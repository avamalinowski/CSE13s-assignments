#include <stdio.h>

int main(void) {
  // Finish this program. You'll almost certainly want to use a loop of some
  // kind, getchar() and putchar(). Remember that the output of getchar() is the
  // symbol EOF when you get to the end of the input
  
  while (1){
  	int letter = getchar();
	if (letter == EOF){
		break;
	}
	if ((letter == 'a') || (letter == 'e') || (letter == 'i') || (letter == 'o') || (letter == 'u') || (letter == 'A') || (letter == 'I') || (letter == 'O') || (letter == 'U')){ 
		putchar(letter);
		putchar(letter);
		letter ++;
	} else {
		putchar(letter);
		letter ++;
	} 
}
  return 0;
  }
