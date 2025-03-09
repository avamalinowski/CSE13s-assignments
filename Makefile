CC = clang
CFLAGS = -Wall -Wpedantic -Werror -Wextra

all: hw2_test calculator

hw2_test: hw2.o hw2_test.o
	$(CC) hw2.o hw2_test.o -o hw2_test

hw2.o: hw2.c hw2.h
	$(CC) $(CFLAGS) -c hw2.c

hw2_test.o: hw2_test.c hw2.h
	$(CC) $(CFLAGS) -c hw2_test.c

calculator: calculator.c
	$(CC) $(CFLAGS) calculator.c -o ./calculator

clean:
	rm -f calculator hw2_test hw2.o hw2_test.o

format:
	clang-format -i -style=file *.[ch]
