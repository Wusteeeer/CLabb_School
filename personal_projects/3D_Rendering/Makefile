INCDIR = ./include
SRCDIR = ./src

OBJ = mainC.o matrix.o vector.o objects.o
INCLUDE = matrix.h vector.h objects.h
CC = gcc

INCLUDE = -IC:\msys64\mingw64\include -I${INCDIR}

CFLAGS = -g ${INCLUDE} -c

LDFLAGS = -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -lm

run : ${OBJ}
	@echo "Creating executable"
	@${CC} -o $@ $^ ${LDFLAGS}


mainC.o :  ${SRCDIR}/mainC.c ${INCDIR}/matrix.h ${INCDIR}/vector.h ${INCDIR}/objects.h
	@${CC} ${CFLAGS} $<

vector.o :  ${SRCDIR}/vector.c ${INCDIR}/vector.h
	@${CC} ${CFLAGS} $<

matrix.o :  ${SRCDIR}/matrix.c ${INCDIR}/vector.h ${INCDIR}/matrix.h 
	@${CC} ${CFLAGS} $<

objects.o : ${SRCDIR}/objects.c ${INCDIR}/vector.h ${INCDIR}/matrix.h  ${INCDIR}/objects.h
	@${CC} ${CFLAGS} $<
