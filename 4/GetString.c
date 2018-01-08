/*
Student name: Raz Shenkman
Student ID: 311130777
Course exercise group: 01
Exercise name: ex5
*/

#include <stdio.h>
#include <string.h>
#include "GetString.h"
#include <malloc.h>
#include <stdlib.h>  
//program 1
/*
Function name: GetLength
The input: none
the output: none
The function operation: the function gets the length of the future inputted
string from user, creates a pointer to that exact length in the memory
and then gets the string from the user (if the memory allocation is failed,
it prints out error), then the function checks the returned values from
FirstCheck function and if the string is all chars, it checks the value of
SortString (which sorts the string), if the string isn't already sorted- it
prints it out
*/
void GetLength() {
	char *str_ptr;
	int strLength;
	printf("Please enter how many chars to allocate:\n");
	scanf("%d", &strLength);
	str_ptr = (char*)calloc(strLength, sizeof(char));
	//if the memory allocation didn't fail
	if (str_ptr != NULL) {
		printf("Allocated %d chars\n", strLength);
		printf("Please enter string to be sorted:\n");
		scanf("%s", str_ptr);
		//check if the string has any chars that are not letters (except the \n)
		if (FirstCheck(str_ptr,strLength) == 0) {
			return;
		}
		//calls the function to sort the string
		if (SortString(str_ptr) == 0) {
			printf("The string is already sorted\n");
		}
		//if it sorted the string- it prints out the new string 
		else {
			printf("The string after sorting is: %s\n", str_ptr);
		}
		free(str_ptr);
	}
	//if the memory allocation failed
	else {
		printf("Error: Cannot allocate Memory\n");
		return;
	}
}
/*
Function name: SortString
The input: unsortedPtr (the pointer to the unser input)
the output: 0 or 1
The function operation: the function runs on all the a-z letters, checking if the
pointer is equal to the letter (starting from a), and for every small letter
it find, it puts it's value in the spot right after the smaller letter found.
the function switches the values if needed. after that it does the same with
A-Z chars, if the string already came sorted than no values needed to be 
swapped, so return 0, if any values were sorted- return 1.
*/
int SortString(char *unsortedPtr) {
    int index1, spot = 0, switchBinar = 0, strLength = strlen(unsortedPtr);
	char smallLetter = 'a', maxLetter = 'z', temp;
	while (smallLetter <= maxLetter) {
		//for loop over the string pointer indexes (chars)
		for (index1 = 0; index1 < strLength; index1++) {
			//checks if the value is equal to the letter in the loop
			if (unsortedPtr[index1] == smallLetter) {
				if (spot == index1) {
					spot++;
				}
				else {
					//swap values if needed (using temporary char)
					temp = unsortedPtr[index1]; 
					unsortedPtr[index1] = unsortedPtr[spot];
					unsortedPtr[spot] = temp;
					spot++;
					switchBinar = 1;
				}
			}
		}
		smallLetter++;
		//run the loop again for capital letters
		if (smallLetter == 'z') {
			maxLetter = 'Z';
			smallLetter = 'A';
		}
	}
	//if no switches were made- the string was inputted sorted already.
	if (switchBinar == 0) {
		return 0;
	}
	else {
		return 1;
	}
}
/*
Function name: FirstCheck
The input: unsortedPtr (the pointer to the unser input) and it's length
the output: 0 or 1
The function operation: the function checks if the string containes elements
which are not letters, if it's only letters it returns 1, if it's not only
letters it prints out error and return 0
*/
int FirstCheck(char *unsortedPtr, int length) {
	int index;
	//if the char is a letter
	for (index = 0; index < (length - 1); index++) {
		if ((unsortedPtr[index] >= 'A' && unsortedPtr[index] <= 'Z') ||
			(unsortedPtr[index] <= 'z' && unsortedPtr[index] >= 'a')) 
			continue;
		else {
			printf("Error: Illegal input\n");
			free(unsortedPtr);
			return 0;
		}
	}
	return 1;
}