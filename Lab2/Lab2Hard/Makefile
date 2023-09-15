#If more files are created then add them as objects and C-files here
OBJ = Lab2HardV.o Lab2Lib.o
FILES = Lab2HardV.c Lab2Lib.c

#Add dependencies here (custom made header files)
DEPS = Lab2Lib.h

SRCDIR =.

CC = gcc

INCLUDE = C:\msys64\mingw64\include
CFLAGS = -g -I${INCLUDE} -c

#These are used to make certain SDL libs work (I think)
LDFLAGS = -lmingw32 -lSDL2main -lSDL2 -mwindows -lm

Lab2HV : ${OBJ}

	@echo "Building Lab2"

	${CC} ${CFLAGS} ${SRCDIR}/${FILES}
	
	${CC} $^ -o $@ ${LDFLAGS}


#Updates all object files (and therefore also recompiles the C-files) if needed
%.o : %.c ${DEPS}
	${CC} -c -o $@ $< ${CFLAGS}


.PHONY : clean

clean:
	rm*.o
	rm*.exe