#include "editor_lib.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


ll_text *create_new(char *text){
  ll_text *newnode = (ll_text *)malloc(sizeof(ll_text));
  newnode->text = strdup(text);
  newnode->next = NULL;
  return newnode;
}

void node_print(ll_text *list){
	while (list != NULL){
		printf("this is list %s\n",list->text);
		list = list->next;
	}
}

// Functions about ll_text...
// append a line: add to the end of the linked list
ll_text *append_text(ll_text *list, char *text) {
  ll_text *newnode = create_new(text);
  ll_text *temp = list;
  if (list == NULL){
	list = newnode;
  	return list; 
  } else {
	while (temp->next != NULL){	
		temp = temp->next;
	}
	temp->next = newnode;
	return list;
  }

}

void save_to_file(ll_text *list, const char *filename) {
  FILE *outfile = fopen(filename, "w");
  for (ll_text *here = list; here; here = here->next) {
    fprintf(outfile, "%s\n", here->text);
  }
  fclose(outfile);
}

int ll_text_length(ll_text *list) {
  int count = 0;
  while (list != NULL){
	count++;
	list = list->next;
	
  }
  free(list);
  return count;

}

// insert a specific line: add to specific place in the linked list; this is the
// new entry at the specified line
ll_text *insert_text(ll_text *list, char *text, int position) {

  ll_text *newnode = create_new(text);
  if (newnode == NULL){
  	return NULL;
  }

  if (position == 0){
	newnode->next = list;
	return newnode;
  }

  ll_text *currently = list;
  for(int i = 0; i <position-1;i++){
  	currently = currently->next;
  }

  newnode->next = currently->next;
  currently->next = newnode;

return list;
}	


// delete a specific line: delete the ith entry in the linked list and return
// the new front of the linked list.
ll_text *delete_text(ll_text *list, int position) {
  ll_text *test = list;
  if (position == 0){
	  test = list->next;
	  free(list->text);
	  free(list);
	  return test;
  }
  ll_text *temp = list;
  ll_text *tofree = list;
  for (int i = 0; i < ll_text_length(list); i++){
	if (i == position-1){
		tofree = list->next;
		list->next = list->next->next;
		free(tofree->text);
		free(tofree);
	}	

	list = list->next; 
  }
  	
  	list = temp;
	return list;
}

// replace a line: go to the specific entry, free the text that's there, replace
// it with a copy of the specified text.
ll_text *replace_text(ll_text *list, char *text, int position) {
  ll_text *temp = list;
  for (int i = 0; i < position; i++){  
	  temp = temp->next;
  }
		free(temp->text);
		temp->text = strdup(text);
return list;
}

// duplicate a list. Returns a copy of the list, including newly copied versions
// of all of the strings.
ll_text *duplicate_ll_text(ll_text *list) {
  if (list == NULL){
	  return NULL;
  }
  ll_text *duplicate = (ll_text *)malloc(sizeof(ll_text));
  duplicate->text = strdup(list->text);
  duplicate->next = duplicate_ll_text(list->next);
  return duplicate;
}

// functions about the state stack...
ll_text_stack *load_from_file(const char *filename) {
  ll_text *lines = NULL;
  ll_text_stack *stack = calloc(1, sizeof(ll_text_stack));
  char buf[1024];
  FILE *infile = fopen(filename, "r");
  while (fgets(buf, 1024, infile)) {
    chomp(buf);
    lines = append_text(lines, buf);
  }
  stack->lines = lines;
  return stack;
}

ll_text_stack *new_stack_empty_text(void) {
  ll_text_stack *stack = calloc(1, sizeof(ll_text_stack));
  stack->lines = NULL;
  return stack;
}



ll_text_stack *push_duplicate(ll_text_stack *stack) {
  ll_text_stack *push = malloc(sizeof(ll_text_stack));
  push->lines = duplicate_ll_text(stack->lines);
  push->next = stack;
  return push;
}

// Push a new entry onto the stack that has an empty ll_text at the top.
ll_text_stack *push_empty(ll_text_stack *stack) {
  ll_text_stack *empty = (ll_text_stack *)malloc(sizeof(ll_text_stack));
  empty->lines = NULL; //new_stack_empty_text();
  empty->next = stack;
  
  return empty;
 
}

// undo, removing the most recent state
// this has to free all the memory associated with that state
ll_text_stack *pop_stack(ll_text_stack *stack) {

  ll_text_stack *top = stack->next;
  ll_text *clear = stack->lines;
  //stack = stack->next;
  for (int i = 0; i < ll_text_length(stack->lines); i++){
	  delete_text(clear,i);
  }
  free(stack);
  
  return top; 
 
}

// Find the first newline in the input and replace it with \0
void chomp(char *s) {
  for (int i = 0; s[i]; i++) {
    if (s[i] == '\n' || s[i] == '\r') {
      // Check for \r in case we're on Windows or a very old Mac??
      // Look, I won't stop you from doing CSE 13s on a Mac from 2001 or prior.
      s[i] = '\0';
      break;
    }
  }
}
