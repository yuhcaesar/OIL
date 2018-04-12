all: operate.o
	g++  -o client operate.o  -lpthread     -L/lib/mysql   -lmysqlclient       -L./deps/hiredis/ -lhiredis 
operate.o:
	g++ -std=c++11   -I include -c -I./deps/hiredis/  src/operate.cpp 

clean:
	rm operate *.o log/*.log.* log/*.log
