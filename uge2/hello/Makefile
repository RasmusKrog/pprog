CFLAGS = -std=gnu99 -Wall
.PHONEY: default clean

default: out.txt
	cat out.txt

out.txt: hello
	./hello > out.txt

hello: hello.c
	cc $(CFLAGS) hello.c -o hello

clean:
	$(RM) hello #out.txt
