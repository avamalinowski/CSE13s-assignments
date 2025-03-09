append text: using strdup i will copy the text from the input and set that as a variable that i will pass into the function
where I will first allocate memory the size of the text and then create a new node where I'll put the text into and add to the end of the linked list.

insert text: will probably first have to append a new node to the end of the list and move the current information at the
place text will be inserted into into the new node, then insert the new information into the node that was just emptied.

delete text: will delete information at a specific index point by finding the NULL value of the node before and have that point to the value of the node after the deleted node. then will free the memory contained in the deleted list.

replace text: will take the string currently held in the node, free it, then retype what you want the value to be and use strdup to place the new string into the node. 

duplicate ll text: will make a new linked list struct in order to copy everything from the given linked list into the new stuff. Also allocating memory the size of all the information currently stored in the linked list

ll text length: use and iterative function to see how many nodes are in the list and also keep track of a counter to return a number.

push duplicate: allocate memory and create a stack that will push the copy of the ll_text to the top of this stack.

push empty: pushes an empty entry (either null or some other way to signify emptiness) into our stack

pop stack: deletes the top entry of the stack while also freeing the space it took up.
