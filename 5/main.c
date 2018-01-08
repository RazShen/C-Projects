/*
Student name: Raz Shenkman
Student ID: 311130777
Course exercise group: 01
Exercise name: ex6
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
#include <ctype.h>
#include "Gadt.h"
//struct of point
struct dotNode_S {
	int x;
	int y;
};
typedef struct dotNode_S dotNode;
//declaring the private functions
static ELM ArrCreate();
static int ArrCmp(ELM, ELM);
static void ArrCpy(ELM, ELM);
static void PrintArr(ELM);
static ELM ArrAddElmToElm(ELM, ELM);
static ELM DotCreate();
static int DotCmp(ELM, ELM);
static void DotCpy(ELM, ELM);
static void Free(ELM);
static void PrintDot(ELM);
static ELM DotAddElmToDot(ELM, ELM);
//the main function which operation the generic functions in Gadt.c
int main() {
	int choice1, indicator = 0, lengthList = 0, indicator2 = 0;
	char *tmpArr,*tmpArr2, choice2;
	//create temporary point struct
	dotNode* tmpDot, *tmpDot2;
	ELM newNode;
	HEAD genHead;
	//get first user input
	scanf("%d", &choice1);
	//if input is 0
	if (choice1 == 0) {
		//create a array and create the head of the array linked list
		tmpArr = ArrCreate();
		scanf("%s", tmpArr);
		//create a head (array type)
		genHead = SLCreate(tmpArr, *ArrCreate, *ArrCpy, *ArrCmp, *Free, *PrintArr,
			*ArrAddElmToElm);
		if (genHead == NULL) {
			free(tmpArr);
			return 0;
		}
	}
	else {
		//create a point structure and create the head of the point linked list
		tmpDot = DotCreate();
		scanf(" (%d,%d)", &tmpDot->x, &tmpDot->y);
		//create a head (point type)
		genHead = SLCreate(tmpDot, *DotCreate, *DotCpy, *DotCmp, *Free, *PrintDot,
			*DotAddElmToDot);
		if (genHead == NULL) {
			Free(tmpDot);
			return 0;
		}
	}
	//do- while loop for user's input (switch case)
	do {
		scanf(" %c", &choice2);
		switch (choice2) {
			case 'a':
				//add node to list
				if (choice1 == 0) {
					tmpArr = ArrCreate();
					scanf("%s", tmpArr);
					//create a newNode array type (general structure)
					newNode = SLCreate(tmpArr, *ArrCreate, *ArrCpy, *ArrCmp, 
						*Free, *PrintArr, *ArrAddElmToElm);
					//calling the SLAddListElement generic function
					indicator2 = SLAddListElement(genHead, newNode);
				}
				//scan a temporary point structs (for comparison)
				if (choice1 != 0) {
					tmpDot = DotCreate();
					scanf(" (%d,%d)", &tmpDot->x, &tmpDot->y);
					//create a newNode point type (general structure)
					newNode = SLCreate(tmpDot, *DotCreate, *DotCpy, *DotCmp,
						*Free, *PrintDot, *DotAddElmToDot);
					//calling the SLAddListElement generic function
					indicator2 = SLAddListElement(genHead, newNode);
				}
				break;
			case 's':
				//scan a temporary char array (for comparison)
				if (choice1 == 0) {
					tmpArr = ArrCreate();
					scanf("%s", tmpArr);
					//calling the SLFindElement generic function
					tmpArr = SLFindElement(genHead, tmpArr);
					//if it's not in the list
					if (tmpArr == NULL) {
						printf("FALSE\n");
					}
					//of ot's in the list
					else {
						free(tmpArr);
						printf("TRUE\n");
					}
				}
				//scan a temporary point structs (for comparison)
				if (choice1 != 0) {
					tmpDot = DotCreate();
					scanf(" (%d,%d)", &tmpDot->x, &tmpDot->y);
					//calling the SLFindElement generic function
					tmpDot = SLFindElement(genHead, tmpDot);
					//if it's not in the list
					if (tmpDot == NULL) {
						printf("FALSE\n");
					}
					//if it's in the list
					else {
						free(tmpDot);
						printf("TRUE\n");
					}
				}
				break;
			case 'd':	
				if (choice1 == 0) {
					//scan a temporary char array (for comparison)
					tmpArr = ArrCreate();
					scanf("%s", tmpArr);
					//calling the SLFindElement generic function
					tmpArr = SLFindElement(genHead, tmpArr);
					if (tmpArr == NULL) {
						printf("FALSE\n");
						break;
					}
					//if only 1 item in the list 
					else {
						indicator = SLPrintSize(genHead);
						if (indicator == 1) {
							free(tmpArr);
							//will stop the do-while and destroy the head
							break;
						}
						//if more than 1 item in the list
						tmpArr = SLCreate(tmpArr, *ArrCreate, *ArrCpy, *ArrCmp,
							*Free, *PrintArr, *ArrAddElmToElm);
						SLRemoveElement(genHead, tmpArr);
					}
				}
				//scan a temporary point structs (for comparison)
				if (choice1 != 0) {
					tmpDot = DotCreate();
					scanf(" (%d,%d)", &tmpDot->x, &tmpDot->y);
					//calling the SLFindElement generic function
					tmpDot = SLFindElement(genHead, tmpDot);
					if (tmpDot == NULL) {
						printf("FALSE\n");
						break;
					}
					//if only 1 item in the list 
					else {
						indicator = SLPrintSize(genHead);
						if (indicator == 1) {
							free(tmpDot);
							//will stop the do-while and destroy the head
							break;
						}
						//if more than 1 item in the list
						tmpDot = SLCreate(tmpDot, *DotCreate, *DotCpy, *DotCmp,
							*Free, *PrintDot, *DotAddElmToDot);
						SLRemoveElement(genHead, tmpDot);
					}
				}
				break;
			case 'p':
				//print the list
				SLPrint(genHead);
				break;
			case 'l':
				//print the length
				printf("%d\n", SLPrintSize(genHead));
				break;
			case 't':
				//add elm to elm
				if (choice1 == 0) {
					//create 2 tmp array structs
					tmpArr = ArrCreate();
					tmpArr2 = ArrCreate();
					scanf(" %s %s", tmpArr,tmpArr2);
					//create 1 array generic struct
					tmpArr2 = SLCreate(tmpArr2, *ArrCreate, *ArrCpy, *ArrCmp,
						*Free, *PrintArr, *ArrAddElmToElm);
					tmpArr = SLCreate(tmpArr, *ArrCreate, *ArrCpy, *ArrCmp,
						*Free, *PrintArr, *ArrAddElmToElm);
					SLAddToElement(genHead, tmpArr, tmpArr2);
				}
				if (choice1 != 0) {
					//create 2 tmp point structs
					tmpDot = DotCreate();
					tmpDot2 = DotCreate();
					scanf(" (%d,%d) (%d,%d)", &tmpDot->x, &tmpDot->y, &tmpDot2->x,
						&tmpDot2->y);
					//create 1 point generic struct
					tmpDot2 = SLCreate(tmpDot2, *DotCreate, *DotCpy, *DotCmp,
						*Free, *PrintDot, *DotAddElmToDot);
					tmpDot = SLCreate(tmpDot, *DotCreate, *DotCpy, *DotCmp,
						*Free, *PrintDot, *DotAddElmToDot);
					SLAddToElement(genHead, tmpDot, tmpDot2);
				}
				break;
			case 'e':
				//destroy- a condition in the do while loop if the input is 'e'
				break;
			default:
				printf("Unrecognized Choice\n");
				break;
		} 
	} while (choice2 != 'e' && indicator != 1);
	//if choice is e or there was only 1 node in the list when user entered 'd'
	//and the inputted element was in the list
	SLDestroy(genHead);
	return 0;
}

/*
Function name: ArrCreate
The input: none
the output: char* pointer
The function operation: the function allocates memory for an array of chars
by using malloc for 16 byte
*/
static ELM ArrCreate() {
	char* root = (char*)malloc(MAXLEN*sizeof(char));
	return root;
}
/*
Function name: ArrCmp
The input: 2 ELM (void*)
the output: 1,-1 or 0 
The function operation: first the function uses casting on the inputted ELM, 
then it returns the comparison between them (using -1,0,1) 
*/
static int ArrCmp(ELM strx, ELM stry) {
	char* strX = (char*)strx;
	char* strY = (char*)stry;
	return (strcmp(strX, strY));
}
/*
Function name: ArrCpy
The input: 2 ELM (void*)
the output: none
The function operation: first the function uses casting on the inputted ELM,
then the function is using strcpy to copy the second char* into the first char*,
then it free the second string
*/
static void ArrCpy(ELM strX, ELM strY) {
	char* strA = (char*)strX;
	char* strB = (char*)strY;
	strcpy(strA,strB);
	free(strB);
}
/*
Function name: PrintArr
The input: ELM (void*)
the output: none
The function operation: the function first casts the ELM input into char*,
then print the chars
*/
static void PrintArr(ELM str) {
	char* strA = (char*)str;
	printf("%s\n", strA);
}
/*
Function name: ArrAddElmToElm
The input: 2 ELM (void*)
the output: char*
The function operation: the function first casts the ELM input into char*,
then adding the value of the new string to the old string and adding that to
the new string value (thats added to the list) (saving the old string value with
str tmp) when finished- return the existing string it's value, and return the 
new string
*/
static ELM ArrAddElmToElm(ELM strX, ELM strY) {
	char tmp[MAXLEN];
	char* strA = (char*)strX;
	char* strB = (char*)strY;
	strcpy(tmp, strB);
	strcat(strB, strA);
	strcpy(strA, strB);
	//return the existing string it's value (by strcpy of tmp to it) 
	strcpy(strB, tmp);
	return strA;
}
/*
Function name: DotCreate
The input: none
the output: point structure pointer
The function operation:  the function allocates memory for a pointer to point
structure using malloc for size of structure
*/
static ELM DotCreate() {
	dotNode *root = (dotNode*)malloc(sizeof(dotNode));
	return root;
}
/*
Function name: DotCmp
The input: 2 ELM (void*)
the output: 1,-1 or 0
The function operation: first the function uses casting on the inputted ELM,
then it checks if the second strcture abs value is bigger than the first strcture
abs value- if it is- return -1, if it's smaller return 1. if they are equal
return 0
*/
static int DotCmp(ELM dotX ,ELM dotY) {
	dotNode* dotA = (dotNode*)dotX;
	dotNode* dotB = (dotNode*)dotY;
	int dX, dY;
	dX = abs(dotA->x) + abs(dotA->y);
	dY = abs(dotB->x) + abs(dotB->y);
	if (dX < dY) {
		return -1;
	}
	if (dX > dY) {
		return 1;
	}
	else {
		return 0;
	}
}
/*
Function name: DotCpy
The input: 2 ELM (void*)
the output: none
The function operation: first the function uses casting on the inputted ELM,
then the function copies the second ELM values of structure into the first
ELM values of structure (overwriting them). then free the second ELM
*/
static void DotCpy(ELM dotX, ELM dotY) {
	dotNode* dotA = (dotNode*)dotX;
	dotNode* dotB = (dotNode*)dotY;
	//accsess the structure x,y values using '->'
	dotA->x = dotB->x;
	dotA->y = dotB->y;
	free(dotB);
}
/*
Function name: PrintArr
The input: ELM (void*)
the output: none
The function operation: the function first casts the ELM input into point 
structure, then print the point.
*/
static void PrintDot(ELM dotX) {
	dotNode* dotA = (dotNode*)dotX;
	//accsess point structure values
	printf("%.3d|%.3d\n", dotA->x, dotA->y);
}
/*
Function name: DotAddElmToDot
The input: 2 ELM (void*)
the output: the first ELM after it's values has been changed
The function operation: the function first casts the ELM input into point
structure pointer, then copies the values of the inputted point into the 
existing point, then returns the existing string. when finished-
return the pointer to the first element
*/
static ELM DotAddElmToDot(ELM dotX, ELM dotY) {
	dotNode* dotx = (dotNode*)dotX;
	dotNode* doty = (dotNode*)dotY;
	//accsess point structure values
	(dotx->x) = (dotx->x) + (doty->x);
	(dotx->y) = (dotx->y) + (doty->y);
	return dotx;
}
/*
Function name: FreeArr
The input: ELM (void*)
the output: none
The function operation: the function uses free to free the inputted pointer
*/
static void Free(ELM x) {
	free(x);
}