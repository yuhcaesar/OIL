all: operate.o protocolUse.o
	g++  -o operate operate.o  protocolUse.o -lpthread  -ljsoncpp   -L/lib/mysql   -lmysqlclient     
operate.o:
	g++ -std=c++11   -I include -c    src/operate.cpp 
protocolUse.o:
	g++ -std=c++11   -I include -c    src/protocolUse.cpp 

clean:
	rm operate *.o 
