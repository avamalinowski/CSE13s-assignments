score guess: will probably make this multiple steps and compare the players guess with the actual word by using strcmp.
first I will check to see if each letter in the guess is identical to the word. probably using two for loops at a time where
one is checking to see if the letter at the time is in the word at all, and then another to check and see if the letter at the
time is equal to the current letter being checked in secret. will have to figure out how to make sure that y does not override
g, but will so strcat to result for each letter in guess checked and ideally this will be the correct output.

valid guess: will probably also use something similar to strcmp to check if the full word player guessed is in vocabulary.
since they're all lowercase it should return as a proper 0, if that happens ill check to make sure it returned 0 and then reture true, and if its not 0 after running through all words then return false. so outside of for loop will return false bc that 
means it never was 0/true.

load vocabulary: will probably iterate through the file and check to see when theres a \n character and assign everything
before that into an index of the array. for each word it will allocate memory equal to the size of it using realloc. open the
file with fopen, strdup to copy text, and fclose to close it at the end of the function.

free vocabulary: i think it'll just be a for loop running through num words and freeing each index of vocabulary. :)
