# change application name here (executable output name)
TARGET=calc
 
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
	$(LD) main_calc/calculator.c main_calc/callbacks.c -o $(TARGET) $(OBJS) $(LDFLAGS)
    
main.o: main_calc/main.c
	$(CC) -c $(CCFLAGS) main_calc/main.c $(GTKLIB) -o main.o
    
clean:
	rm -f *.o $(TARGET)
