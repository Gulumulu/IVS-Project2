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
	$(LD) main_calculator/callbacks.c main_calculator/calculator.c -o $(TARGET) $(OBJS) $(LDFLAGS)

main.o: main_calculator/main.c
	$(CC) -c $(CCFLAGS) main_calculator/main.c $(GTKLIB) -o main.o

clean:
	rm -f *.o $(TARGET)
