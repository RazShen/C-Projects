/*
Student name: Raz Shenkman
Student ID: 311130777
Course exercise group: 01
Exercise name: ex5
*/
#include <stdio.h>
#include "GetString.h"
#include "FindRepeat.h"
#include "SmallestStr.h"
#include "ChangeSen.h"
#include "SortNames.h"
#include "LinkedList.h"
//main - do while loop to get user's input and operate the matching function
int main() {
	int input;
	enum Select {Quit, SortStr, Repeat,SmallStr, Change,Names, Linkedlist};
	do {
		printf("Please enter your input:\n");
		scanf("%d", &input);
		switch (input) {
		case Quit:
			break;
		case SortStr:
			//program 1
			GetLength();
			break;
		case Repeat:
			//program 2
			GetLengths();
			break;
		case SmallStr:
			//program 3
			GetLenAndStr();
			break;
		case Change:
			//program 4
			GetSentence();
			break;
		case Names:
			//program 5
			GetNames();
			break;
		case Linkedlist:
			//program 6
			MainMenu();
			break;
		default:
			printf("Error: Illegal input\n");
			break;
		}
		//if the input is 0
	} while (input != 0);
	return 0;
}