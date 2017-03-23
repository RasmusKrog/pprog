CFLAGS = -Wall -std=gnu99 
CFLAGS += `gsl-config --cflags`
LDLIBS = -lm 
LDLIBS += `gsl-config --libs`
FORMAT = png
SCRIPT = log
PLOTTER = gnuplot

.PHONEY : all

all : plot.$(FORMAT)

plot.$(FORMAT) : out_error.txt Makefile
	echo 'set term $(FORMAT)' > $(SCRIPT)
	echo 'set title "RASMUS KROG - TEST"' >> $(SCRIPT)
	echo 'set output "$@"' >> $(SCRIPT)
	echo 'set key out' >> $(SCRIPT)
	echo 'set size ratio -1' >> $(SCRIPT)
	echo 'set grid' >> $(SCRIPT)
	echo 'set xlabel "x"' >> $(SCRIPT)
	echo 'set ylabel "y"' >> $(SCRIPT)
	echo 'plot \' >> $(SCRIPT)
	echo '"$(word 1, $^)" using "x":"errfunc" with lines notitle \' >> $(SCRIPT)
	$(PLOTTER) $(SCRIPT)

out_error.txt : error
		./error -3.0 3.0 0.2  > $@
#		./main -3.0 3.0 0.2 > $@

error : errfunc.c main.c
		cc $^ -o $@ $(CFLAGS) $(LDLIBS)

#main : main.c
#	cc $^ -o $@ $(CFLAGS) $(LDLIBS)

.PHONEY : clean
clean :
	find ./ -type f -executable -delete
	$(RM) *.dat $(SCRIPT) *.svg *.png *.pdf log*
