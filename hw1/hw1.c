#include "hw1.h"

#include <math.h>
#include <stdbool.h>
#include <stdio.h>

// For the value of Pi, please use M_PI, which is defined in math.h.
double area_of_disk(double radius) {
  // your code here
  double A = (M_PI * (radius * radius));
  return A;
  // remove all these UNUSED things when you actually write the function.
  //UNUSED(radius);
  //return 0;
}

double area_of_ring(double outer_radius, double inner_radius) {
  // your code here
  double outer = (M_PI * (outer_radius * outer_radius));
  double inner = (M_PI * (inner_radius * inner_radius));
  return (outer - inner);
  //UNUSED(outer_radius);
  //UNUSED(inner_radius);
  //return 0;
}

int bigger_minus_smaller(int a, int b) {
  // your code here
  if (a == b){
  	return 0;
  }
  if (a < b){
  	return (b - a);
  } else {
	  return (a - b);
	
  //UNUSED(a);
  //UNUSED(b);
  //return 0;
}
}
bool value_in_range(int lower_bound, int x, int upper_bound) {
  // your code here
  if ((x <= upper_bound) && (x>= lower_bound)){
	  return true;
  } else {
	  return false;
  }
  //UNUSED(lower_bound);
  //UNUSED(upper_bound);
  //UNUSED(x);
  //return false;
}

int sum_of_greater_squares(int a, int b, int c) {
  // your code here
  int as = (a*a);
  int bs = (b*b);
  int cs = (c*c);
  if ((as < bs) && (as < cs)){
    return ((bs)+(cs));
  }
  if ((bs < as) && (bs < cs)){
    return ((as)+(cs));
  } else {
    return ((as)+(bs));
  }
  if ((as == bs) && (as == cs) && (bs == cs)){
          return ((as)+(cs));
  //UNUSED(a);
  //UNUSED(b);
  //UNUSED(c);
  //return false;
}
}
