

.PHONY : all clean

LINKERFLAG = -lm

CC := gcc
SRCS := makeTest.c testC.c testH.h.gch
BINS := $(SRCS:%.c=%)


all : ${BINS}

%: %.o
	@echo "Checking..."
	${CC} ${LINKERFLAG} $< -o $@


%.o:%.c
	@echo "Creating Object..."
	${CC} -c $<


clean:
	@echo "Cleaning up.."
	rm -rvf *.o ${BINS}
