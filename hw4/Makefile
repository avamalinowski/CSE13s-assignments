CC = clang
CFLAGS = -Wall -Wpedantic -Werror -Wextra

all: editor editor_lib_test

editor: editor.o editor_lib.o
	$(CC) editor.o editor_lib.o -o editor

editor_lib_test: editor_lib_test.o editor_lib.o
	$(CC) editor_lib_test.o editor_lib.o -o editor_lib_test

editor_lib.o: editor_lib.c editor_lib.h
	$(CC) $(CFLAGS) -c editor_lib.c

editor_lib_test.o: editor_lib_test.c editor_lib.h
	$(CC) $(CFLAGS) -c editor_lib_test.c

editor.o: editor.c editor_lib.h
	$(CC) $(CFLAGS) -c editor.c

clean:
	rm -f editor_lib_test editor editor.o editor_lib_test.o editor_lib.o

format:
	clang-format -i -style=file *.[ch]
