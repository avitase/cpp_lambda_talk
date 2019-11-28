.PHONY: all clean snippets

PDF = icsc2020_nmeinert.pdf

all: $(PDF)

$(PDF): slides/build/main.pdf
	cp $< $@

slides/build/main.pdf: $(shell find slides -name '*.tex') $(shell find img -name '*.png') slides/beamerthemevertex.sty
	cd slides && mkdir -p build && \
	latexmk -halt-on-error -pdflatex=lualatex -pdf -jobname=build/main main.tex

snippets:
	make -f Makefile.snippets

clean:
	make clean -f Makefile.snippets
	rm -f slides/build/*
