CFLAGS = -Wall -std=gnu99
.PHONEY: default clean

default: out.txt
		cat $<

out.txt: main
		./$< > $@

clean:
		$(RM) main #out.txt
