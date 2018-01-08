/*
Student name: Raz Shenkman
Student ID: 311130777
Course exercise group: 01
Exercise name: ex5
*/
//program 3

#include <stdio.h>
#include <string.h>
#include "FindRepeat.h"
#include "SmallestStr.h"
#include <malloc.h>
#include <stdlib.h>  
/*
Function name: GetLenAndStr
The input: none
the output: none
The function operation: the function gets a lengt for the string, allocates 
memory for it and then find how many times it has duplications in it(by using
ShortestStr), then it prints out the sub-string (the smallest part of string
that repeats itself) and it's length.
*/
void GetLenAndStr() {
	int strLength, shortestLen, index = 0;
	char *unSortedStr;
	printf("Please enter how many chars to allocate:\n");
	scanf("%d", &strLength);
	unSortedStr = (char*)malloc(strLength * sizeof(char));
	//if the memory allocation didn't fail
	if (unSortedStr != NULL) {
		printf("Allocated %d chars\n", strLength);
		printf("Please enter your string:\n");
		scanf("%s", unSortedStr);
		//give shortestLen the returned value of ShortestStr function
		shortestLen = ShortestStr(unSortedStr);
		printf("The shortest prefix building the string is: ");
		//print the sub-string(the smallest part of string that repeats itself)
		for (index = 0; index <= shortestLen; index++) {
			printf("%c",unSortedStr[index]);
		}
		//print the length of the sub-string
		printf(" of length %d\n",(shortestLen+1));
		free(unSortedStr);
		return;
	}
	else {
		printf("Error: Cannot allocate Memory\n");
		free(unSortedStr);
		return;
	}
}
/*
Function name: ShortestStr
The input: pointer to the user string
the output: 0 or the shortest length of the sub-string(the self repeating-
smallest part of string which can build the whole string)
The function operation: the function gets the user inputted string and checks
first if the first letter is the sub-string, if it is it returns 0 and if not
it checks whats the smallest sub-string that can build the whole string (using
SubGenerator function), and returns the size of the sub-string.
*/
int ShortestStr(char *unSorted) {
	char *check_ptr, *longer_ptr;
	int newSize = 1, indicator1 = 0, indicator2 = 0, index = 0, index1 = 0, length;
	check_ptr = (char *)malloc(2 * sizeof(char));
	if (check_ptr == NULL) {
		printf("Error: Cannot allocate Memory\n");
		free(unSorted);
		return 0;
	}
	length = strlen(unSorted);
	//check if the first letter is the sub string of the substring
	check_ptr[0] = unSorted[0];
	for (index1 = 0; index1 < (length); index1++) {
		if (check_ptr[0] != unSorted[index1]) {
			indicator1 = 1;
			break;
		}
	}
	// if the first letter is the sub string of the substring return  0
	if (indicator1 == 0) {
		free(check_ptr);
		return 0;
	}
	free(check_ptr);
	//checks whats the smallest sub-string that can build the whole string
	longer_ptr = (char *)calloc(length + 1, sizeof(char));

	while (newSize < length) {
		++newSize;
		if (longer_ptr == NULL) {
			printf("Error: Cannot allocate Memory\n");
			return 0;
		}
		for (index = 0; index < newSize; index++) {
			longer_ptr[index] = unSorted[index];
		}
		indicator2 = SubGenerator(unSorted, longer_ptr);
		if (indicator2 != 0) {
			break;
		}
	} 
	free(longer_ptr);
	//return the size of the smallest substring
	return (newSize-1);
}
