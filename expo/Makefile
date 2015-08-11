NAME=expo
NAME_READ=read

all : diap c_read

diap : $(NAME).tex
	pdflatex $(NAME).tex -halt-on-error

c_read : $(NAME_READ).tex
	latex $(NAME_READ).tex
	dvips $(NAME_READ).dvi

clean :
	rm -vf `ls --ignore=Makefile --ignore=*.tex --ignore=rc`

view : diap
	zathura $(NAME).pdf > /dev/null 2>&1 &

read : c_read
	xdvi $(NAME_READ).dvi > /dev/null 2>&1 &

view_all : all view read
