all: operate.o
	g++  -o operate operate.o  -lpthread     -L/lib/mysql   -lmysqlclient     
operate.o:
	g++ -std=c++11   -I include -c    src/operate.cpp 

clean:
	rm operate *.o log/*.log.* log/*.log
