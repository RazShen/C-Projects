/*
Student name: Raz Shenkman
Student ID: 311130777
Course exercise group: 01
Exercise name: ex5
*/
//program 4
#include <stdio.h>
#include <string.h>
#include "ChangeSen.h"
#include <malloc.h>
#include <stdlib.h> 
/*
Function name: GetSentence
The input: none
the output: none
The function operation: the function gets the length of the sentence memory from
the user, then it allocates the memory to the pointer sentence_ptr, if the 
allocation worked it continue- if not print error and return to menu.
after the allocation worked it gets the sentence from the user and gets
the number of the numbers the user want to reverse, than the function calls 
the function ReverseNumWords with those values(sentence, number needed reverse)
*/
void GetSentence() {
	int length, reverseNum;
	char dummy;
	char *sentence_ptr;
	printf("Please enter how many chars to allocate:\n");
	scanf(" %d", &length);
	sentence_ptr = (char*)calloc(length, sizeof(char));
	//if the memory allocation failed
	if (sentence_ptr == NULL) {
		printf("Error: Cannot allocate Memory\n");
		return;
	}
	printf("Allocated %d chars\n", length);
	scanf("%c", &dummy);
	printf("Please enter your string:\n");
	//gets the sentence input from user
	fgets(sentence_ptr, length, stdin);
	printf("Please enter how many words to reverse:\n");
	scanf("%d", &reverseNum);
	ReverseNumWords(sentence_ptr, reverseNum);
	return;
}
/*
Function name: ReverseNumWords
The input: pointer to the sentence, number of wanted reverse words
the output: none
The function operation: the function finds how many words there are by calling
the function CheckSpace (if there's 1 word and the user's reverse number is 1 it
just print the word and if the number is bigger then the number of words- print
out error). then it creates a pointer to pointers word_ptr, and calls the function
BreakAndSwitch (it changes the pointers value). after that it prints out the
words with their new order.
*/
void ReverseNumWords(char *sentence_ptr, int reverseNum) {
	int words, index = 0;
	char **words_ptr;
	//calls the function to check how many words there are in the string
	words = CheckSpace(sentence_ptr, reverseNum);
	//if there is only 1 word it's being printed in CheckSpace function
	if (words == 0) {
		free(sentence_ptr);
		return;
	}
	words_ptr = (char **)calloc((strlen(sentence_ptr) + 1), sizeof(char*));
	//if the memory allocation failed
	if (words_ptr == NULL || words_ptr == 0) {
		printf("Error: Cannot allocate Memory\n");
		free(sentence_ptr);
		return;
	}
	words_ptr = BreakAndSwitch(words_ptr, sentence_ptr, reverseNum);
	//print out the pointers value by their new order
	printf("The string after reverse is: ");
	for (index = 0; index < words; index++) {
		printf("%s ", words_ptr[index]);
	}
	printf("\n");
	//free all the used memory
	for (index = 0; index <= words; index++) {
		free(words_ptr[index]);
	}
	free(words_ptr);
	free(sentence_ptr);
}
/*
Function name: BreakAndSwitch
The input: pointer to pointers words_ptr, pointer to the sentence, 
 number of wanted reverse words
the output: none
The function operation: the function creates a temporary poiner which will get 
the string words by strtok and give each pointer in the words_ptr a value of
word by order. then word are being switched by the value of user's reversed
numbers.
*/
char** BreakAndSwitch(char **words_ptr, char *sentence_ptr, int reverse) {
	char *brokenSentence_ptr, *tmp_ptr;
	int index1 = 0, index2 = 0, tmpLength, newLength;
	brokenSentence_ptr = strtok(sentence_ptr, " ");
	//brokenSentence_ptr will be NULL in the end of the sentence
	while (brokenSentence_ptr != NULL) {
		words_ptr[index1] = (char *)calloc(60, sizeof(char));
		//if memory allocation failed
		if (words_ptr[index1] == NULL) {
			printf("Error: Cannot allocate Memory\n");
			for (index2 = 0; index2 < index1; index2++) {
				free(words_ptr[index1]);
			}
			free(sentence_ptr);
			return 0;
		}
		//give each pointer in words_ptr a value of a word
		strcpy(words_ptr[index1], brokenSentence_ptr);
		brokenSentence_ptr = strtok(NULL, " \n");
		newLength = strlen(words_ptr[index1]);
		words_ptr[index1] = (char *)realloc(words_ptr[index1], 
			(newLength + 1) * sizeof(char));
		if (words_ptr[index1] == NULL) {
			printf("Error: Cannot allocate Memory\n");
			for (index2 = 0; index2 < index1; index2++) {
				free(words_ptr[index1]);
			}
			free(sentence_ptr);
			return 0;
		}
		index1++;	
	}
	index2 = reverse - 1;
	//switch values loop (by the user wanted reversed number)
	for (index1 = 0; index1 < index2; index1++, index2--) {
		//swich values 
		tmpLength = strlen(words_ptr[index1 ]) + 1;
		tmp_ptr = (char *)malloc(tmpLength * sizeof(char));
		//if memory allocation failed
		if (tmp_ptr == NULL) {
			printf("Error: Cannot allocate Memory\n");
			for (index2 = 0; index2 < index1; index2++) {
				free(words_ptr[index1]);
			}
			free(sentence_ptr);
			return 0;
		}
		strcpy(tmp_ptr, words_ptr[index1]);
		words_ptr[index1] = (char *)realloc(words_ptr[index1],
			(strlen(words_ptr[index2]) + 1) * sizeof(char));
		if (words_ptr[index1] == NULL) {
			printf("Error: Cannot allocate Memory\n");
			for (index2 = 0; index2 < index1; index2++) {
				free(words_ptr[index1]);
			}
			free(sentence_ptr);
			free(tmp_ptr);
			return 0;
		}
		strcpy(words_ptr[index1], words_ptr[index2]);
		words_ptr[index2] = (char *)realloc(words_ptr[index2],
			(strlen(tmp_ptr) + 1) * sizeof(char));
		if (words_ptr[index2] == NULL) {
			printf("Error: Cannot allocate Memory\n");
			for (index2 = 0; index2 < index1; index2++) {
				free(words_ptr[index1]);
			}
			free(sentence_ptr);
			free(tmp_ptr);
			return 0;
		}
		strcpy(words_ptr[index2], tmp_ptr);
		free(tmp_ptr);
		}
	return words_ptr;
	}
