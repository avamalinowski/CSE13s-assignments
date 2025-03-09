#include "hw3.h"

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void should_be_exactly_equal(const char *message, int expected, int actual) {
  printf("%s\n", message);
  printf("%s: wanted %d, got %d\n",
         (expected == actual) ? "SUCCESS" : "FAILURE", expected, actual);
}

void str_should_be_exactly_equal(const char *message, char *expected,
                                 char *actual) {
  printf("%s\n", message);
  printf("%s: wanted \"%s\", got \"%s\"\n",
         !strcmp(expected, actual) ? "SUCCESS" : "FAILURE", expected, actual);
}

bool approximately_equal(double a, double b) {
  // difference is less than 0.001?
  return fabs(a - b) < 0.001;
}

void should_be_equal(const char *message, double expected, double actual) {
  printf("%s\n", message);
  printf("%s: wanted %f, got %f\n",
         approximately_equal(expected, actual) ? "SUCCESS" : "FAILURE",
         expected, actual);
}

int count_negative_helper(int cumulative, int nextval) {
  return cumulative + ((nextval < 0) ? 1 : 0);
}

void test_str_suffix(char *haystack, char *needle, bool expected) {
  printf("haystack: %s\n", haystack);
  printf("needle  : %s\n", needle);
  bool result = str_suffix(haystack, needle);
  printf("%s: do we think it's a suffix? %s\n",
         (result == expected) ? "SUCCESS" : "FAILURE", result ? "yes" : "no");
}

