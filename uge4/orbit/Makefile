CFLAGS = -Wall -std=gnu99 
LDLIBS = -lm 
CFLAGS += `gsl-config --cflags`
LDLIBS += `gsl-config --libs`
FORMAT = png
SCRIPT = log
PLOTTER = gnuplot

.PHONEY: all clean 

all : out_ydiff.txt plot.$(FORMAT)

plot.$(FORMAT) : out_orbit.txt Makefile
	echo 'set term $(FORMAT)' >> $(SCRIPT)
	echo 'set title "Orbital motion"' >> $(SCRIPT)
	echo 'set output "$@"' >> $(SCRIPT)
	echo 'set key out' >> $(SCRIPT)
	echo 'set size ratio -1' >> $(SCRIPT)
	echo 'set grid' >> $(SCRIPT)
	echo 'set xlabel "x"' >> $(SCRIPT)
	echo 'set ylabel "y"' >> $(SCRIPT)
	echo 'plot \' >> $(SCRIPT)
	echo ' "$(word 1, $^)" using (1/$$2) * sin($$1):(1/$$2) * cos($$1) with lines notitle' >> $(SCRIPT)
	$(PLOTTER) $(SCRIPT)

out_ydiff.txt : ydiff 
	./$< >$@

out_orbit.txt : orbit
	./$< > $@

orbit : main_orbit.c
	cc $^ -o $@ $(CFLAGS) $(LDLIBS)

ydiff : main_ydiff.c
	cc $^ -o $@ $(CFLAGS) $(LDLIBS)
clean : 
	find ./ -type f -executable -delete
	$(RM) *.dat $(SCRIPT) *.svg *.png *.pdf log*
