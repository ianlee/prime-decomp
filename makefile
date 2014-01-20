CC = g++
CFLAGS = -Wall -g
LDFLAGS = -lm

all: myprogram

prime.o : prime.cpp prime.h
	${CC} ${CFLAGS} -c prime.cpp

process.o : process.cpp process.h prime.h
	${CC} ${CFLAGS} -c process.cpp

thread.o : thread.cpp thread.h prime.h
	${CC} ${CFLAGS} -c thread.cpp

main.o : main.cpp main.h thread.h process.h
	${CC} ${CFLAGS} -c main.cpp

myprogram : main.o thread.o process.o prime.o
	${CC} ${CFLAGS} main.o thread.o process.o prime.o ${LDFLAGS} -o a

clean:
	rm -rf *.o hello
