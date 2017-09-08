OBJS = mainex1.o
CFLAGS = -Wall -c -g
LFLAGS = -Wall -g
CC = g++
INCLUDE =
LIBS = -lm

mainex1:    ${OBJS}
	${CC} ${LFLAGS} ${INCLUDES} ${OBJS} -o mainex1
mainex1.o:  mainex1.cpp Arrange.h QuickSort.h BubbleSort.h
	${CC} ${CFLAGS} mainex1.cpp
clean:
	-rm *.o mainex1
