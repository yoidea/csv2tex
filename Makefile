CC := gcc

csv2tex: csv2tex.c
	gcc -o csv2tex csv2tex.c

clean:
	$(RM) csv2tex