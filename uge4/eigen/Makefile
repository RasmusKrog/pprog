CFLAGS = -Wall -std=gnu99 #Wall: Gives all warnings
LDLIBS = -lm  #link to math
CFLAGS += `gsl-config --cflags` #Backticks: Everything we type in `` is executed by the shell before the main command
LDLIBS += `gsl-config --libs`
SOURCES = main.c 
OBJECTS = $(SOURCES: .c=.o)  #from .c to .o file
EXECUTEABLE = eigen
SCRIPT = log.gpi
FORMAT = png
PLOTTER = gnuplot

.PHONEY: all clean #Making sure that default is not a file. It has to be an action

all : plot.$(FORMAT)

plot.$(FORMAT) : data Makefile
	echo 'set term $(FORMAT)' > $(SCRIPT) #> : slet hvad der står, og skriv. 
	echo 'set title "Eigen-functions"' >> $(SCRIPT) #append
	echo 'set output "$@"' >> $(SCRIPT)
	echo 'set key out' >> $(SCRIPT)
	echo 'set xlabel "x"' >> $(SCRIPT)
	echo 'set ylabel "u(x)"' >> $(SCRIPT)
	echo 'plot \' >> $(SCRIPT)
	echo ' "$(word 1,$^)" using "x":"u0" with lines title "u_0" \' >> $(SCRIPT)
	echo ',"$(word 1,$^)" using "x":"u1" with lines title "u_1" \' >> $(SCRIPT)
	echo ',"$(word 1,$^)" using "x":"u2" with lines title "u_2"' >> $(SCRIPT)
	$(PLOTTER) $(SCRIPT)

data : $(EXECUTEABLE)
	./$< >$(word 1, $@)  # send standard output into 'data'

$(EXECUTEABLE): $(OBJECTS)
	cc $(OBJECTS) -o $@ $(CFLAGS) $(LDLIBS)

# clean removes all temporary files, only the original files remain.				
clean : 
	find ./ -type f -executable -delete
	$(RM) *.dat $(SCRIPT) *.svg *.png *.pdf log*
