#pragma once

#include <stdio.h>
#include <stdlib.h>

unsigned long hash(char *str);

typedef struct new_customer{
	char *email;
	char name;
	int shoe_size;
	char food;
	struct new_customer *next;
} new_customer;

typedef struct hashtable{
	size_t num_customers;
	new_customer **customers;
} hashtable;

hashtable *new_hashtable(size_t num_customers);


int **load_info(hashtable *table, char *filename, char *check_email);

void add_customer(hashtable *table, char *email, char *name, int shoe_size, char *food);   //was *name, *food

new_customer *lookup(hashtable *table, char *email);

void print_info(hashtable *table, char *email);

void customer_list(hashtable *table);

void save_customer(hashtable *table, char *filename);

void delete_customer(hashtable *table, char *email);

void free_customer(new_customer *customers);

void free_table(hashtable *table);
