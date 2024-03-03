OBJS = main.o students.o
CC = g++
LFLAGS = -Wall -pedantic

all: Lab03

Lab03: $(OBJS)
    $(CC) $(LFLAGS) $(OBJS) -o Lab03

main.o: main.cpp students.h
    $(CC) $(LFLAGS) -c main.cpp

students.o: students.cpp students.h
    $(CC) $(LFLAGS) -c students.cpp

.PHONY: clean

clean:
    rm -f *.o Lab03

run: Lab03
    ./Lab03