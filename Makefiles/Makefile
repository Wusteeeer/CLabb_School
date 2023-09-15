
CC = gcc
CFLAGS = -I.
DEPS = testH.h
OBJ = makeTest.o testC.o

all : generate clean

#$@ is the left side of the :
#$^ is all dependencies on the right side and $< is the first dependency in the dependency list
%.o : %.c ${DEPS}
	${CC} -c -o $@ $< ${CFLAGS}

generate : ${OBJ}
	${CC} -o $@ $^ ${CFLAGS}


.PHONY : clean

clean:
	rm generate