/*
Function name: CheckSpace
The input: pointer to pointers words_ptr, pointer to the sentence,
number of words number of wanted reverse words
the output: 0 or the number of words
The function operation: the function checks the number of words in the sentence
by checking how many spaces in it, if there's only 1 word and the user input
for reversed number is 1- then it just print out the word. if wanted reverse 
number is greated than the number of word it print error. otherwise it returns
the number of words.
*/
int CheckSpace(char *sentence_ptr, int reverseNum) {
	int count = 0, index = 0;
	char space = ' ';
	//check how many spaces in the sentence
	for (index = 0; index <(const) strlen(sentence_ptr); index++) {
		if (sentence_ptr[index] == space) {
			count++;
		}
	}
	//if there's 1 word and user wanted reverse number is 1- print the string
	if (count == 0) {
		if (reverseNum == 1) {
			printf("The string after reverse is: ");
			printf("%s", sentence_ptr);
			return 0;
		}
	}
	//if only 1 word to reverse
	if (reverseNum == 1) {
		printf("The string after reverse is: ");
		printf("%s", sentence_ptr);
		return 0;
	}
	//if wanted reverse number is greated than the number of word
	if ((count + 1) < reverseNum ) {
		printf("Error: Illegal Input\n");
		return 0;
	}
	//returns the number of words
	return (count+1);
}
