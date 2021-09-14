CC=gcc
AR=ar
FLAGS= -Wall -g

all: libFrequency.a frequencys

frequency: libFrequency.a

frequencys: main.o libFrequency.a
	$(CC) $(FLAGS) -o frequency main.o Frequency.o ./libFrequency.a

libFrequency.a: Frequency.o
			$(AR) -rcs libFrequency.a Frequency.o

main.o: main.c Frequency.h
	$(CC) $(FLAGS) -c main.c

Frequency.o: Frequency.c Frequency.h
			$(CC) $(FLAGS) -c Frequency.c

.PHONY: clean all frequency

clean:
	rm -f *.o *.a *.so frequency