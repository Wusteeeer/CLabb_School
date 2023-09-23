SRCDIR =./src
INCDIR =./include

CC = gcc


#TODO: It cannot find the asteroid file for some reason (i think)

#If more files are created then add them as objects and C-files here
OBJ = Lab2HardV.o Ship.o asteroid.o labMath.o bullet.o score.o

INCLUDE = -IC:\msys64\mingw64\include -I${INCDIR}

CFLAGS = -g ${INCLUDE} -c

#These are used to make certain SDL libs work - order matters!
LDFLAGS = -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -mwindows -lm

Lab2HV : ${OBJ}

	@echo "Building Lab2"
	@${CC} -o $@ $^ ${LDFLAGS}

# %.o : ${SRCDIR}/%.c ${INCDIR}/%.h
# 	${CC} ${CFLAGS} ${SRCDIR}/%.c

Lab2HardV.o : ${SRCDIR}/Lab2HardV.c ${INCDIR}/Ship.h ${INCDIR}/asteroid.h ${INCDIR}/labMath.h ${INCDIR}/bullet.h ${INCDIR}/score.h
	@${CC} ${CFLAGS} ${SRCDIR}/Lab2HardV.c


Ship.o : ${SRCDIR}/Ship.c ${INCDIR}/Ship.h ${INCDIR}/labMath.h
	@${CC} ${CFLAGS} ${SRCDIR}/Ship.c


asteroid.o : ${SRCDIR}/asteroid.c ${INCDIR}/asteroid.h ${INCDIR}/labMath.h
	@${CC} ${CFLAGS} ${SRCDIR}/asteroid.c

labMath.o : ${SRCDIR}/labMath.c ${INCDIR}/labMath.h
	@${CC} ${CFLAGS} ${SRCDIR}/labMath.c

bullet.o : ${SRCDIR}/bullet.c ${INCDIR}/bullet.h ${INCDIR}/labMath.h
	@${CC} ${CFLAGS} ${SRCDIR}/bullet.c

score.o : ${SRCDIR}/score.c ${INCDIR}/score.h
	@${CC} ${CFLAGS} ${SRCDIR}/score.c

.PHONY : clean

clean:
	rm*.o
	rm*.exe