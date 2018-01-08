/*
Student name: Raz Shenkman
Student ID: 311130777
Course exercise group: 01
Exercise name: ex5
*/
//program 2
#include <stdio.h>
#include <string.h>
#include "GetString.h"
#include <malloc.h>
#include <stdlib.h>  
/*
Function name: GetLengths
The input: none
the output: none
The function operation: the function get the lengths of the 2 strings (firstLen
and secondLen) then it creates places in memory for the strings, and if it
successfuly created the memory it prints out the result of the function 
SubGenerator, if the result isn't 0- means they devide so it print out the 
wanted answer. if the result is 0 it prints out "No concatenation found"
if it didn't successfuly create memory then print out error.
*/
void GetLengths() {
	int firstLen = 0, secondLen = 0, result = 0;
	char *firstString_ptr;
	char *secondString_ptr;
	printf("Please enter how many chars to allocate to the two strings:\n");
	scanf(" %d %d", &firstLen, &secondLen);
	firstString_ptr = (char*)calloc(1, firstLen);
	//if didn't successfuly allocate memory 
	if (firstString_ptr == NULL) {
		printf("Error: Cannot allocate Memory\n");
		return;
	}
	secondString_ptr = (char*)calloc(1, secondLen);
	//if successfuly allocate memory 
	if (firstString_ptr != NULL && secondString_ptr != NULL) {
		printf("Allocated %d chars and %d chars\n", firstLen, secondLen);
		printf("Please enter two arrays of chars:\n");
		scanf(" %s %s", firstString_ptr, secondString_ptr);
		//result is the number of times smaller string is in the bigger string
		result = SubGenerator(firstString_ptr,secondString_ptr);
		if (result == 0) {
			printf("No concatenation found\n");
			free(firstString_ptr);
			free(secondString_ptr);
			return;
		}
		//if result isn't 0
		else {
			printf("%s is a concatenation of %s %d times\n", firstString_ptr,
			secondString_ptr, result);
			free(firstString_ptr);
			free(secondString_ptr);
			return;
		}
	}
	//if didn't successfuly allocate memory 
	else {
		printf("Error: Cannot allocate Memory\n");
		free(firstString_ptr);
		return;
	}
}
/*
Function name: SubGenerator
The input: pointers to the first string and the second string
the output: if they don't devide- return 0, if they devide return the
result of the devision
The function operation: the function checks if the length of the first string
can be devided by the length of the second string- if not- return 0.
if they do devide it checks if the first char of the smaller string equals
to the position of where it should be in the bigger string. if it didn't find
a match- return 0;
*/
int SubGenerator(char *first_ptr, char *sec_ptr) {
	int firLen, secLen;
	int tmp = 0, current = 0, devide = 0, index1 = 0, duplicate = 0;
	//get the lengths of the strings
	firLen = strlen(first_ptr) ;
	secLen = strlen(sec_ptr);
	//check if the first string can be devided by the second string
	devide = (firLen) % (secLen);
	if (devide != 0) {
		return 0;
	}
	else {
		while (tmp < ((firLen) / (secLen))) {
			for (index1 = 0; index1 < (secLen); index1++) {
				/*checks if the char in the smaller string is equal to the char
				in the same position + the divide result in the bigger string
				*/
				if (sec_ptr[index1] != first_ptr[index1 + ((secLen)*tmp)]){
					return 0;
				}
			}
			duplicate++;
			tmp++;
		}
	}
	//return the number of times the bigger string contain only the smaller string 
	return duplicate;
}