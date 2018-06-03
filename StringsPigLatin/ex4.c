/*
Student name: Raz Shenkman
Student ID: 311130777
Course exercise group: 01
Exercise name: ex4c
*/
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "calculate.h"
#include "PigLatin.h"

int main() {
	int menuIndex;
	char userInput[20];	
	char quit[5] = "quit";
	char calculator[11] = "calculator";
	char translator[11] = "translator";
	//the menu do while-loop, if the input isn't equal to "quit"
	do {
		printf("Main menu, choose between the options:\n");
		printf("Matrix Calculator\nPigLatin Translator\n");
		scanf("%s", userInput);
		//for loop for each letter in the input, make it a lower case letter
		for (menuIndex = 0; userInput[menuIndex]; menuIndex++) {
			userInput[menuIndex] = tolower(userInput[menuIndex]);
		}
		//compare the user's input to calculator option
		if (strcmp(userInput, calculator) == 0) {
			calculate();
		}
		//compare the user's input to translator option
		else if (strcmp(userInput, translator) == 0) {
			PigLatin();
		}
		//if the user typed in something else else
		else  {
			if (strcmp(userInput, quit) != 0) {
				printf("This was not an option.\n");
			}
		}
		//while the user doesn't input 'quit'
	} while (strcmp(userInput,quit) != 0);
	return 0;
}

