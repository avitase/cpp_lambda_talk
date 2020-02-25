.PHONY: all clean snippets slides/build/main.pdf

PDF_SLIDES = slides.pdf
PDF_EXERCISE = exercise.pdf

all: $(PDF_SLIDES) $(PDF_EXERCISE)

$(PDF_SLIDES): slides/build/main.pdf 
	cp $< $@

$(PDF_EXERCISE): exercise/build/main.pdf 
	cp $< $@

slides/build/main.pdf: 
	./make_print_version.py slides/part1.tex && \
	./make_print_version.py slides/part2.tex && \
	cd slides && mkdir -p build && \
	lualatex -halt-on-error -jobname=build/main main.tex

exercise/build/main.pdf: $(shell find exercise -name '*.tex')
	cd exercise && mkdir -p build && \
	lualatex -halt-on-error -jobname=build/main main.tex

snippets:
	make -f Makefile.snippets

clean:
	make clean -f Makefile.snippets
	rm -f slides/build/*
	rm -f exercise/build/*
