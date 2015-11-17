#
# CS 11: Makefile for C track, assignment 5.
#

CC     = gcc
CFLAGS = -g -Wall -Wstrict-prototypes -ansi -pedantic

all: 1d_cell_auto 1d_cell_auto_pointer

1d_cell_auto: 1d_cell_auto.o memcheck.o
	$(CC) 1d_cell_auto.o memcheck.o -o 1d_cell_auto

1d_cell_auto_pointer: 1d_cell_auto_pointer.o memcheck.o
	$(CC) 1d_cell_auto_pointer.o memcheck.o -o 1d_cell_auto_pointer

memcheck.o: memcheck.c memcheck.h
	$(CC) $(CFLAGS) -c memcheck.c

1d_cell_auto_pointer.o: 1d_cell_auto_pointer.c memcheck.h
	$(CC) $(CFLAGS) -c 1d_cell_auto_pointer.c

1d_cell_auto.o: 1d_cell_auto.c memcheck.h
	$(CC) $(CFLAGS) -c 1d_cell_auto.c

test:
	./1d_cell_auto 50 50
	./1d_cell_auto_pointer 50 50

check:
	./c_style_check 1d_cell_auto.c 1d_cell_auto_pointer.c

clean:
	rm -f *.o 1d_cell_auto memcheck 1d_cell_auto_pointer
