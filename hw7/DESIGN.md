add: using the code given to us by the professor in class I will be taking the inputs given by the user by using scanf or some
other way and assigning whatever information given to its respective variable in the hash structs while also allocating the
correct amount of memory to store the information. if the input entered is already present in the hash table then I will 
probably free all of the information in the hash table before hand and replace all the data with the new information entered.
 If I am reading from a file I will be sure to slice everything where there are tabs so each bit of information is properly
assigned to each struct variable. If there is a random tab inside the entered text then I will prompt an error message and
prompt them again with the information they were trying to input.

lookup: following the code that was done in class, I will read from the users input and find the corresponding bucket in which the email address is
located so that all of the information can be shown. I will do this by doing the hash(email) % table->num_buckets in order to find out which bucket
the email is located in. Then I will make sure that the information found in that bucket is the same as the information the user wants to lookup by comparing the email addresses and if they are the same then return the info from that bucket. To display the information I will record which bucket the info is in and print out the email, name, shoe size, and favorite food according to the info recorded in the bucket.

delete: I will go find whichever bucket is holding the information the user wants to delete and then free everything from that bucket. if the info
isn't found then i will just say its not been found and prompt the command again.

list: will probably try to print out each bucket and all of its information in list format by going through each email address inputed into the
table and then printing all the info before moving onto the next.

save: will try to read through everything in the file and go until what is in the hash table doesn't match what is in the file, then will write 
using file write all of the information stored in the hash in a line in the file separated by tabs.

quit: I believe that this is freeing everything before quitting. since the information should be stored in the file if the user chose to save
(or not) then I will free all linked lists and arrays from the buckets and hash table so that no memory leaks. then print a goodbye message and exit the program.
