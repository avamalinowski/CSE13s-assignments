#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include "hash_lib.h"



int main(void){
	

	hashtable *information = new_hashtable(100);
//printf("before load info\n");
	load_info(information,"customers.tsv", NULL);

	add_customer(information, "jordan.lol@gmail.com","jordan", 12, "turkey");
	add_customer(information, "subaru@deepfake.org","Subaru BRZ", 5, "cucumber");
	delete_customer(information, "subaru@deepfake.org");
	char mail[256];
	char name[256];
	int shoe;
	char food[256];
	while(1){
		char command[256];
	printf("Please enter a command: ");
	if(fgets(command,256,stdin) == NULL){
		break;
		}	
	if (strcmp(command,"quit\n") == 0){
		break;
	}else if (strcmp(command, "save\n") == 0){
		save_customer(information, "customers.tsv");
	}else if(strcmp(command, "add\n") == 0){
		//printf("");
		printf("email address: ");
		fgets(mail,256,stdin);
		mail[strcspn(mail,"\n")] = '\0';
		printf("name: ");
		fgets(name, 256,stdin);
		name[strcspn(name,"\n")] = '\0';
		printf("shoe size: ");
		scanf("%d", &shoe);
		getchar();
		printf("favorite food: ");
		fgets(food,256,stdin);
		food[strcspn(food,"\n")] = '\0';
		add_customer(information,mail,name,shoe,food);
	}else if (strcmp(command, "lookup\n") == 0){
		char email[256];
		printf("email address to lookup: ");
		fgets(email,sizeof(email),stdin);
		email[strcspn(email,"\n")] = '\0';
		lookup(information,email);
	} else if (strcmp(command, "delete\n") == 0){
		printf("email address: ");
                fgets(mail,256,stdin);
                mail[strcspn(mail,"\n")] = '\0';
		delete_customer(information,mail);
	} else if (strcmp(command, "list\n") == 0){
		customer_list(information);
	} else{
		printf("unknown command\n");
	}
	}


	free_table(information);
  return 0;

}
