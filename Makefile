.PHONY: all clean snippets

PDF_SLIDES = slides.pdf
PDF_EXERCISE = exercise.pdf

all: $(PDF_SLIDES) $(PDF_EXERCISE)

$(PDF_SLIDES): slides/build/main.pdf 
	cp $< $@

$(PDF_EXERCISE): exercise/build/main.pdf 
	cp $< $@

slides/build/main.pdf: $(shell find slides -name '*.tex') slides/beamerthemevertex.sty
	cd slides && mkdir -p build && \
	latexmk -halt-on-error -pdflatex=lualatex -pdf -jobname=build/main main.tex

exercise/build/main.pdf: $(shell find exercise -name '*.tex')
	cd exercise && mkdir -p build && \
	latexmk -halt-on-error -pdflatex=lualatex -pdf -jobname=build/main main.tex

snippets:
	make -f Makefile.snippets

clean:
	make clean -f Makefile.snippets
	rm -f slides/build/*
	rm -f exercise/build/*
