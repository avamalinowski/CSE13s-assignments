score letter: do a for loop comparing letter with the specific index letter of each word in vocabulary. If it's in the word then plus 1 to a counter, else skip.

score word: for each letter in word, ill check to see what the letter score is for that letter and then add it to a 
running total variable. I will keep a variable that is the previous letter and then a variable that is the new letter 
and then compare them before adding. if the previous letter is the same as the new letter then skip the letter and 
continue to the next. (updated: looped through the word once and added the first letter score to a running total, then
strcat that letter to another variable where i will then loop over the new variable and the current letter to see if the current letter is in the new variable, if it is then skip and dont add to total.)

filter vocabulary gray: loop through each of the words and check to see if the gray letter is in the word. if it is then set vocabulary[i] to null and then free it. then continue on.

filter vocabulary yellow: do something similar to gray except if it's in the position that it was originally guessed,
then get rid of it.

filter vocabulary green: check to see if the green letter is in the position it was guessed in the word, if it is keep the word,otherwise get rid of it.

free vocabulary: for each word left in vocabulary, free that index, then free the entire vocabulary.
