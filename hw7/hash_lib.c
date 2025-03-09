#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

// Thank you Dan Bernstein.
unsigned long hash(char *str) {
  unsigned long hash = 5381;
  int c;

  while (*str != '\0') {
    c = *str;
    hash = ((hash << 5) + hash) + (unsigned char)c; /* hash * 33 + c */
    str++;
  }
  return hash;
}

// Inventory system for an online retailer.
// key: name of the thing
// values: how many we have, price

typedef struct new_customer {
  char *email;
  char *name;   //was *name
  int shoe_size;
  char *food;   //was *food
  struct new_customer *next;
} new_customer;

typedef struct hashtable {
  // buckets
  size_t num_customers;
  // array of the linked lists that we have;
  new_customer **customers;
} hashtable;

hashtable *new_hashtable(size_t num_customers) {
  hashtable *output = calloc(1, sizeof(hashtable));
  output->num_customers = num_customers;

  output->customers = calloc(num_customers, sizeof(new_customer *));
  return output;
}


void free_customer(new_customer *customers){
        if (customers){
                free(customers->email);
                free(customers->name);
                free(customers->food);
                free(customers);
}
}


new_customer *lookup(hashtable *table, char *email) {
  unsigned long hashed = hash(email);
  unsigned long customer_num = hashed % table->num_customers;
  // this is a specific bucket that's in the array of buckets.
  new_customer* current = table->customers[customer_num];

  while(current) {
    if (!strcmp(current->email, email)) {
        printf("email: %s  name: %s  shoe size: %d  food: %s\n",current->email,current->name,current->shoe_size,current->food);
        return current;
    }
    current = current->next;
  }
  
  return NULL;
}




void add_customer(hashtable *table, char *email, char *name, int shoe_size, char *food) {
  // decide which bucket.
  unsigned long hashed = hash(email);
  unsigned long customer_num = hashed % table->num_customers;

  printf("hash for '%s': %lu, goes to bucket %lu\n", email, hashed, customer_num);

  // this is a specific bucket that's in the array of buckets.
  new_customer* customers = table->customers[customer_num];

  // allocate the linked list node.
  new_customer* another_customer = calloc(1, sizeof(new_customer));
  another_customer->email = strdup(email);
  another_customer->name = strdup(name);
  another_customer->shoe_size = shoe_size;
  another_customer->food = strdup(food);

  //new_customer *check_email = lookup(table,another_customer->email)
  if (!(lookup(table, another_customer->email))){
	another_customer->next = table->customers[customer_num];
  	table->customers[customer_num] = another_customer;
  } else {
	  new_customer* current = lookup(table,another_customer->email);
	  free(current->food);
	  free(current->name);
	  current->food = another_customer->food;
	  current->name = another_customer->name;
	  current->shoe_size = another_customer->shoe_size;
  		
  	}
  	
  // pop a new pointer into that array of pointers.
  //table->customers[customer_num] = another_customer;
  return;
}

//was **
int load_info(hashtable *table, char *filename, char *check_email){
        FILE *file = fopen(filename, "r");
        //new_customer* another_customer = calloc(1, sizeof(new_customer));
        if (!file){
                perror("failed to open file");

        }
        char buffer[1024];
        while(fgets(buffer,sizeof(buffer),file)){
                buffer[strcspn(buffer,"\n")] = '\0';
                char *section[4];
                int num_sections = 0;
                char *separate = strtok(buffer,"\t");
                while(separate != NULL){
                        section[num_sections] = separate;
                        num_sections++;
                        separate = strtok(NULL,"\t");
                }
        if(check_email == NULL){            //new
                char *email = section[0];    //was char *email , char *name, int shoe_size, char *food)
                char *name = section[1];
                int shoe_size = atoi(section[2]);
                char *food = section[3];
                add_customer(table, email, name, shoe_size, food);
        } else {  //new
                if (strcmp(check_email,section[0]) == 0){  //new
                        //freopen(filename,"w",file);
			fclose(file);           //new
                        return 1;               //new
                }
        }
        //fclose(file);
        //return 0;
}
fclose(file);
return 0;
}


void delete_customer(hashtable *table, char *email){
	unsigned long hashed = hash(email);
  	unsigned long customer_num = hashed % table->num_customers;

  	//printf("hash for '%s': %lu, goes to bucket %lu\n", email, hashed, customer_num);

  // this is a specific bucket that's in the array of buckets.
  	new_customer* current = table->customers[customer_num];

  // allocate the linked list node.
  	new_customer* previous = NULL;
	while(current){
		if(strcmp(current->email, email) == 0){
			if(previous){
				previous->next = current->next;
			}else {
				table->customers[customer_num] = current->next;
			}
			free_customer(current);
			return;
		}
		previous = current;
		current = current->next;
	}
}

void free_table(hashtable *table){
	for (size_t i = 0; i < table->num_customers; i++){
		new_customer *current = table->customers[i];
		while(current != NULL){
			new_customer *next = current->next;
			
			free_customer(current);
			current = next;
		}
	
	}
	free(table->customers);	
	free(table);
}




void customer_list(hashtable *table){
		
	for (size_t i = 0; i < table->num_customers; i++){
		new_customer* current = table->customers[i];
		while(current){
			if(current->email != NULL){
				printf("Customer email: %s\nCustomer name: %s\nCustomer shoe size: %d\nCustomer food: %s\n\n",current->email,current->name,current->shoe_size,current->food);
				current = current->next;
			}
		}
	}

}


void save_customer(hashtable *table, char *filename){
	FILE *file = fopen(filename, "w+");
		for (size_t i = 0; i < table->num_customers; i ++){
			new_customer* current = table->customers[i];
			while(current){
				if (current->email != NULL){
					fprintf(file, "%s\t%s\t%d\t%s\t\n",current->email,current->name,current->shoe_size,current->food);
					current = current->next;
				}
			}
		}
fclose(file);
}


void print_info(hashtable *table, char *email) {
  new_customer *found = lookup(table, email);
  if (found) {
    printf("found it!\n");
    printf("email: %s\n name: %s\n shoe size: %d\n food: %s\n", found->email, found->name, found->shoe_size, found->food);
  } else {
    printf("not found: %s\n", email);
  }
}


