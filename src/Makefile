#
# AUTHORS: Martin Minarik, Gabriel Quirschfeld, Tomas Svetlik, Jakub Zich
# DATE: 22.4.2017
#
# USAGE:
# -translating
#	make
# -testing
#	make test
# -packaging
#	make pack
# -documentation
#	make doc
# -running
#	make run
# -cleaning
#	make clean

# output name
TARGET=calc

# compiler
CC=gcc
# debug
DEBUG=-g
# optimisation
OPT=-O0
# warnings
WARN=-Wall

.PHONY: run clean doc test

PTHREAD=-pthread

CCFLAGS=$(DEBUG) $(OPT) $(WARN) $(PTHREAD) -pipe

CFLAGS=-std=c99 -Wall -Werror

GTKLIB=`pkg-config --cflags --libs gtk+-3.0`

# linker
LD=gcc
LDFLAGS=$(PTHREAD) $(GTKLIB) -export-dynamic

OBJS=    main.o

all: $(OBJS)
	$(LD) main_calc/calculator.c main_calc/callbacks.c -o $(TARGET) $(OBJS) $(LDFLAGS)

main.o: main_calc/main.c
	$(CC) -c $(CCFLAGS) main_calc/main.c $(GTKLIB) -o main.o

clean:
	rm -f *.o $(TARGET)

run: calc
	./calc

doc: main_calc/calculator.h
	cd main_calc && doxygen Doxyfile && \

test_calculator: test_calculator
	$(CC)  $(CFLAGS) -o test_calculator main_calc/test_calculator.c main_calc/calculator.c

test: test_calculator
	./test_calculator
