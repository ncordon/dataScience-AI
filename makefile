all: desarrollo.pdf presentacion.pdf nonstop_pre.pdf

desarrollo.pdf: desarrollo.md
	pandoc $< -o $@

presentacion.pdf: presentacion.tex
	pdflatex $<

nonstop_pre.tex: presentacion.tex
	./rmpauses.sh

nonstop_pre.pdf: nonstop_pre.tex
	pdflatex $<
