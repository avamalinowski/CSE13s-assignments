CC = clang

businessdb: businessdb.o hash_lib.o
	$(CC) businessdb.o hash_lib.o -o businessdb

businessdb.o: businessdb.c hash_lib.h
	$(CC) -c businessdb.c

hash_lib.o: hash_lib.c hash_lib.h
	$(CC) -c hash_lib.c

clean:
	rm -f businessdb.o hash_lib.o


