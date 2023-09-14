#TODO: Figure out how this works!

# Makefile for Windows

# Location of where shipSDL.c is stored in
SRCDIR=.

# Name of the compiler, GNU GCC in this case
CC=gcc

# Any include directories
INCLUDE = C:\msys64\mingw64\include

# Any flags for the compiler
#CFLAGS = -g -I$(INCLUDE) -c
CFLAGS = -g -c

# Any libraries to link with
#LIBS = C:\msys64\mingw64\lib

# Extra flags to give to compilers when they are supposed to invoke the linker
# NOTE ORDER OF THE FLAGS MATTERS!
LDFLAGS = -lmingw32 -lSDL2main -lSDL2 -mwindows -m

shipSDL:
	@echo "Building shipSDL"
	$(CC) $(CFLAGS) $(SRCDIR)/shipSDL.c
	$(CC) shipSDL.o -o shipSDL $(LDFLAGS)

clean:
	rm shipSDL
	rm shipSDL.o