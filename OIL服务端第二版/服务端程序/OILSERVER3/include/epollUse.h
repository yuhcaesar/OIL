#ifndef __epollUse_H__   
#define __epollUse_H__   
#include  <stdio.h>   
#include  <iostream>   
#include  <unistd.h>   
#include  <fcntl.h>   
#include  <errno.h>  
#include  <sys/types.h>  
#include  <sys/socket.h>   
#include  <sys/epoll.h>   
#include  <netinet/in.h>   
#include  <arpa/inet.h>   

#include <string.h>
#include "protocolUse.h"

using namespace std;  
  
class epollUse
{  
    public:  
        epollUse();  
        virtual ~epollUse();  
        bool init(int port, int sock_count , protocolUse thePin);   
        int epoll_server_wait(int time_out);  
        int accept_new_client();  
        int recv_data(int sock, char* recv_buf);  
        int send_data(int sock, char* send_buf, int buf_len);  
        void run(int time_out); 
  
    private:  
        int m_listen_sock;  
        int m_epoll_fd;  
        int m_max_count;  
        struct epoll_event *m_epoll_events; 
        protocolUse theProtocolController; 
};  
  
epollUse::epollUse()  
{  
    m_listen_sock = 0;  
    m_epoll_fd = 0;  
    m_max_count = 0;  
    m_epoll_events = NULL;  
}  
  
epollUse::~epollUse()  
{  
    if (m_listen_sock > 0)  
    {  
        close(m_listen_sock);  
    }  
  
    if (m_epoll_fd > 0)  
    {  
        close(m_epoll_fd);  
    }  
}  
  
bool epollUse::init(int port , int sock_count , protocolUse thePin)  
{  
    theProtocolController = thePin;
    m_max_count = sock_count;     
    struct sockaddr_in server_addr;  
    memset(&server_addr, 0, sizeof(&server_addr));  
    server_addr.sin_family = AF_INET;  
    server_addr.sin_port = htons(port);  
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);          
  
    m_listen_sock = socket(AF_INET, SOCK_STREAM, 0);  
    if(m_listen_sock == -1)  
    {  
        //exit(1);     
        return false;
    }  
      
    if(bind(m_listen_sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1)  
    {  
        //exit(1);     
        return false; 
    }  
      
    if(listen(m_listen_sock, 5) == -1)  
    {  
        //exit(1);     
        return false; 
    }  
  
    m_epoll_events = new struct epoll_event[sock_count];  
    if (m_epoll_events == NULL)  
    {  
        //exit(1);     
        return false;  
    }  
  
    m_epoll_fd = epoll_create(sock_count);  
    struct epoll_event ev;  
    ev.data.fd = m_listen_sock;  
    ev.events  = EPOLLIN | EPOLLOUT;  
    epoll_ctl(m_epoll_fd, EPOLL_CTL_ADD, m_listen_sock, &ev); 
    cout<<"epoll server inited"<<endl;   
}  

  
int epollUse::accept_new_client()  
{  
    sockaddr_in client_addr;  
    memset(&client_addr, 0, sizeof(client_addr));  
    socklen_t clilen = sizeof(struct sockaddr);   
    int new_sock = accept(m_listen_sock, (struct sockaddr*)&client_addr, &clilen);  
    struct epoll_event ev;  
    ev.data.fd = new_sock;  
    ev.events  = EPOLLIN;  
    epoll_ctl(m_epoll_fd, EPOLL_CTL_ADD, new_sock, &ev);  
    return new_sock;  
}  
  
int epollUse::recv_data(int sock, char* recv_buf)  
{  
    char buf[1024] = {0};  
    int len = 0;  
    int ret = 0;  
    while(ret >= 0)  
    {  
        ret = recv(sock, buf, sizeof(buf), 0);  
        if(ret <= 0)  
        {  
            struct epoll_event ev;  
            ev.data.fd = sock;  
            ev.events  = EPOLLERR;  
            epoll_ctl(m_epoll_fd, EPOLL_CTL_DEL, sock, &ev);  
            close(sock);  
            break;  
        }  
        else if(ret < 1024)  
        {  
            memcpy(recv_buf, buf, ret);  
            len += ret;   
            struct epoll_event ev;  
            ev.data.fd = sock;  
            ev.events  = EPOLLOUT;  
            epoll_ctl(m_epoll_fd, EPOLL_CTL_MOD, sock, &ev);  
            break;  
        }  
        else  
        {  
            memcpy(recv_buf, buf, sizeof(buf));  
            len += ret;  
        }  
    }  
  
    return ret <= 0 ? ret : len;  
}  
  
int epollUse::send_data(int sock, char* send_buf, int buf_len)  
{  

    int ret = send(sock, send_buf , buf_len, MSG_NOSIGNAL);  

    if(ret > 0)  
    {  
        struct epoll_event ev;  
        ev.data.fd = sock;  
        ev.events  = EPOLLIN;  
        epoll_ctl(m_epoll_fd, EPOLL_CTL_MOD, sock, &ev);  
    }  
  
    return ret ;  
}  
  
int epollUse::epoll_server_wait(int time_out)  
{  
    int nfds = epoll_wait(m_epoll_fd, m_epoll_events, m_max_count, time_out);  
}  
  
void epollUse::run(int time_out)  
{  
    cout<<"epoll server start running"<<endl;  
    cout<<"--------------------------------"<<endl;
    char *recv_buf = new char[65535];  
    char *send_buf = new char[65535];  
    while(1)  
    {  
        int ret = epoll_server_wait(time_out);  
        if(ret == 0)  
        {  
            //cout<<"time out"<<endl;  
            continue;  
        }  
        else if(ret == -1)  
        {  
            cout<<"error"<<endl;  
        }  
        else  
        {  
            for(int i = 0; i < ret; i++)  
            {  
                if(m_epoll_events[i].data.fd == m_listen_sock)  
                {  
                    if(m_epoll_events[i].events & EPOLLIN)  
                    {  
                        int new_sock = accept_new_client();  
                    }  
                }  
                else  
                {  
                    if(m_epoll_events[i].events & EPOLLIN)  
                    {  
                        int recv_count = recv_data(m_epoll_events[i].data.fd, recv_buf);  
                        cout<<"receive: "<<recv_buf<<endl;  

                        string receiveString(recv_buf);
                        theProtocolController.getString(receiveString);
                        memset(recv_buf, 0, sizeof(recv_buf)); 
                    }  
                    else if(m_epoll_events[i].events & EPOLLOUT)  
                    {  
                        string sendString = "information";
                        strcpy(send_buf ,sendString.c_str() );
                        cout<<"send: "<<sendString<<endl; 

                        int send_count = send_data(m_epoll_events[i].data.fd, send_buf,strlen(sendString.c_str()) );  

                        memset(send_buf, 0, sizeof(send_buf));  

                    }
                    else
		    {
                       cout<<"error!"<<endl;
		    }  
                      
                }  
            }  
        }  
    }  
}  


#endif     
