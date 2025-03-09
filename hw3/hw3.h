#pragma once
#include <stdbool.h>

bool str_suffix(char *haystack, char *needle);

char *str_repeat(char *s, int n);

bool str_is_palindrome(char *s);

float dot_product(float *vec_a, float *vec_b, int length);

int reduce(int *nums, int length, int (*f)(int, int), int initial);

int maximum_with_reduce(int *nums, int length);

int sum_positive_with_reduce(int *nums, int length);

// Idea for the UNUSED macro from Stack Overflow user mtvec. Thanks!
// https://stackoverflow.com/a/3599170
#define UNUSED(x) (void)(x)
