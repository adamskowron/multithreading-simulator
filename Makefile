#Makefile
all:
	g++ -std=c++11 terminal.cpp randgen.h sawmill.cpp lumberjack.cpp part.cpp worker.cpp truck.cpp factory.cpp map.cpp wiz.cpp manager.cpp main.cpp -o test -pthread -lncurses -g
#line.cpp
