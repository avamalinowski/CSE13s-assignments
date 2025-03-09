#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "wordle_lib.h"

int main(void) {
  printf("\n**** tests for free_vocabulary ****\n");
  char **expected_vocabulary;
  expected_vocabulary = calloc(20, sizeof(char *));
  int i = 0;
  expected_vocabulary[i++] = strdup("moody");
  expected_vocabulary[i++] = strdup("sheep");
  expected_vocabulary[i++] = strdup("hippy");
  expected_vocabulary[i++] = strdup("sleet");
  expected_vocabulary[i++] = strdup("oxide");
  expected_vocabulary[i++] = strdup("flour");
  expected_vocabulary[i++] = strdup("copse");
  expected_vocabulary[i++] = strdup("nobly");
  expected_vocabulary[i++] = strdup("fraud");
  expected_vocabulary[i++] = strdup("geese");
  expected_vocabulary[i++] = strdup("clown");
  expected_vocabulary[i++] = strdup("adobe");
  expected_vocabulary[i++] = strdup("knack");
  expected_vocabulary[i++] = strdup("decor");
  expected_vocabulary[i++] = strdup("gawky");
  expected_vocabulary[i++] = strdup("jumpy");
  expected_vocabulary[i++] = strdup("shaft");
  expected_vocabulary[i++] = strdup("draft");
  expected_vocabulary[i++] = strdup("belle");
  expected_vocabulary[i++] = strdup("jiffy");

  free_vocabulary(expected_vocabulary, 20);

  expected_vocabulary = calloc(20, sizeof(char *));
  i = 0;
  expected_vocabulary[i++] = strdup("clown");
  expected_vocabulary[i++] = strdup("adobe");
  expected_vocabulary[i++] = strdup("knack");
  expected_vocabulary[i++] = strdup("decor");
  expected_vocabulary[i++] = strdup("gawky");
  expected_vocabulary[i++] = strdup("jumpy");
  expected_vocabulary[i++] = strdup("shaft");
  expected_vocabulary[i++] = strdup("draft");
  expected_vocabulary[i++] = strdup("belle");
  expected_vocabulary[i++] = strdup("jiffy");

  free_vocabulary(expected_vocabulary, 10);

  printf("ran free_vocabulary\n");
  printf("run this test with valgrind to know if it's working correctly!\n");

  return 0;
}
