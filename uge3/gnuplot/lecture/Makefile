CFLAGS = -Wall -Werror -std=gnu99
LDLIBS = -lm

all: article.pdf plot.pdf

article.pdf: article.tex plot.tex
	pdflatex $<
	pdflatex $<

plot.pdf plot.tex: plot.gpi data
	gnuplot plot.gpi

data: main
	./main 1> data 2> log

.PHONEY: clean
clean:
	find . -type f -executable -delete
	$(RM) data log *.aux *.log *.pdf plot.tex
