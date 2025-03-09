/*
 * All of your code goes in here. You need to finish these functions.
 */

#include "hw2.h"

int next_collatz_number(int n) {
  if (n % 2 == 0){
    return (n/2);
  } else {
    return ((n*3) + 1);
  }
    
}

int count_collatz_steps(int n) {
  int counter = 0;
  while (n != 1){
    if (n % 2 == 0){
      n = (n/2);
      counter ++;
  } else {
      n = ((n*3) + 1);
      counter ++;
  }
}
return counter;
}

int maximum(int *nums, int len) {
 int max = 0;
  for(int i=0;i < len; i++){
    if (max < nums[i]){
        max = nums[i];
    }else{
	continue;
    } 
}
return max;
}

int sum_positive(int *nums, int len) {
	int sum = 0;
  for (int i=0;i<len;i++){
    if (nums[i]>0){
      sum = sum + nums[i];
    } else {
      continue;
    }
  }
  return sum;
}

int count_negative(int *nums, int len) {
  int counter = 0;
  for (int i=0;i<len;i++){
    if (nums[i]<0){
      counter++;
    } else {
      continue;
    }
  }
  return counter;
}
