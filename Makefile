CC = clang
CFLAGS = -Wall -Wpedantic -Werror -Wextra

all: wordle_game free_vocabulary_test wordle_lib_test

wordle_game: wordle_game.o wordle_lib.o
	$(CC) wordle_game.o wordle_lib.o -o wordle_game

free_vocabulary_test: free_vocabulary_test.o wordle_lib.o
	$(CC) free_vocabulary_test.o wordle_lib.o -o free_vocabulary_test

wordle_lib_test: wordle_lib_test.o wordle_lib.o
	$(CC) wordle_lib_test.o wordle_lib.o -o wordle_lib_test

wordle_game.o: wordle_game.c wordle_lib.h
	$(CC) $(CFLAGS) -c wordle_game.c 

wordle_lib.o: wordle_lib.c wordle_lib.h
	$(CC) $(CFLAGS) -c wordle_lib.c 

wordle_lib_test.o: wordle_lib_test.c wordle_lib.h
	$(CC) $(CFLAGS) -c wordle_lib_test.c 

free_vocabulary_test.o: free_vocabulary_test.c wordle_lib.h
	$(CC) $(CFLAGS) -c free_vocabulary_test.c 


clean:
	rm -f wordle_game wordle_lib_test free_vocabulary_test
	rm -f wordle_game.o wordle_lib.o wordle_lib_test.o \
		free_vocabulary_test.o

format:
	clang-format -i -style=file *.[ch]
