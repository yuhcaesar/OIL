all: operate.o protocolUse.o param.o
	g++  -o operate operate.o  protocolUse.o param.o -lpthread  -ljsoncpp   -L/lib/mysql   -lmysqlclient     
operate.o:
	g++ -std=c++11   -I include -c    src/operate.cpp 
protocolUse.o:
	g++ -std=c++11   -I include -c    src/protocolUse.cpp 
param.o:
	g++ -std=c++11   -I include -c    src/param.cpp
clean:
	rm operate *.o 
