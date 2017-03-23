CFLAGS = -Wall -std=gnu99 
CFLAGS += `gsl-config --cflags`
LDLIBS = -lm 
LDLIBS += `gsl-config --libs`
FORMAT = png
SCRIPT = log
PLOTTER = gnuplot

.PHONEY: all plot.$(FORMAT)

all : output_sqrtln.txt plot.$(FORMAT)

plot.$(FORMAT) : output_integ.txt Makefile
	echo 'set term $(FORMAT)' > $(SCRIPT)
	echo 'set title "Energies from the variational method"' >> $(SCRIPT)
	echo 'set output "$@"' >> $(SCRIPT)
	echo 'set key out' >> $(SCRIPT)
	echo 'set grid' >> $(SCRIPT)
	echo 'set xlabel "Alpha [arb. units]"' >> $(SCRIPT)
	echo 'set ylabel "Energy [arb. units]"' >> $(SCRIPT)
	echo 'plot \' >> $(SCRIPT)
	echo '"$(word 1, $^)" using "a":"E(a)" with lines notitle \' >> $(SCRIPT)	
	$(PLOTTER) $(SCRIPT)

output_sqrtln.txt : sqrtln
		./$^ > $@

output_integ.txt : integ
		./$^ > $@

sqrtln : sqrtln.c
		cc $^ -o $@ $(CFLAGS) $(LDLIBS)

integ : integ.c
		cc $^ -o $@ $(CFLAGS) $(LDLIBS)

.PHONEY : clean
clean : 
		find ./ -type f -executable -delete
			$(RM) *.txt $(SCRIPT) *.pdf log*
