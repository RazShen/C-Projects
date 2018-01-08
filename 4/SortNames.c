/*
Student name: Raz Shenkman
Student ID: 311130777
Course exercise group: 01
Exercise name: ex5
*/
//program 5
#include <stdio.h>
#include <string.h>
#include "SortNames.h"
#include <malloc.h>
#include <stdlib.h>  
/*
Function name: GetNames
The input: none
the output: none
The function operation: the function gets the list of names from the user
(using the function GetWord in the do while loop), allocating memory for
each pointer in names_ptr(pointer to pointers) for size (reallocating later
if needed) and increases the size of names_ptr by 1, after allocated all the
names sends the pointer of pointers to SortWords
*/
void GetNames() {
	int index = 0, index3, sizeStr = 0, indicator = 0;
	char **names_ptr, dummy;
	printf("Please enter list of names:\n");
	//creates pointer to pointers with size for 1 pointer
	names_ptr = (char **)malloc(sizeof(char*));
	if (names_ptr == NULL) {
		printf("Error: Cannot allocate Memory\n");
		return;
	}
	scanf("%c", &dummy);
	 do {
		 //allocating memory for the pointer (of the future inputted word)
		names_ptr[index] = (char *)calloc(11, sizeof(char));
		//if allocation failed
		if (names_ptr[index] == NULL) {
			printf("Error: Cannot allocate Memory\n");
			for (index3 = 0; index3 < index; index3++) {
				free(names_ptr[index3]);
			}
			free(names_ptr);
			return;
		}
		//sents pointer to GetWord function
		names_ptr[index] = GetWord(names_ptr[index]);
		index++;
		//increase pointer to pointers size(by 1 each loop)
		names_ptr = (char **)realloc(names_ptr, (index+1) * sizeof(char*));
		//if allocation failed
		if (names_ptr == NULL) {
			printf("Error: Cannot allocate Memory\n");
			for (index3 = 0; index3 < index; index3++) {
				free(names_ptr[index3]);
			}
			free(names_ptr);
			return;
		}
		//stops looping if word is QUIT
	 } while (strcmp(names_ptr[index-1],"QUIT")!=0);
	 //sends all the words but 'QUIT' to the SortNames function
	 SortNames(names_ptr,(index-1));
}
/*
Function name: GetWord
The input: pointer to a word
the output: pointer to a word
The function operation: the function scans the user input and checks if the
last letter of the pointer to the scanned word is \n (if it is it means that
the whole word scanned successfuly) if not, creates a new pointer which
get whats left of the user input (from the buffer) and use strcat to add the
new pointer letters to the original pointer (then loop over again).
once the whole word is in the pointer- realloc the pointer to the minimum size.
*/
char* GetWord(char *word) { 
	int length = 10, index, indicator=0;
	char *tmp_ptr;
	//get the input to the pointer of the word
	fgets(word, 10, stdin);
	do {
		//if the whole input is in the pointer successfuly
		for (index = 0; index < length; index++) {
			if (word[index] == '\n') {
				word[index] = '\0';
				indicator = 1;
			}
		}
		if (indicator != 1) {
			//creates new pointer (if not the whole input is in the pointer)
			tmp_ptr = (char *)calloc(10, sizeof(char));
			//if allocation failed
			if (tmp_ptr == NULL) {
				printf("Error: Cannot allocate Memory\n");
				free(word);
				return 0;
			}
			length = strlen(word);
			//making the size of the original word pointer bigger
			word = (char *)realloc(word, (length+10) * sizeof(char));
			//if allocation failed
			if (word == NULL) {
				printf("Error: Cannot allocate Memory\n");
				free(tmp_ptr);
				return 0;
			}
			fgets(tmp_ptr, 10, stdin);
			//copy the temporary pointer to the original word pointer
			strcat(word, tmp_ptr);
			free(tmp_ptr);
			length = strlen(word);
			indicator = 0;
		}
	} while (indicator == 0);
	length = strlen(word);
	//minimizing word's pointer size to the minimum
	word = (char *)realloc(word, (length+1) * sizeof(char));
	//if allocation failed
	if (word == NULL) {
		printf("Error: Cannot allocate Memory\n");
		free(tmp_ptr);
		return 0;
	}
	return word;
}
/*
Function name: SortNames
The input: pointer to the pointers of the words, number of words
the output: none
The function operation: the function run through the pointer of pointers (runs
"words" times (if there are 3 words- it will run 3 times)- so all the words 
will be sorted if one is alphabettically larger than the next one.
*/
void SortNames(char** names_ptr, int words) {
	int index, index2, indicator = 0;
	for (index2 = 0; index2<words; index2++){
		for (index = 0; index < (words-1); index++) {
			//if the word is alphabettically larger than the next word
			if (strcmp(names_ptr[index], names_ptr[index + 1]) > 0) {
				names_ptr = FastSwap(names_ptr, index);
			}
		}
	}
	printf("There are %d names:\n", words);
	for (index = 0; index < words; index++) {
		//print out all the names, not repeating themself and not equal to QUIT
		if ((strcmp(names_ptr[index], names_ptr[index + 1]) != 0) 
			&& (strcmp(names_ptr[index], "QUIT") != 0)) {
			printf("%s\n", names_ptr[index]);
		}
	}
	//free the allocated memory
	for(index = 0 ; index <= words; index++) {
		free(names_ptr[index]);
	}
	free(names_ptr);
	return;
}
/*
Function name: FastSwap
The input: pointer to the pointers of the words,index of the current word 
the output: pointer to the pointers of the words
The function operation: the function gets the place of the the needed to be
swapped pointer, creates a temporary pointer and use strcpy to switch between 
the pointer and the next pointer. using realloc to adjust the pointer's size
according to the word
*/
char** FastSwap(char **names_ptr,int index) {
	int tmpLength, index3;
	char *tmp_ptr;
	//creates a temporary pointer
	tmpLength = strlen(names_ptr[index + 1]) + 1;
	tmp_ptr = (char *)malloc(tmpLength * sizeof(char));
	//if allocation failed
	if (names_ptr == NULL) {
		printf("Error: Cannot allocate Memory\n");
		for (index3 = 0; index3 < index; index3++) {
			free(names_ptr[index3]);
		}
		free(names_ptr);
		return 0;
	}
	//assign next word to the pointer 
	strcpy(tmp_ptr, names_ptr[index + 1]);
	//realloc the next word according to the previous word
	names_ptr[index + 1] = (char *)realloc(names_ptr[index + 1],
		(strlen(names_ptr[index]) + 1) * sizeof(char));
	//if allocation failed
	if (names_ptr == NULL) {
		printf("Error: Cannot allocate Memory\n");
		for (index3 = 0; index3 < index; index3++) {
			free(names_ptr[index3]);
		}
		free(names_ptr);
		free(tmp_ptr);
		return 0;
	}
	strcpy(names_ptr[index + 1], names_ptr[index]);
	//realloc the previous word according to the next word
	names_ptr[index] = (char *)realloc(names_ptr[index],
		(strlen(tmp_ptr) + 1) * sizeof(char));
	//if allocation failed
	if (names_ptr == NULL) {
		printf("Error: Cannot allocate Memory\n");
		for (index3 = 0; index3 < index; index3++) {
			free(names_ptr[index3]);
		}
		free(names_ptr);
		free(tmp_ptr);
		return 0;
	}
	strcpy(names_ptr[index], tmp_ptr);
	free(tmp_ptr);
	return names_ptr;
}