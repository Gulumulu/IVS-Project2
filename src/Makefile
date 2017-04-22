# change application name here (executable output name)
TARGET=calculator
 
# compiler
CC=gcc
# debug
DEBUG=-g
# optimisation
OPT=-O0
# warnings
WARN=-Wall
 
PTHREAD=-pthread
 
CCFLAGS=$(DEBUG) $(OPT) $(WARN) $(PTHREAD) -pipe
 
GTKLIB=`pkg-config --cflags --libs gtk+-3.0`
 
# linker
LD=gcc
LDFLAGS=$(PTHREAD) $(GTKLIB) -export-dynamic
 
OBJS=    main.o
 
all: $(OBJS)
	$(LD) src/callbacks.c src/calculator.c -o $(TARGET) $(OBJS) $(LDFLAGS)
    
main.o: src/main.c
	$(CC) -c $(CCFLAGS) home/tomas/Stiahnuté/kalkulacka/Calculator/src/main.c $(GTKLIB) -o main.o
    
clean:
	rm -f *.o $(TARGET)