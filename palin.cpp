/**
 * palin.cpp
 *
 * to compile:
 *		g++ palin.cpp -o palin
 *
 * to run(where test.txt is an input file):
 * 		./palin test.txt
 *
 * Purpose:
 *		print out the palindromes contained within a string
 * 
 * notes:
 * 		the program will only print out full length palindromes. Example, if abxba is present 
 * 		in a string it will print abxba and not print bxb
 * 
 * 		the program will ignore duplicates, printing out the positioning of the first 
 *		occurence of a palindrome
 * 
 * 		a palindrome is case sensitive, a single character is not a palindrome
 *
 * @author Matthew Wojcik
 * @version 1 2019-05-06
 */

// for io
#include <iostream>
// for vectors
#include <vector>
// for strings
#include <string.h>
// for reversing a string
#include <algorithm>
// for building a tuple
#include <tuple>
// for reading "words" from file
#include <bits/stdc++.h> 

using namespace std;

/**
 * check if a string is a palindrome
 *
 * @param str String which may be a palindrome
 * @return Boolean, true if str is a palindrome, false otherwise
 */
bool ispal (string str) {
	long length = str.length();
	string reverse;

	reverse.assign(str.rbegin(),str.rend());

	for (int index = 0;index < length; index++) {
		if (str[index] != reverse[index]) return false;
	}
	return true;
}

/**
 * get all palindromes from a string
 * -includes sub-palindromes. Example, sabxba contains abxba and bxb
 *
 * @param str String which may have palindromes in it
 * @return Vector of palindrome tulpes (the palindrome, the palindromes starting position in str, length of the palindrome)
 *        the vector is empty if there are no palindromes, a single character is not a palindrome
 */
vector <tuple<string,long,long>> palindromes (string str) {
	long length = str.length();
	vector <tuple<string,long,long>> substrings;
	if (length < 2) return substrings;
	// retrieve all the substrings of the string input
	//i will be the length of the substring
	for (long i = length;i >= 2;--i) {
		// j will be the starting point of the substring
		for (long j = 0;j <= length-i;j++) {
			substrings.push_back(tuple<string,long,long>(str.substr(j,i),j,i));
		}
	}
	return substrings;	
}

/**
 * main method, reads a file and prints all of the palindromes contained
 * in every word in the file, treats words individually
 *
 * @param  argc Integer argument count of the command line arguments
 * @param  argv Argument vector of the command line arguments
 * @return an integer 0 upon exit success, -1 on bad input or failure
 */
int main (int argc, char *argv[]) {
	vector <tuple<string,long,long>> substrings;
	string word;
	fstream pFile;

	if (argc != 2) return -1;
	pFile.open(argv[1]);
	if(!pFile) return -1;

	// for each "word" in the file
	while (pFile >> word){
		cout << "Input:" << endl << "\t" << word << endl << endl;
		cout << "Result:" << endl;
		substrings = palindromes(word);

		//vector to keep track of seen palindromes, as well as their sub-palindromes
		vector<string> usedPalindromes;

		// print out the palindtromes, their starting point, their length
		for (auto& tuple : substrings) {
			if (ispal(get<0>(tuple))) {
				// check if you've seen the palindrome
				if (find(usedPalindromes.begin(),usedPalindromes.end(),get<0>(tuple)) == usedPalindromes.end()) {
					cout << "\t" << get<0>(tuple) << ", " << get<1>(tuple) << ", " << get<2>(tuple) << endl;
					// 	say you've seen the palindrome
					for (auto& subPalindrome : palindromes(get<0>(tuple))){
						usedPalindromes.push_back(get<0>(subPalindrome));
					}
				}
			}
		}
		cout << endl;
	}
	return 0;
}