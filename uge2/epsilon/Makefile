CFLAGS = -Wall -std=gnu99 
LDLIBS = -lm

default: out.txt
	cat out.txt

out.txt: epsilon sum
	./epsilon > out.txt
	./sum >> out.txt

sum epsilon check: sum.o epsilon.o
	$(CC) $< -o $@

#check: check.o
#	$(CC) check.o -o check

epsilon.o: epsilon.c
	$(CC) -c $(CFLAGS) epsilon.c check.c

check.o: check.c
	cc -c $(CFLAGS) check.c

sum.o: sum.c
	cc -c $(CFLAGS) sum.c  

clean:
	$(RM) epsilon out.txt epsilon.o check check.o sum sum.o

test:
	@echo	"cc:" $(CC)
	@echo "cflags" $(CFLAGS)
	@echo "ldlibs:	"$(LDLIBS)
