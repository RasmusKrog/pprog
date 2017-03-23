CFLAGS = -Wall  -std=gnu99 `gsl-config --cflags`
LDLIBS = `gsl-config --libs`

all : data.txt plot.pdf report.pdf 

report.pdf: report.tex plot.pdf
	pdflatex $<
	pdflatex $<


plot.pdf: plot.gpi data.txt
	gnuplot plot.gpi

data.txt: main
	./main 0.1 10 0.2 > data.txt

main : main.o


plot.gpi: Makefile
	echo 'set term png' > $@
	echo 'set out "plot.pdf"' >> $@
	echo 'set xlabel "x [arb. units]"' >> $@ #from data.txt
	echo 'set ylabel "t [arb. units]"' >> $@ #from data.txt
	echo 'set key right bottom' >> $@
	echo 'plot \' >> $@
	echo ' "data.txt" using 1:3 with lines title "Exact log",\' >> $@
	echo ' "data.txt" using 1:2 with points title "Calculated log"' >> $@

.PHONEY: clean #when typing make clean, rm will be executed
clean:
	$(RM) main *.o data* *.pdf *.log *.aux plot*
