/*
Student name: Raz Shenkman
Student ID: 311130777
Course exercise group: 01
Exercise name: ex5
*/

#include <stdio.h>
#include <string.h>
#include "LinkedList.h"
#include <malloc.h>
#include <stdlib.h>  
//program 6
//created a global variable to track and change the number of pointers from
//all the functions
int ptrCount = 0;
/*
Function name: MainMenu
The input: none
the output: 0 or none
The function operation: this is the main function of the program, managed by
a switch-case in a do-while loop to choose the correct function by user input.
the MainMenu function creates a pointer to pointer linkedChain_ptr which
will point to the pointers of int (Added by user).
*/
int MainMenu() {
	static indicator = 0;
	int input, index;
	//creates pointer to pointers
	int **linkedChain_ptr  = (int**)calloc(0, sizeof(int*));
	if (linkedChain_ptr == NULL) {
		printf("Error: Insufficient Memory\n");
		return 0;
	}
	enum Select {Quit, Add, Remove, PrCur, PrMax, PrMin, PrIndex, Clear, Menu};
	input = PrintMenu();
	do {
		//print the menu if user inputted 8
		if (input == 8) {
			input = PrintMenu();
		}
		switch (input) {
		case Quit:
			//choice 0- clear memory and quit the function 
			if (ptrCount != -1) {
				//clear memory
				for (index = 1; index <= ptrCount; index++) {
					free(linkedChain_ptr[index]);
				}
				free(linkedChain_ptr);
			}
			return 0;
			//choice 1- add a pointer
		case Add:
			/*static int indicator- (so it won't create a new list of pointer
			each time)*/
			if (indicator != 1) {
				indicator = 1;
			}
			if (ptrCount == -1) {
				//if the user clear queue- create new list of pointers
				linkedChain_ptr = (int**)calloc(0, sizeof(int*));
				if (linkedChain_ptr == NULL) {
					printf("Error: Insufficient Memory\n");
					return 0;
				}
				ptrCount = 0;
			}
			ptrCount++;
			linkedChain_ptr = (int**)realloc(linkedChain_ptr,
				(ptrCount + 1) * sizeof(int*));
			//if allocation failed
			if (linkedChain_ptr == NULL) {
				for (index = 0; index <= ptrCount; index++) {
					free(linkedChain_ptr[index]);
				}
				printf("Error: Insufficient Memory\n");
				return 0;
			}
			linkedChain_ptr[ptrCount] = (int *)malloc(sizeof(int));
			if (linkedChain_ptr[ptrCount] == NULL) {
				for (index = 0; index < ptrCount; index++) {
					free(linkedChain_ptr[index]);
				}
				free(linkedChain_ptr);
				printf("Error: Insufficient Memory\n");
				return 0;
			}
			//user AddItem function to add value for the new pointer
			linkedChain_ptr[ptrCount] = AddItem(linkedChain_ptr[ptrCount]);
			break;
			//choice 2- remove a pointer
		case Remove:
			if (FindError(indicator) == 1) {
				break;
			}
			//use RemovePtr function to remove pointer from list of pointers
			linkedChain_ptr = RemovePtr(linkedChain_ptr);
			break;
			//choice 3- Print the queue
		case PrCur:
			if (FindError(indicator) == 1) {
				break;
			}
			//use PrintQueue function to print queue
			PrintQueue(linkedChain_ptr);
			break;
			//choice 4- find max number in the queue
		case PrMax:
			if (FindError(indicator) == 1) {
				break;
			}
			//use PrintMax function to print the max number
			PrintMax(linkedChain_ptr);
			break;
			//choice 5- find min number in the queue
		case PrMin:
			if (FindError(indicator) == 1) {
				break;
			}
			//use PrintMin function to print the min number
			PrintMin(linkedChain_ptr);
			break;
			//choice 6- find index of inputted number
		case PrIndex:
			if (FindError(indicator) == 1) {
				break;
			}
			/*use PrintIndex function to print index of inputted number (if it's
			in the queue)*/
			PrintIndex(linkedChain_ptr);
			break;
			//choice 7- clear queue
		case Clear:
			//use ClearQueue function to clear the queue
			ClearQueue(linkedChain_ptr);
			printf("Queue is clear\n");
			break;
		case Menu:
			break;
		default:
			printf("Error: Unrecognized choice\n");
			break;
		}
		//after the chosen case is finished- print next choice selection
		printf("Please select your next choice (select 8 for complete menu)\n");
		scanf("%d", &input);
		//run for each case unless user chose 0 (quit)
	} while (1>0);
}
/*
Function name: MainMenu
The input:  linkedChain_ptr- new created pointer (from MainMenu function)
the output: linkedChain_ptr- pointer to int
The function operation: this is the main function of the program, managed by
a switch-case in a do-while loop to choose the correct function by user input.
the MainMenu function creates a pointer to pointer linkedChain_ptr which
will point to the pointers of int (Added by user).
*/
int* AddItem(int* linkedChain_ptr) {
	printf("Enter item value to add\n");
	//scan user input into pointer
	scanf("%d", linkedChain_ptr);
	printf("Item %d added\n", *linkedChain_ptr);
	return linkedChain_ptr;
}
/*
Function name: PrintMenu
The input:  none
the output: user input (scanned int)
The function operation: this function is invocated after any choice of user-
print the menu and scan the user's input
*/
int PrintMenu() {
	int input;
	printf("Please select your choice:\n"
		"0.Exit\n"
		"1.Add item to the queue\n"
		"2.Remove item from the queue\n"
		"3.Print queue\n"
		"4.Print the maximum item in the queue\n"
		"5.Print the minimum item in the queue\n"
		"6.Print index of given item\n"
		"7.Clear queue\n"
		"8.Print the menu\n");
	scanf("%d", &input);
	return input;
}
/*
Function name: RemovePtr
The input:  linkedChain_ptr- pointer to pointers
the output: 0 if allocation failed- else return the new linkedChain_ptr
The function operation: this function takes the pointer to pointers, brings
all the pointers to the start (overwriting pointers) and freeing the last pointer,
then it reallocs the new pointer to pointers (linkedChain_ptr)
*/
int** RemovePtr(int** linkedChain_ptr) {
	int index;
	printf("Item %d was removed\n", *linkedChain_ptr[1]);
	//move all pointers 1 move to the start (overwriting pointers)
	for (index = 1; index < ptrCount; index++) {
		*linkedChain_ptr[index] = *linkedChain_ptr[index + 1];
	}
	//free the last pointer
	free(linkedChain_ptr[index]);
	linkedChain_ptr = (int**)realloc(linkedChain_ptr, ptrCount * sizeof(int*));
	//if realloc failed
	if (linkedChain_ptr == NULL) {
		for (index = 0; index < ptrCount; index++) {
			free(linkedChain_ptr[index]);
		}
		free(linkedChain_ptr);
		printf("Error: Insufficient Memory\n");
		return 0;
	}
	--ptrCount;
	//return the new pointer to pointers
	return linkedChain_ptr;
}
/*
Function name: PrintQueue
The input:  linkedChain_ptr- pointer to pointers
the output: none
The function operation: this function runs a for loop on all the pointer to 
pointers and print every pointer in it.
*/
void PrintQueue(int** linkedChain_ptr) {
	int index;
	printf("Queue items are:");
	for (index = 1; index <= ptrCount; index++) {
		printf(" %d", *linkedChain_ptr[index]);
	}
	printf("\n");
	return;
}
/*
Function name: PrintMax
The input:  linkedChain_ptr- pointer to pointers
the output: none
The function operation: this function finds the maximum item in the queue 
(run a for loop on all the pointers and find out the biggest one)
*/
void PrintMax(int** linkedChain_ptr) {
	int index, tmpMax;
	//new int tmpMax- assign it a random value from the queue for the for loop
	tmpMax = *linkedChain_ptr[1];
	printf("Maximum item in queue is ");
	for (index = 1; index <= ptrCount; index++) {
		if (*linkedChain_ptr[index] > tmpMax) {
			//if found bigger value
			tmpMax = *linkedChain_ptr[index];
		}
	}
	printf("%d\n", tmpMax);
}
/*
Function name: PrintMax
The input:  linkedChain_ptr- pointer to pointers
the output: none
The function operation: this function finds the minimum item in the queue
(run a for loop on all the pointers and find out the smallest one)
*/
void PrintMin(int** linkedChain_ptr) {
	int index, tmpMin;
	//new int tmpMin- assign it a random value from the queue for the for loop
	tmpMin = *linkedChain_ptr[1];
	printf("Minimum item in queue is ");
	for (index = 1; index <= ptrCount; index++) {
		if (*linkedChain_ptr[index] < tmpMin) {
			//if found smaller value
			tmpMin = *linkedChain_ptr[index];
		}
	}
	printf("%d\n", tmpMin);
}
/*
Function name: PrintIndex
The input:  linkedChain_ptr- pointer to pointers
the output: none
The function operation: this function gets an input from the user and scans
the pointer to pointer to check if there's a value equal to it- if there is
it prints all the indexes it appers in, if not- prints there isn't one
*/
void PrintIndex(int** linkedChain_ptr) {
	int index, wantedNum, indicator = 0, tmpIndex;
	printf("Please enter the item you would like to know its index\n");
	scanf("%d", &wantedNum);
	//count how many times the user inputted number appears in pointers
	for (index = 1; index <= ptrCount; index++) {
		if (*linkedChain_ptr[index] == wantedNum) {
			indicator++;
		}
	}
	//if the user number appears more than once- print all the indexes
	if (indicator >= 1) {
		for (tmpIndex = 0; tmpIndex <= indicator; tmpIndex++) {
			for (index = 1; index <= ptrCount; index++) {
				if (*linkedChain_ptr[index] == wantedNum) {
					tmpIndex++;
					printf("Item %d index is %d\n", wantedNum, index);
				}
			}
		}
	}
	else {
		printf("Error: no such item!\n");
	}
}
/*
Function name: FindError
The input:  indicator (indicator if the 'AddItem' function has ever been 
invocated
the output: 1 if the queue is empty, 2 if not
The function operation: this function finds if the queue is empty (by checking
the value of the indicator, and the ptrCount (variable tracking the number of 
pointers). return 1 if queue is empty, return 2 if it's not empty
*/
int FindError(int indicator) {
	if (indicator == 0 || ptrCount == 0 || ptrCount == -1) {
		printf("Error: Queue is empty!\n");
		return 1;
	}
	else {
		return 2;
	}
}
/*
Function name: ClearQueue
The input:  linkedChain_ptr (pointer to pointers)
the output: none
The function operation: this function frees all the pointers and pointers 
to pointer in the program, and setting the value of pointer counter to (-1)- 
just to indicate the AddItem function it has been invocated
*/
void ClearQueue(int** linkedChain_ptr) {
	int index;
	if (ptrCount != 0) {
		for (index = 1; index <= ptrCount; index++) {
			free(linkedChain_ptr[index]);
		}
	}
	free(linkedChain_ptr);
	ptrCount = -1;
}