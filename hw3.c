/*
 * All of your code goes in here. You need to finish these functions.
 */

#include "hw3.h"
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

bool str_suffix(char *haystack, char *needle) {
  int lenhaystack = strlen(haystack);  //was size_t
  int lenneedle = strlen(needle);  //was size_t
  int unchangedhaystack = strlen(haystack);
 // char testneedle;
  //char testhaystack;
  if (lenneedle > lenhaystack){
	  //printf("needle is greater than haystack\n");
	  return false;
  }
  if (*needle == '\0'){
	  return true;
}
  if (strcmp(haystack,needle) == 0){ 
    //int string = strcmp(haystack,needle);
    //printf("needle haystack equal, string is %d\n",string);
	  return true;
  }
int hay;
int ned;
int a = 0;
for (int i = 0;i < unchangedhaystack;i++){
	hay = haystack[i];
	ned = needle[a];
	if (lenneedle !=0){
		if ((hay == ned)||(hay-ned == 32)||(ned - hay == 32)){
			lenneedle--;
			a++;
			lenhaystack--;
			continue;
		} else {
			lenhaystack--;
			continue;
		}
	} else {
		if (lenhaystack > 0){
			return false;
		} else {
			return true;
	}
}
}


return true;
}
//}


char *str_repeat(char *s, int n) {
  int length = strlen(s);
  int totallength = length * n;
  char *out = malloc(sizeof(totallength) + 1);
  out[0] = '\0';
  char *running = NULL;
	for (int i = 0; i < n; i ++){
		if (out == (void *)0){
			return out;
		}
	running = &s[0];
	strcat(out, running);
	
    }
  return out; 
}
   
bool str_is_palindrome(char *s) {
	//UNUSED(s);
	//*s = tolower(*s);
	int length = strlen(s);
	int forward;
	int backward;
	//int compare;
	//int compare2;
	for (int i = 0, j = length-1; ((i <= length) && (j >= 0)); i++,j--){
		forward = s[i];
		backward = s[j];
		//printf("forward = %d\n",forward);
		//printf("backward = %d\n",backward);
		//printf("&foward = %s\n",&forward);
		//printf("&backward = %s\n",&backward);
		//compare = forward - backward;
		//compare2 = backward - forward;
		if (((ispunct(s[i])) && (ispunct(s[j]))) || ((isspace(s[i])) && ((isspace(s[j]))))){
			continue;
		}
icompare:
		if ((ispunct(s[i])) || (isspace(s[i]))){
		//	printf("add to i\n");
			i++;
			forward = s[i];
		//	printf("forrward is now = %d\n",forward);
			goto icompare;
		}
jcompare:
		if ((ispunct(s[j])) || (isspace(s[j]))){
		//	printf("subtract from j");
			j--;
		//	printf("j is %d\n",j);
			backward = s[j];
		//	printf("backward is now = %d\n",backward);
			goto jcompare;
			
		}
		if ((forward - backward == 32) || (backward - forward == 32) || (forward == backward)){
		//	printf("compare is %d\n",compare);
		//	printf("compare2 is %d\n",compare2);
		//	printf("it continued\n");
			continue;
		} else {
		//	printf("not equal forward %d\n",forward);
		//	printf("not equal backward %d\n",forward);
		//	printf("comparison when not equal %d\n",compare);
		//	printf("compare2 when not equal %d\n",compare2);
		//	printf("it wasn't equal\n");
			return false;

	}
		//return true;
	}
	return true;

	
}

float dot_product(float *vec_a, float *vec_b, int length) {
  int first;
  int second;
  int result = 0;
  for (int i = 0; i < length;i++){
  	first = vec_a[i];
	second = vec_b[i];
	result = result + (first * second);
  }
return result;

}

int reduce(int *nums, int length, int (*f)(int, int), int initial) {
  int running;
  for (int i = 0; i < length; i++){
	running = nums[i];
  	initial = f(initial,running);
  } 
  return initial;
  
}

// These two functions will end up as a *single call to reduce*, but you'll have
// to write a new helper function for each of them. Those helper functions will
// be quite short though!

int max(int a, int b){
	return (a > b) ? a : b;
}

int maximum_with_reduce(int *nums, int length) {
  if (length == 0){
	  return INT_MIN;
  }
  return reduce(nums,length,max,INT_MIN);
}

int positive(int current, int next){
	return (next > 0) ? (current + next) : current;
}
int sum_positive_with_reduce(int *nums, int length) {
	return reduce(nums,length,positive,0);
  //UNUSED(nums);
  //UNUSED(length);
  //return 0;
}
