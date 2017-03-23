CFLAGS = -Wall -std=c99
LDLIBS = -lm
CC = clang
CC = gcc
.PHONEY: all clean indent test

all: out.txt
		cat out.txt

out.txt: main
		./main > out.txt

main: main.o nvector.o

main.o nvector.o: nvector.h

clean:
		$(RM) out.txt main *.o *~

indent:
		indent --linux-style *.c; rm -f *.c~
