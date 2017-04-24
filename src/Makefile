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

TARGET=calc

TEST=test_calculator

ZIP=xlogin01_xlogin02_xlogin03_xlogin04.zip

CC=gcc

DEBUG=-g

OPT=-O0

WARN=-Wall -Werror

PTHREAD=-pthread

CCFLAGS=$(DEBUG) $(OPT) $(WARN) $(PTHREAD) -pipe

CFLAGS=-std=c99 $(WARN)

GTKLIB=`pkg-config --cflags --libs gtk+-3.0`

LDFLAGS=$(PTHREAD) $(GTKLIB) -export-dynamic

OBJS=main.o

.PHONY: run clean doc test pack

all : $(OBJS)
	$(CC) */calculator.c */callbacks.c -o $(TARGET) $(OBJS) $(LDFLAGS) -lm

main.o : */main.c
	$(CC) -c $(CCFLAGS) */main.c $(GTKLIB) -o $@

clean :
	rm -f *.o *.tex *.sty $(TARGET) $(TEST)
	rm -rf */html

run : $(TARGET)
	./$(TARGET)

doc: */calculator.h */callbacks.h
	cd main_calc && doxygen Doxyfile

test_calculator : test_calculator
	$(CC)  $(CFLAGS) -o $@ */test_calculator.c */calculator.c

test : $(TEST)
	./$(TEST)

pack :
	cd .. && cd .. && zip -r xminar31_xquirs00_xsvetl05_xzichj00.zip CALC_v2.0
