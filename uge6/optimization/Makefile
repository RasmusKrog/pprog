CFLAGS = -Wall -std=gnu99 
CFLAGS += `gsl-config --cflags`
LDLIBS = -lm 
LDLIBS += `gsl-config --libs`
FORMAT = png
SCRIPT = log
PLOTTER = gnuplot

.PHONEY: all plot.$(FORMAT)

all : out_rosenbrock.txt plot.$(FORMAT)

plot.$(FORMAT) : out_leastsquares.txt Makefile
	echo 'set term $(FORMAT)' > $(SCRIPT)
	echo 'set title "Least-squares fit to data"' >> $(SCRIPT)
	echo 'set output "$@"' >> $(SCRIPT)
	echo 'set key out' >> $(SCRIPT)
	echo 'set grid' >> $(SCRIPT)
	echo 'set xlabel "Time [arb. units]"' >> $(SCRIPT)
	echo 'set ylabel "Activity [arb. units]"' >> $(SCRIPT)
	echo 'plot \' >> $(SCRIPT)
	echo '"$(word 1, $^)" index 0 with errorbars title "Experiment" \' >> $(SCRIPT)
	echo ', "$(word 1, $^)" index 1 with lines title "Model"' >> $(SCRIPT)
	$(PLOTTER) $(SCRIPT)

out_rosenbrock.txt : rosenbrock
	./$^ > $@

out_leastsquares.txt : leastsquares
	./$^ > $@

rosenbrock: rosenbrock.c
	cc $^ -o $@ $(CFLAGS) $(LDLIBS)

leastsquares : leastsquare.c
	cc $^ -o $@ $(CFLAGS) $(LDLIBS)

.PHONEY : clean

clean : 
	find ./ -type f -executable -delete
	$(RM) *.txt $(SCRIPT) *.pdf log*

