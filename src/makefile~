Objects = main.o config.o smart_coder.o
CC = g++
TARGET = smart_coder 
#LIBPATH = ./lib
CFLAGS = -g
#INCLUDE = -I$(LIBPATH)/jsoncpp_4.0.0.0/include/
#LIB = -lpthread -L$(LIBPATH)/jsoncpp_4.0.0.0/lib -ljsoncpp

all: clean ${TARGET} cleanobj

${TARGET}: ${Objects}
	g++ ${CFLAGS} -o ${TARGET} ${Objects}

%.o: %.cpp
	g++ ${CFLAGS} -c $< -o $@

%.o: %.cc
	g++ ${CFLAGS} -c $< -o $@

clean:
	rm -rf ${Objects} ${TARGET}

cleanobj:
	rm -rf ${Objects}
