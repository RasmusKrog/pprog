CFLAGS = -Wall -std=gnu99
LDFLAGS = -lm
.PHONEY: default clean

default : out.txt
	cat out.txt

out.txt : sum
	./sum > out.txt

#sum : sum.o
#	cc sum.o -o sum

#sum.o : sum.c
#	cc -c sum.c

clean :
	rm --force sum.o sum out.txt

