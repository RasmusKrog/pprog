CFLAGS = -Wall -std=gnu99
CFLAGS += `gsl-config --cflags`
LDLIBS += `gsl-config --libs`
PLOTTER = gnuplot

report.pdf: report.tex plot.pdf
	pdflatex report.tex
	pdflatex report.tex

report.tex: plot.gpi out.txt 
	gnuplot plot.gpi

out.txt:  multiroot
	./multiroot > out.txt

multiroot: multiroot.c Fe.c
	cc $^ -o $@ $(CFLAGS) $(LDLIBS)

.PHONEY: clean
clean: 
	$(RM) multiroot Fe out.txt report.pdf report.log report.aux plot.tex multiroot.o Fe.o

