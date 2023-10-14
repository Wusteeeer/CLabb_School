CC = gcc

INCDIR = ./include
SRCDIR = ./src

OBJ = tree.o line.o vector.o matrix.o

INCLUDE = -IC:\msys64\mingw64\include -I${INCDIR}

CFLAGS = -g ${INCLUDE} -c

LDFLAGS = -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -lm


run : ${OBJ}
	@echo "Creating executable"
	@${CC} -o $@ $^ ${LDFLAGS}

tree.o : ${SRCDIR}/tree.c ${INCDIR}/vector.h ${INCDIR}/matrix.h ${INCDIR}/line.h
	@${CC} ${CFLAGS} $<

line.o : ${SRCDIR}/line.c ${INCDIR}/vector.h ${INCDIR}/line.h
	@${CC} ${CFLAGS} $<

vector.o : ${SRCDIR}/vector.c ${INCDIR}/vector.h ${INCDIR}/matrix.h
	@${CC} ${CFLAGS} $<

matrix.o : ${SRCDIR}/matrix.c ${INCDIR}/vector.h ${INCDIR}/matrix.h
	@${CC} ${CFLAGS} $<



