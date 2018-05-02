using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using MySql.Data.MySqlClient;
using System.Data;
using System.Net.Sockets;  
using System.Net;  
using System.Threading;

namespace serverPlatform
{
    /// <summary>
    /// MainWindow.xaml 的交互逻辑
    /// </summary>
    public partial class MainWindow : Window
    {


        public MainWindow()
        {
            InitializeComponent();
        }

        private static byte[] result = new byte[1024];
        static Socket serverSocket;
        static Thread myThread;
        static Socket clientSocketInServer;
        static Thread receiveThread;
        static Socket myClientSocket;
        static Socket clientSocket;

        private static bool play = true;
        public static bool isOpened = false;
        string TextIP;
        string Textport;

        //------------------------------------------------下面这些是真正用到的，毕竟只是客户端----------------------------------------------------------------------//

        public void clientMain(string message = "")
        {
            TextIP = IPText.Text;
            Textport = portText.Text;
            Thread th = new Thread(theClient);
            th.Start();
        }

        void theClient()
        {
            if (isOpened)
                return;

            //设定服务器IP地址  
            IPAddress ip = IPAddress.Parse(TextIP);
            if (clientSocket == null)
            {
                clientSocket = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
                try
                {
                    clientSocket.Connect(new IPEndPoint(ip, Convert.ToInt32(Textport))); //配置服务器IP与端口  
                    isOpened = true;
                    Console.WriteLine ("连接服务器成功");  
                }
                catch(Exception D)
                {
                    Console.WriteLine("连接服务器失败 ");
                    Console.WriteLine(D.Message);
                    isOpened = false;
                    return;
                }

                //通过clientSocket接收数据  
                //int receiveLength = clientSocket.Receive(result);  
                //systemValues.stepCountShow = Encoding.UTF8.GetString (result, 0, receiveLength);
                //print("接收服务器消息\n"+Encoding.UTF8.GetString(result,0,receiveLength)+"\ntype: client");  
                //通过 clientSocket 发送数据  
            }
        }

        public void send(string message = "")
        {
            if (clientSocket != null && isOpened)
            {
                string sendMessage = message;
                clientSocket.Send(Encoding.UTF8.GetBytes(sendMessage));
                //print ("向服务器发送消息\n" + sendMessage);  
                //通过clientSocket接收数据  
                try
                {
                    int receiveLength = clientSocket.Receive(result);
                    string reveiveString = Encoding.UTF8.GetString(result, 0, receiveLength);
                    //从服务器获得的信息简单处理
                    Console.WriteLine("receive = " + reveiveString);
                }
                catch (Exception C)
                {
                    return;
                }
            }
        }



        private void button_Click(object sender, RoutedEventArgs e)
        {
            clientMain();
        }

        private void button1_Click(object sender, RoutedEventArgs e)
        {
            send(information.Text);
        }
    }

}
