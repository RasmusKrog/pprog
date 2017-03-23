CFLAGS = -std=gnu99 -Wall # options for the C-compiler $(CC)
LDLIBS = -lm              # libraries for the linker
.PHONEY: default clean test

default: out.txt        # the first target is made by default
		cat out.txt     # show out.txt in terminal

out.txt: main              # out.txt depends on main
		./main > out.txt   # run main and send output to out.txt

main: main.o               # main depends on main.o
		$(CC) $(CFLAGS) $(LDFLAGS) $< $(LDLIBS) -o $@    # linking

main.o: main.c             # main.o depends on main.c
		$(CC) $(CFLAGS) -c $<              # compilation

clean:
		$(RM) main main.o #out.txt      # clean up

test:
		@echo "cc:    " $(CC)
		@echo "cflags:" $(CFLAGS)
		@echo "ldlibs:" $(LDLIBS)
		@echo $(RM)
