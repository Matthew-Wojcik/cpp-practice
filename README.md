# Palindrome
---

palindrome is used to determine whether a file populated with strings contains any palindromes.

 *    the program will only print out full length palindromes. Example, if abxba is present 
 * 		in a string it will print abxba and not print bxb
 * 		the program will ignore duplicates, printing out the positioning of the first 
 *		occurence of a palindrome
 * 
 * 		a palindrome is case sensitive, a single character is not a palindrome
 * 
 *		a word is seperated by a number of spaces or new lines in the file given as input

## Getting Started
---
download the files contained; palin.cpp, and test.txt

to compile (c++ 11 required), in directory where palin.cpp exists

```
g++ palin.cpp -o palin
```

to run, in directory where palin.exe and test.txt exist 
```
./palin test.txt
```

