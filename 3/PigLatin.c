/*
Student name: Raz Shenkman
Student ID: 311130777
Course exercise group: 01
Exercise name: ex4c
*/
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "PigLatin.h"

/*
Function name: PigLatin
The input: none
the output: none
The function operation: the operation runs the do while loop to get the sentence
from the user unless the value of IfTranslate function is 0 (according to the
user input in that function), the function gets a sentence, use toLower function
on it and than uses BreakSentence function on it.
*/
void PigLatin() {
	char sentence[LENGTH], dummy[LENGTH];
	do {
		printf("Please enter a sentence in English:\n");
		fgets(dummy, LENGTH, stdin);
		fgets(sentence, LENGTH, stdin);
		toLower(sentence);
		BreakSentence(sentence);
	} while (IfTranslate()!= 0);
	return;
}
/*
Function name: IfTranslate
The input: none
the output: return 0 or 1, according to the user's input
The function operation: the function asks the user if he wants to translate 
another sentence, if yes- it returns 1 which makes the do while loop in PigLatin
function continue, if no it returns 0 and makes it stop.
*/
int IfTranslate() {
	char yesOrNo;
	printf("Do you want to translate another sentence?(y/n)\n");
	scanf("%c", &yesOrNo);
	if (yesOrNo == 'n') {
		return 0;
	}
	else {
		return 1;
	}
}
/*
Function name: toLower
The input: char input[] (the user sentence from PigLatin function)
the output: none
The function operation: the function takes the input, then it changes it's
char value one by one in the array to be a lower case char.
*/
void toLower(char input[]) {
	int index;
	for (index = 0; input[index]; index++) {
		input[index] = tolower(input[index]);
	}
}
/*
Function name: BreakSentence
The input: char input[] (the user sentence from PigLatin function)
the output: none
The function operation: the function takes the input, then it breaks it into
words according to key values and run 'LetterAdd' function on every word.
after that function worked it prints the new edited user's input
*/
void BreakSentence(char input[]) {
	char *brokenSentence, singleWord[MAXCHAR];
	//breaks the sentence by the key values 'space' 'tab' 'new line'
	brokenSentence = strtok(input, " \t\n");
	/*changes singleWord value to be the value of brokenSentence (pointer of
	the strtok function on the user's input), then it uses the function 
	LetterAdd and after that function worked it prints out the value of the
	new edited input/
	*/
	while (brokenSentence != NULL) {
		strcpy(singleWord, brokenSentence);
		brokenSentence = strtok(NULL, " \t\n");
		LetterAdd(singleWord);
		printf("%s ", singleWord);
	}
	printf("\n");
}
/*
Function name: LetterAdd
The input: char input[] (the user sentence from PigLatin function)
the output: none
The function operation: the function takes the input,check if it's first letter 
starts with 'AEIOU' if yes, it just add "way" to the end of the word. if
not it will check if the first letter doesn't start with 'AEIOU' (in case
it's a 'y') then it will start MoveLetter function and add 'ay' in the end of the
string and print it
*/
void LetterAdd(char input[]) {
	char AEIOU[6] = {'a','e','i','o','u','\0'};
	int index = 0, reCheckWord = 0, letterIndex = 0;
	for (index; index < 6; index++) {
		if (input[0] == AEIOU[index]) {
			strcat(input, "way");
			reCheckWord = 2;
		}
	}

	if (reCheckWord == 0) {
		for (letterIndex = 0; letterIndex<6; letterIndex++) {
			if (input[0] != AEIOU[letterIndex]) {
				MoveLetter(input);
				break;
			}
		}
		WordChanger(input);
		strcat(input, "ay");
	}
}
/*
Function name: WordChanger
The input: char input[] (the user sentence from PigLatin function)
the output: none
The function operation:the function takes a letter, checks if it starts with 
'AEIOUY' in a loop and if it doesn't start with 'AEIOUY' then it start
LetterAdd function
*/
void WordChanger(char input[]) {
	char AEIOUY[8] = { 'a','e','i','o','u','y','\0'};
	int indexLetter = 0, indexMove = 0;
	while (input[0] != AEIOUY[0] && input[0] != AEIOUY[1] && input[0] != AEIOUY[2]
		&& input[0] != AEIOUY[3] && input[0] != AEIOUY[4] && input[0] != AEIOUY[5])
		MoveLetter(input);
}
/*
Function name: MoveLetter
The input: char input[] (the user sentence from PigLatin function)
the output: none
The function operation: the function takes the input, and moves the second letter
to the end of the loop, then it puts the first letter in the end of the loop.
*/
void MoveLetter(char input[]) {
	char firstLetter = input[0];
	int length = strlen(input);
	//moves the second letter to the first letter (memmove from string.h library
	memmove(input, input+ 1, length - 1);
	//moves the firstLetter to the end of the word
	input[length-1] = firstLetter;
}

