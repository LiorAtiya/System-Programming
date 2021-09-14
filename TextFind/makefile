CC=gcc
AR=ar
FLAGS= -Wall -g

all: libTextFind.a libInsertionSort.a isort txtfind

txtfinds: libTextFind.a

isorts: libInsertionSort.a

isort: main_sort.o libInsertionSort.a
	$(CC) $(FLAGS) -o isort main_sort.o InsertionSort.o ./libInsertionSort.a

txtfind: main_txtfind.o libTextFind.a
	$(CC) $(FLAGS) -o txtfind main_txtfind.o TextFind.o ./libTextFind.a

libInsertionSort.a: InsertionSort.o
			$(AR) -rcs libInsertionSort.a InsertionSort.o

libTextFind.a: TextFind.o
			$(AR) -rcs libTextFind.a TextFind.o

main_txtfind.o: main_txtfind.c TextFind.h
	$(CC) $(FLAGS) -c main_txtfind.c

main_sort.o: main_sort.c InsertionSort.h
	$(CC) $(FLAGS) -c main_sort.c

TextFind.o: TextFind.c TextFind.h
			$(CC) $(FLAGS) -c TextFind.c

InsertionSort.o: InsertionSort.c InsertionSort.h
			$(CC) $(FLAGS) -c InsertionSort.c

.PHONY: clean all isort txtfind

clean:
	rm -f *.o *.a *.so isort txtfind