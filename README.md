# Palindrome
---

palindrome is used to determine whether a file populated with words contains any palindromes. A word is described as a string of visible ascii characters terminated with a space or new line character.

- the program will only print out full length palindromes. Example, if abxba is present in a string it will print abxba and not print bxb
- a the program will ignore duplicates, printing out the positioning of the first occurence of a palindrome
- a palindrome is CASE SENSITIVE string that reads the same as when reversed, a single character is not a palindrome
-	a word is seperated by a number of spaces or new lines in the file given as input. Given this, a sentence can not be determined to be a palindrome
- the program is intended for use with visible ascii character

## Getting Started
---
download the files contained; palin.cpp, and test.txt

the test file is just for simple testing, and to show that no formatting of the input file other than words being seperated is needed

to compile (c++ 11 required), in directory where palin.cpp exists

```
g++ palin.cpp -o palin
```

to run, in directory where palin.exe and test.txt exist 
```
./palin test.txt
```

