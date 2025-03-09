#include "search_util.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// This function should loop over the vocabulary (which contains num_words
// entries) and return the number of words in which that particular letter
// occurs. So if there are 15 words containing the letter 'x' for the particular
// vocabulary, then this function will return 15.
int score_letter(char letter, char **vocabulary, size_t num_words) {
  // TODO(you): implement this function!
	int a = 0;
	int counter = 0;
	for (size_t i = 0; i < num_words; i ++){
	if (vocabulary[i] == NULL){
		continue;
	}
	a = 0;
		while( a < 5 ){
		if (letter == (vocabulary[i][a])){
			counter++;
		}
		a++;
	
	}
	}
  //num_words = counter;
  return counter;
}

// Calculate the score for a given word, where the letter_scores array has
// already been filled out for you and is guaranteed to be of length 26. Slot 0
// contains the score for 'a', and slot 25 contains the score for 'z'.
// The score for a word is the sum of all of the letter scores, *for unique
// letters*. So if the letter 'e' occurs three times, it only contributes to the
// score once.
int score_word(char *word, int *letter_scores) {
  // TODO(you): implement this function!
  int lenword = strlen(word);
  int counter = 0;
  int total = 0;
  int a = 0;
  char pointer = '\0';
  char dupword[6] = {'\0'};
  int lendupword = 0;
  bool duplicate = false;
  //printf("this is word %s\n",word);
  for (int i = 0; i < lenword; i++){
	duplicate = false;
	a = 0;
	counter = 0;
	pointer = word[i];
	lendupword = strlen(dupword);
	for (int j = 0; j < lendupword;j++){
        if (word[i] == dupword[j]){
                duplicate = true;
		break;
        }
	}
	strcat(dupword,&pointer);
	if (duplicate == true){
		continue;
	}
	while(a < 26){
	if (word[i] == ('a' + a)){
		break;
		
	}else{
		counter++;
  	}
	a++;
	}
	total = total + letter_scores[counter];
  }
  return total;
}

// Returns the optimum guess, based on our heuristic.
// This one works, you don't have to change it.
// Note that this function allocates a new string every time it runs, and those
// strings will need to be freed!
char *get_guess(char **vocabulary, size_t num_words) {
  int letter_scores[26];

  for (int i = 0; i < 26; i++) {
    letter_scores[i] = score_letter('a' + i, vocabulary, num_words);
  }

  char *best_guess = NULL;
  int best_score = 0;
  int score = 0;
  for (size_t i = 0; i < num_words; i++) {
    if (vocabulary[i] == NULL) {
      continue;
    }
    score = score_word(vocabulary[i], letter_scores);
    if (score > best_score) {
      best_guess = vocabulary[i];
      best_score = score;
    }
  }
  return best_guess ? strdup(best_guess) : NULL;
}

// This function will filter down the vocabulary based on the knowledge that the
// specified letter *does not occur* in the secret word. So for any of the words
// in the vocabulary that do contain that letter, free their pointers and set
// the corresponding slot to NULL.
// Returns the number of words that have been filtered from the vocabulary.
size_t filter_vocabulary_gray(char letter, char **vocabulary, size_t num_words) {
  // TODO(you): implement this function!
  //printf("this is num words %lu\n",num_words);
  int a = 0;
  size_t counter = 0;
  for (size_t i = 0; i < num_words; i++){
	if (vocabulary[i] == NULL){
		continue;
	}
//	printf("letter %c\n",letter);
	a = 0;
//	printf("i = %lu\n",i);
//	printf("i %zu\n",i);
  	while (a < 5){
		//printf("this is letter %c\n",letter);
//		printf("this is vocabulary[i] %s\n",vocabulary[i]);
		if (vocabulary[i] == NULL){
			//a++;
			//continue;
			break;
		}
		if (letter == vocabulary[i][a]){
			//free(vocabulary[i]);
			//printf("vocabulary[i] %s\n",vocabulary[i]);
			free(vocabulary[i]);
			vocabulary[i] = NULL;
			//free(vocabulary[i]);
//			printf("vocabulary[i] %s\n",vocabulary[i]);
			counter++;
//			printf("broken\n");
			//broken = true;
			break;
//			printf("it broke\n");
		}
	a++;
	}
	//num_words = num_words - counter;
//	printf("num_words = %lu\n",num_words);
	//if (broken == true){
	//	continue;
	//}
  }  
  //UNUSED(letter);
  //UNUSED(vocabulary);
  //UNUSED(num_words);
  //printf("this is counter %lu\n",counter);
  //printf("num_words %lu\n",num_words); 
  printf("finished gray\n");
  return counter;
}

// This function will filter down the vocabulary based on the knowledge that the
// specified letter occurs in the word, *but not at this particular position*.
// So remove any words that either don't contain the letter at all, or do
// contain it, but at the specified position.
// Returns the number of words that have been filtered from the vocabulary.
size_t filter_vocabulary_yellow(char letter, int position, char **vocabulary,
                                size_t num_words) {
  // TODO(you): implement this function!
  int counter = 0;
  int check = 0;
  int a = 0;
  for (size_t i = 0; i < num_words; i++){
	if (vocabulary[i] == NULL){
		continue;
	}
	check = 0;
	a = 0;
	while (a < 5){
		if (letter == vocabulary[i][position]){
			free(vocabulary[i]);
			vocabulary[i] = NULL;
			counter++;
			break;
		}
		if (letter == vocabulary[i][a]){ 
			break;
		}else{
			check++;
		//	printf("check %d\n",check);
		}
		if (check == 5){
			free(vocabulary[i]);
			vocabulary[i] = NULL;
			break;
		}
	a++;
	}
  }
  
  //UNUSED(letter);
  //UNUSED(position);
  //UNUSED(vocabulary);
  //UNUSED(num_words);
  printf("finished yellow\n");
  return counter;
}

// This function will filter down the vocabulary based on the knowledge that the
// specified letter *definitely* occurs as the specified position. So remove any
// word that does not contain, for the specified position, the specified letter.
// Returns the number of words that have been filtered from the vocabulary.
size_t filter_vocabulary_green(char letter, int position, char **vocabulary,
                               size_t num_words) {
  // TODO(you): implement this function!
  printf("function green called \n");
  int counter = 0;
  for (size_t i = 0; i < num_words;i++){
	if (vocabulary[i] == NULL){
		continue;
	}
  	if (vocabulary[i][position] != letter){
		free(vocabulary[i]);
		vocabulary[i] = NULL;
		counter++;
	}	
  }
  //UNUSED(letter);
  //UNUSED(position);
  //UNUSED(vocabulary);
  //UNUSED(num_words);
  printf("finished green\n");
  return counter;
}

// Free each of the strings in the vocabulary, as well as the pointer vocabulary
// itself (which points to an array of char *).
void free_vocabulary(char **vocabulary, size_t num_words) {
  printf("free ran");
  for (size_t i = 0; i < num_words; i++) {
    free(vocabulary[i]);
  }
  free(vocabulary);
}
