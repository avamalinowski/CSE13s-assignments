#include <stdio.h>
#include <stdlib.h>

void remove_newline(char *s, int maxsize) {
  for (int i = 0; i < maxsize && s[i]; i++) {
    if (s[i] == '\n') {
      s[i] = '\0';
      return;
    }
  }
}

long operation(long num1, long num2, char operator) {
    switch (operator) {
        case '+': return num1 + num2;
        case '-': return num1 - num2;
	case '*': return num1 * num2;
        case '/':
            if (num2 == 0) {
                printf("ERROR\n");
		exit(EXIT_FAILURE);
            } else {
            return num1 / num2;
	    }
        default:
            printf("ERROR\n");
            exit(EXIT_FAILURE);
    }
}

long add(long first, long second){
	return first + second;
}

int main(int argc, char *argv[]) {
  const int BUFSIZE = 80;
  char buffer[BUFSIZE];
  FILE *infile = NULL;

  if (argc != 2) {
    fprintf(stderr, "calculator needs exactly 1 argument, the input file\n");
    return 1;
  }
  infile = fopen(argv[1], "r");
  if (!infile) {
    fprintf(stderr, "input file %s not found\n", argv[1]);
    return 1;
  }

  // Your code should go here-ish. Feel free to change this loop as you need to.
  // IMPORTANT: your output should either be the single line "ERROR\n", or the
  // single number output.
  


    int counter = 0;
    char *pointer;
    long num;
    long answer;
    long first;
    long second = 0;
    char operator;
  while (fgets(buffer, BUFSIZE, infile)) {
    // TODO: implement the calculator.
    remove_newline(buffer, BUFSIZE); 
    num = strtol(buffer,&pointer,10);
    if (counter == 0){
	    first = num;
	    counter ++;
	    continue;
	    
    }
    if (counter == 1){
    	operator = *pointer;
	counter++;
	continue;
    }
    if (second == 0 && operator == 0){
    	operator = *pointer;
	continue;
    }
    if (second == 0){
        second = num;
        counter++;
    }
    if (operator != 0){
       answer = operation(first,second,operator);
       operator = 0;
       second = 0;
    }
    first = answer; 
  }
  printf("%ld\n",answer);
  return 0;
}