int main(void) {
  int test_array_1[] = {100, 5, 3, -12, 109, -100};
  int test_array_2[] = {-55, 3, -12, 109, -100, 12, -12, 7000, 12};

  printf("**********************\n");
  printf("tests for str_suffix\n");
  test_str_suffix("", "", true);
  test_str_suffix("long string here", "", true);
  test_str_suffix("long string here", "here", true);
  test_str_suffix("", "something other than nothing", false);
  test_str_suffix("unrelated strings", "completely different", false);
  test_str_suffix("butter","ter",true);
  // new ones
  test_str_suffix("long string here", "string", false);
  test_str_suffix("long string here", "long string", false);
  test_str_suffix("cowabunga", "wabu", false);
  test_str_suffix("I love burgers", "burgers", true);
  test_str_suffix("I \n love", "love", true);

  printf("\n**********************\n");
  printf("tests for str_repeat\n");

  char *repeat_result = NULL;

  repeat_result = str_repeat("hello", 3);
  str_should_be_exactly_equal("repeat hello 3 times", "hellohellohello",
                              repeat_result);
  free(repeat_result);

  repeat_result = str_repeat("hello ", 5);
  str_should_be_exactly_equal("repeat \"hello \" 5 times",
                              "hello hello hello hello hello ", repeat_result);
  free(repeat_result);

  repeat_result = str_repeat("welcome to computer science", 0);
  str_should_be_exactly_equal("repeat \"welcome to computer science\" 0 times",
                              "", repeat_result);
  free(repeat_result);

  repeat_result = str_repeat("cowabunga", 4);
  str_should_be_exactly_equal("repeat \"cowabunga\" 4 times",
		              "cowabungacowabungacowabungacowabunga", repeat_result);
  free(repeat_result);

  printf("\n**********************\n");
  printf("tests for str_is_palindrome\n");

  should_be_exactly_equal("str_is_palindrome: \"sob\"",false,str_is_palindrome("sob"));

  should_be_exactly_equal("str_is_palindrome: \"Sit on a potato pan, Otis\"",
                          true, str_is_palindrome("Sit on a potato pan, Otis"));

  should_be_exactly_equal("str_is_palindrome: \"Mr. Owl ate my metal worm\"",
                          true, str_is_palindrome("Mr. Owl ate my metal worm"));

  should_be_exactly_equal("str_is_palindrome: \"Mr. Owl ate my metal worms\"",
                          false,
                          str_is_palindrome("Mr. Owl ate my metal worms"));

  should_be_exactly_equal("str_is_palindrome: \"bob\"", true,
                          str_is_palindrome("bob"));

  should_be_exactly_equal("str_is_palindrome: \"bobby\"", false,
                          str_is_palindrome("bobby"));
  //should_be_exactly_equal("str_is_palindrome: \"Able was I ere I saw Elba\"", true, str_is_palindrome("Able was I ere I saw Elba"));
  //should_be_exactly_equal("str_is_palindrome: \"A dog! A panic in a pagoda!\"", true, str_is_palindrome("A dog! A panic in a pagoda!"));
  //should_be_exactly_equal("str_is_palindrome: \"Ah, Satan sees Natasha\"", true, str_is_palindrome("Ah, Satan sees Natasha"));
  //should_be_exactly_equal("str_is_palindrome: \"A man, a plan, a canal – Panama!\"", true, str_is_palindrome("A man, a plan, a canal – Panama!"));
  //should_be_exactly_equal("str_is_palindrome: \"A Toyota\"", true, str_is_palindrome("A Toyota"));
  //should_be_exactly_equal("str_is_palindrome: \"A Toyota's a Toyota\"", true, str_is_palindrome("A Toyota's a Toyota"));
  //should_be_exactly_equal("str_is_palindrome: \"Dennis sinned\"", true, str_is_palindrome("Dennis sinned"));
  //should_be_exactly_equal("str_is_palindrome: \"Dennis and Edna sinned\"", true, str_is_palindrome("Dennis and Edna sinned"));
  //should_be_exactly_equal("str_is_palindrome: \"Doc, note: I dissent. A fast never prevents a fatness. I diet on cod\"", true, str_is_palindrome("Doc, note: I dissent. A fast never prevents a fatness. I diet on cod"));
  //should_be_exactly_equal("str_is_palindrome: \"Do geese see God?\"", true, str_is_palindrome("Do geese see God?"));
  //should_be_exactly_equal("str_is_palindrome: \"Do nine men Interpret? Nine men I nod\"", true, str_is_palindrome("Do nine men Interpret? Nine men I nod"));
  //should_be_exactly_equal("str_is_palindrome: \"Drab as a fool, aloof as a bard\"", true, str_is_palindrome("Drab as a fool, aloof as a bard"));
  //should_be_exactly_equal("str_is_palindrome: \"Egad, a base tone denotes a bad age\"", true, str_is_palindrome("Egad, a base tone denotes a bad age"));
  //should_be_exactly_equal("str_is_palindrome: \"God, a red nugget, a fat egg under a dog\"", true, str_is_palindrome("God, a red nugget, a fat egg under a dog"));
  //should_be_exactly_equal("str_is_palindrome: \"Go hang a salami, I'm a lasagna hog\"", true, str_is_palindrome("Go hang a salami, I'm a lasagna hog"));
  //should_be_exactly_equal("str_is_palindrome: \"I, man, am Regal, a German am I\"", true, str_is_palindrome("I, man, am Regal, a German am I"));
  //should_be_exactly_equal("str_is_palindrome: \"If I had a hi-fi\"", true, str_is_palindrome("If I had a hi-fi"));
  //should_be_exactly_equal("str_is_palindrome: \"Lid off a daffodil\"", true, str_is_palindrome("Lid off a daffodil"));
  //should_be_exactly_equal("str_is_palindrome: \"Lived on decaf, faced no devil\"", true, str_is_palindrome("Lived on decaf, faced no devil"));
  //should_be_exactly_equal("str_is_palindrome: \"Lisa Bonet ate no basil\"", true, str_is_palindrome("Lisa Bonet ate no basil"));
  //should_be_exactly_equal("str_is_palindrome: \"Lonely Tylenol\"", true, str_is_palindrome("Lonely Tylenol"));
  //should_be_exactly_equal("str_is_palindrome: \"Madam, I'm Adam\"", true, str_is_palindrome("Madam, I'm Adam"));
  //should_be_exactly_equal("str_is_palindrome: \"Ma is as selfless as I am\"", true, str_is_palindrome("Ma is as selfless as I am"));
  //should_be_exactly_equal("str_is_palindrome: \"May a moody baby doom a yam?\"", true, str_is_palindrome("May a moody baby doom a yam?"));
  //should_be_exactly_equal("str_is_palindrome: \"Mr. Owl ate my metal worm\"", true, str_is_palindrome("Mr. Owl ate my metal worm"));
  //should_be_exactly_equal("str_is_palindrome: \"Name now one man\"", true, str_is_palindrome("Name now one man"));
  //should_be_exactly_equal("str_is_palindrome: \"Name no one man\"", true, str_is_palindrome("Name no one man"));
  printf("\n**********************\n");
  printf("tests for dot_product\n");
  float vec1[] = {1.0, 0, 0};
  float vec2[] = {0, 0, 1.0};
  float vec3[] = {2.0, 2.0, 2.0};

  should_be_equal("dot_product of vec1 and vec2", 0.0,
                  dot_product(vec1, vec2, 3));
  should_be_equal("dot_product of vec1 and vec3", 2.0,
                  dot_product(vec1, vec3, 3));
  should_be_equal("dot_product of vec2 and vec3", 2.0,
                  dot_product(vec2, vec3, 3));
  should_be_equal("dot_product of vec3 and vec3", 12.0,
                  dot_product(vec3, vec3, 3));


  int test_array_3[] = {1,8,7,10,20,100};

  printf("\n**********************\n");
  printf("tests for reduce\n");
  should_be_exactly_equal("reduce with count_negative on test_array_1", 2,
                          reduce(test_array_1, 6, count_negative_helper, 0));
  should_be_exactly_equal("reduce with count_negative on test_array_2", 4,
                          reduce(test_array_2, 9, count_negative_helper, 0));
  should_be_exactly_equal("reduce with count_negative on test_array_3", 0, reduce(test_array_3, 6, count_negative_helper, 0));


  printf("\n**********************\n");
  printf("tests for maximum_with_reduce\n");
  should_be_exactly_equal("maximum of test_array_1", 109,
                          maximum_with_reduce(test_array_1, 6));
  should_be_exactly_equal("maximum of test_array_2", 7000,
                          maximum_with_reduce(test_array_2, 9));

  printf("\n**********************\n");
  printf("tests for sum_positive_with_reduce\n");
  should_be_exactly_equal("sum_positive of test_array_1", 217,
                          sum_positive_with_reduce(test_array_1, 6));
  should_be_exactly_equal("sum_positive of test_array_2", 7136,
                          sum_positive_with_reduce(test_array_2, 9));
  should_be_exactly_equal("sum_positive of test_array_3",146, sum_positive_with_reduce(test_array_3, 6));
  return 0;
}
