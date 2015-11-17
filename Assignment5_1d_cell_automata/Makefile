#
# CS 11: Makefile for C track, assignment 5.
#

CC     = gcc
CFLAGS = -g -Wall -Wstrict-prototypes -ansi -pedantic

1d_cell_auto: 1d_cell_auto.o memcheck.o
	$(CC) 1d_cell_auto.o memcheck.o -o 1d_cell_auto

memcheck.o: memcheck.c memcheck.h
	$(CC) $(CFLAGS) -c memcheck.c

1d_cell_auto.o: 1d_cell_auto.c memcheck.h
	$(CC) $(CFLAGS) -c 1d_cell_auto.c

test:
	./1d_cell_auto 10 10

check:
	./c_style_check 1d_cell_auto.c

clean:
	rm -f *.o 1d_cell_auto memcheck
