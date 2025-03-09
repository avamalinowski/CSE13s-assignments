Computing the next Collatz number: For this function I would do as the definition says and check to see whether the number is even or odd by dividing the number by 2 and if the remainder is 0 then return the number outputted. else, if the remainder is not 0 then do 3n + 1 and return that number.

Counting Collatz steps to convergence: ill create a while loop that checks to see when the number is == 1 and when it's equal to 1 the loop will break and print how many times it went through the loop. To print this i will have a variable counting up
every time the number goes through the loop. Furthermore, I will be applying the Collatz n/2 or 3n+1 to determine whether the number is even or odd. The while loop will have nested if statements. the return value will be how many times the number 
looped.

Finding the maximum element of an array: my first maximum number will be arr[0] and after that I will do a comparison condition statement to see if arr[i] > arr[0]. if it is then I will change my highestnumber variable to be equal to that index of the array. to make sure i know the size of the array I will try to use sizeof and figure it out as I go :D

summing all positive elements of an array: I will traverse my way through the array and test each number to check if its > 0, if it is then I will add it to a running total variable, if its not I will continue through the function, and at the end of the array I will return that variable as the sum of all positive elements in the array.

counting negative numbers in an array: for this function I will traverse my way through the array and check to see if
arr[i] < 0, if it is then I will add 1 to a counter variable, if arr[i] is not < 0 then I will skip and continue. At the end of the array I will return the counter variable to tell how many negative numbers there were in the array.

Calculator program: I will make sure to use the switch function to jump to the correct operator symbol in order to add,subtract,divide,multiply the numbers. I will use getchar() to detect the numbers and set two variables == to the first and second number and delete the \n to not break the program. Then I will use switch to detect operators and then perform the operations. for equations longer than num + num (etc) I will record a result variable to keep and keep adding (or whatever) when new numbers come in. At the beginning of the program I will make result = 0 and do result = num1 + num2 + result (or whatever operators)(unless making result = 0 at the beginning breaks the multiplication or division operators then I will figure something out) If that doesn't work I may just establish result and then do result = num1 + num2 + result so nothing is in result to begin with so nothing breaks. I will figure it out :D 
