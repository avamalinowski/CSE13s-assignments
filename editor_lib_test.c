#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "editor_lib.h"

void str_should_be_exactly_equal(const char *message, char *expected,
                                 char *actual) {
  printf("%s\n", message);
  printf("%s: wanted \"%s\", got \"%s\"\n",
         !strcmp(expected, actual) ? "SUCCESS" : "FAILURE", expected, actual);
}

void should_be_exactly_equal(const char *message, int expected, int actual) {
  printf("%s\n", message);
  printf("%s: wanted %d, got %d\n",
         (expected == actual) ? "SUCCESS" : "FAILURE", expected, actual);
}

int main(void) {
  printf("**********************\n");
  printf("tests for append_text\n");
  printf("**********************\n");
  ll_text *list = NULL;
  list = append_text(list, "hello");

  str_should_be_exactly_equal("empty list and then append hello", "hello",
                             list->text);
  free(list->text);
  free(list);

  list = NULL;
  list = append_text(list, "hello");
  str_should_be_exactly_equal("empty list and then append hello","hello",list->text);
  list = append_text(list, "second string");
  str_should_be_exactly_equal("empty list and then append two strings",
                              "second string", list->next->text);
  list = append_text(list, "three");
  str_should_be_exactly_equal("empty list and then append two strings",
                              "three", list->next->next->text);
  list = append_text(list, "four");
  str_should_be_exactly_equal("empty list and then append two strings",
                              "four", list->next->next->next->text);
  free(list->next->next->next->text);
  free(list->next->next->next);
  free(list->next->next->text);
  free(list->next->next);
  free(list->next->text);
  free(list->next);
  free(list->text);
  free(list);




  printf("\n**********************\n");
  printf("tests for insert_text\n");
  printf("**********************\n");

  list = NULL;
  //list = append_text(list, "one");
  //list = append_text(list, "two");
  //list = insert_text(list, "three", 1);
  //str_should_be_exactly_equal("check if index 1 is now 'three'","three",list->next->text);
  //str_should_be_exactly_equal("check if index 0 is still 'one'","one",list->text);
  //str_should_be_exactly_equal("check if index 2 is now 'two'","two",list->next->next->text);
  list = append_text(list, "hello");
  //list = append_text(list, "ayyo");
  list = insert_text(list, "new first string", 0);
  str_should_be_exactly_equal("empty list and then append and then insert",
                              "new first string", list->text);

  list = insert_text(list, "one", 1);
  str_should_be_exactly_equal("empty list and then append and then insert",
                              "new first string", list->text);

  str_should_be_exactly_equal("empty list and then append and then insert",
                              "one", list->next->text);
  //str_should_be_exactly_equal("empty list and then append and then insert","ayyo",list->next->next->text);
  str_should_be_exactly_equal("empty list and then append and then insert",
                              "hello", list->next->next->text);
  // str_should_be_exactly_equal("empty list and then append and then insert","ayyo",list->next->next->next->text);
  //ee(list->next->next->next->text);
  //ee(list->next->next->next);
  free(list->next->next->text);
  free(list->next->next);
  free(list->next->text);
  free(list->next);
  free(list->text);
  free(list);

  printf("\n**********************\n");
  printf("tests for delete_text\n");
  printf("**********************\n");

  list = NULL;
  list = append_text(list, "hello");
  list = insert_text(list, "new first string", 0);
  list = insert_text(list, "one", 1);

  list = delete_text(list, 1);

  str_should_be_exactly_equal("append and then insert and then delete",
                              "new first string", list->text);
  str_should_be_exactly_equal("append and then insert and then delete", "hello",
                              list->next->text);

  list = delete_text(list, 0);
  str_should_be_exactly_equal("append and then insert and then delete", "hello",
                              list->text);
  free(list->text);
  free(list);

  printf("\n**********************\n");
  printf("tests for replace_text\n");
  printf("**********************\n");

  list = NULL;
  list = append_text(list, "hello");
  list = insert_text(list, "new first string", 0);
  list = insert_text(list, "one", 1);

  list = replace_text(list, "two", 1);
  str_should_be_exactly_equal("append, two inserts, then replace", "two",
                              list->next->text);

  list = replace_text(list, "good evening", 0);
  str_should_be_exactly_equal("append, two inserts, then replace",
                              "good evening", list->text);

  free(list->next->next->text);
  free(list->next->next);
  free(list->next->text);
  free(list->next);
  free(list->text);
  free(list);

  printf("\n**********************\n");
  printf("tests for duplicate_ll_text\n");
  printf("**********************\n");

  list = NULL;
  list = append_text(list, "one");
  list = append_text(list, "two");
  list = append_text(list, "three");

  ll_text *newlist = duplicate_ll_text(list);
  str_should_be_exactly_equal("copied list", "one", newlist->text);
  str_should_be_exactly_equal("copied list", "three",
                              newlist->next->next->text);

  printf("%s: pointers for lists should not be equal\n",
         (list != newlist) ? "SUCCESS" : "FAILURE");

  printf("%s: pointers for strings in lists should not be equal\n",
         (list->text != newlist->text) ? "SUCCESS" : "FAILURE");

  free(list->next->next->text);
  free(list->next->next);
  free(list->next->text);
  free(list->next);
  free(list->text);
  free(list);

  free(newlist->next->next->text);
  free(newlist->next->next);
  free(newlist->next->text);
  free(newlist->next);
  free(newlist->text);
  free(newlist);

  printf("\n**********************\n");
  printf("tests for ll_text_length\n");
  printf("**********************\n");

  list = NULL;

  should_be_exactly_equal("length of empty list should be 0", 0,
                          ll_text_length(list));

  list = append_text(list, "one");
  list = append_text(list, "two");
  list = append_text(list, "three");

  should_be_exactly_equal("length of list should now be 3", 3,
                          ll_text_length(list));

  free(list->next->next->text);
  free(list->next->next);
  free(list->next->text);
  free(list->next);
  free(list->text);
  free(list);

  printf("\n**********************\n");
  printf("tests for push_duplicate\n");
  printf("**********************\n");

  list = NULL;
  list = append_text(list, "one");

  ll_text_stack *stack = calloc(1, sizeof(ll_text_stack));
  stack->lines = list;

  stack = push_duplicate(stack);
  str_should_be_exactly_equal("made a new entry in the stack", "one",
                              stack->lines->text);
  str_should_be_exactly_equal("old entry is still there", "one",
                              stack->next->lines->text);

  free(stack->next->lines->text);
  free(stack->next->lines);
  free(stack->next);
  free(stack->lines->text);
  free(stack->lines);
  free(stack);

  printf("\n**********************\n");
  printf("tests for push_empty\n");
  printf("**********************\n");

  list = NULL;
  list = append_text(list, "one");
  stack = calloc(1, sizeof(ll_text_stack));
  stack->lines = list;

  stack = push_empty(stack);
  printf("%s: lines list for top of stack should be empty\n",
         (stack->lines == NULL) ? "SUCCESS" : "FAILURE");
  str_should_be_exactly_equal("old entry is still there", "one",
                              stack->next->lines->text);

  free(stack->next->lines->text);
  free(stack->next->lines);
  free(stack->next);
  free(stack->lines);
  free(stack);

  printf("\n**********************\n");
  printf("tests for pop_stack\n");
  printf("**********************\n");

  list = NULL;
  list = append_text(list, "one");
  stack = calloc(1, sizeof(ll_text_stack));
  stack->lines = list;

  stack = push_empty(stack);
  stack = pop_stack(stack);
  str_should_be_exactly_equal("old entry is restored after popping", "one",
                              stack->lines->text);

  free(stack->lines->text);
  free(stack->lines);
  free(stack);

  return 0;
}
