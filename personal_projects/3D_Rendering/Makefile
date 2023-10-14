INCDIR = ./include
SRCDIR = ./src
ROOTDIR = ..

OBJ = mainC.o matrix.o vector.o objects.o
INCLUDE = matrix.h vector.h objects.h
CC = gcc

INCLUDE = -IC:\msys64\mingw64\include -I${INCDIR}

CFLAGS = -g ${INCLUDE} -c

LDFLAGS = -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -lm

run : ${OBJ}
	@echo "Creating executable"
	@${CC} -o $@ $^ ${LDFLAGS}


mainC.o :  ${SRCDIR}/mainC.c ${ROOTDIR}/matrix.h ${ROOTDIR}/vector.h ${INCDIR}/objects.h
	@${CC} ${CFLAGS} $<

vector.o :  ${ROOTDIR}/vector.c ${ROOTDIR}/vector.h
	@${CC} ${CFLAGS} $<

matrix.o :  ${ROOTDIR}/matrix.c ${ROOTDIR}/vector.h ${ROOTDIR}/matrix.h 
	@${CC} ${CFLAGS} $<

objects.o : ${SRCDIR}/objects.c ${ROOTDIR}/vector.h ${ROOTDIR}/matrix.h  ${INCDIR}/objects.h
	@${CC} ${CFLAGS} $<
