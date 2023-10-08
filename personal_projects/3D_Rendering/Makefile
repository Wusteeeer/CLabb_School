INCDIR = ./include
SRCDIR = ./src

OBJ = cube.o matrix.o vector.o
INCLUDE = matrix.h vector.h
CC = gcc

INCLUDE = -IC:\msys64\mingw64\include -I${INCDIR}

CFLAGS = -g ${INCLUDE} -c

LDFLAGS = -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -lm

run : ${OBJ}
	@echo "Creating executable"
	@${CC} -o $@ $^ ${LDFLAGS}


cube.o :  ${SRCDIR}/cube.c ${INCDIR}/matrix.h ${INCDIR}/vector.h
	@${CC} ${CFLAGS} $<

vector.o :  ${SRCDIR}/vector.c ${INCDIR}/vector.h
	@${CC} ${CFLAGS} $<

matrix.o :  ${SRCDIR}/matrix.c ${INCDIR}/vector.h ${INCDIR}/matrix.h 
	@${CC} ${CFLAGS} $<

