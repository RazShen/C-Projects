/*
Student name: Raz Shenkman
Student ID: 311130777
Course exercise group: 01
Exercise name: ex6
*/
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "Gadt.h"

//general struct (has a pointer to it's value (char* or dotNode*))
struct GenNode_S {
	ELM pointTo;
	struct GenNode_S* next;
	ELM(*create_elm)();
	void(*cpy_elm)(ELM, ELM);
	int(*cmp_elm)(ELM, ELM);
	void(*free_elm)(ELM);
	void(*print_elm)(ELM);
	ELM(*add_elm_to_elm)(ELM, ELM);
};
typedef struct GenNode_S GenNode;
/*
Function name: SLCreate
The input: Head (void*),pointer to the inputted data
and pointers to the 6 'private' functions 
the output: pointer to the new struct
The function operation: the function first allocates memory for the pointer to 
the structs, then it allocates memory to the pointer (of the data- arr or point)
and then it allocated the struct pointer to generic functions all the 'private'
functions inputted
*/
extern HEAD SLCreate(ELM head_val, ELM(*create_elm)(), void(*cpy_elm)(ELM, ELM),
	int(*cmp_elm)(ELM, ELM), void(*free_elm)(ELM),
	void(*print_elm)(ELM), ELM(*add_elm_to_elm)(ELM, ELM)) {
	//allocate memory for the pointer to the struct
	GenNode* head = (GenNode*)malloc(sizeof(GenNode));
	//allocate memory for the data
	head->pointTo = create_elm();
	if (head->pointTo == NULL) {
		return NULL;
	}
	//copy the inputted data into the struct pointer to data
	cpy_elm(head->pointTo, head_val);
	head->next = NULL;
	head->create_elm = create_elm;
	head->print_elm = print_elm;
	head->cpy_elm = cpy_elm;
	head->free_elm = free_elm;
	head->cmp_elm = cmp_elm;
	head->add_elm_to_elm = add_elm_to_elm;
	return (void*) head;
}
/*
Function name: SLAddListElement
The input: pointer to the head of linked struct, element to add
the output: RESULT enum type (0-3)
The function operation: the function first cast the input to be genNode type
and the new inputted node to be of general type, first the function checks if
the elements has to be replaced with the head. if not the function go over the 
elements in the list and compare the vales, once the input has smaller value
it puts it in the right place in the list
*/
extern RESULT SLAddListElement(HEAD* head, ELM node) {
	GenNode* newNode = (GenNode*)node;
	GenNode* newHead = (GenNode*)head;
	void* tmp;
	GenNode* current;
	//if the new element is smaller or equal to the head of the list
	if (newHead == NULL || newHead->cmp_elm(newHead->pointTo,newNode->pointTo)
		>=0) {
		newNode->next = newHead->next;
		newHead->next = newNode;
		tmp = newHead->pointTo;
		newHead->pointTo = newNode->pointTo;
		newNode->pointTo = tmp;
	}
	else {
		current = newHead;
		//if he new element is bigger than the head, find the right place for it
		while (current->next != NULL &&
			current->cmp_elm(current->next->pointTo,newNode->pointTo)<0) {
			current = current->next;
		}
		newNode->next = current->next;
		current->next = newNode;
	}

	return success;
}
/*
Function name: SLRemoveElement
The input: pointer to the head of linked struct, element to remove
the output: RESULT enum type (0-3)
The function operation: the function first casts the input to be of type of 
general Head (genNode)-  if the item to remove is the head- the function just
transfer the values of the item next to the head and the destroy the second
pointer (after the head), if the item to remove is not in the head (and there is
more then 1 element)- the function checks where it is in the list and then it
frees it from the list (described more in the function)
*/
extern RESULT SLRemoveElement(HEAD* head, ELM node) {
	GenNode* newHead = (GenNode*)head;
	GenNode* removeNode = (GenNode*)node;
	GenNode* current = newHead;
	GenNode* prevCur = newHead;
	GenNode* tmp = NULL;
	if (current->cmp_elm(current->pointTo, removeNode->pointTo) == 0) {
		//copy the element after the head values to the head
		newHead->cpy_elm(newHead->pointTo, newHead->next->pointTo);
		current = newHead->next;
		newHead->next = newHead->next->next;
		//freeing the element after the head and the input
		free(current);
		removeNode->free_elm(removeNode->pointTo);
		free(removeNode);
		return success;
	}
	else {
		//while loop to find out where the element to remove is in the list
		while (current->next != NULL && current->cmp_elm(current->pointTo,
			removeNode->pointTo) != 0) {
			prevCur = current;
			current = current->next;
		}
		//free the element's pointer to the data and make the struct that is
		//in 1 place before the removed struct to point to the struct that is
		//1 place after the removed struct.
		prevCur->free_elm(prevCur->next->pointTo);
		tmp = prevCur->next;
		prevCur->next = current->next;
		//freeing the element and the input
		free(tmp);
		removeNode->free_elm(removeNode->pointTo);
		free(removeNode);
		return success;
	}
}
/*
Function name: SLAddToElement
The input: pointer to the head of linked struct, element to remove and to add
the output: none
The function operation: the function first cast the input to be genNode type
and then it searches if the user added to- input is in the list, if it's not 
- free and return. if it is, add it's value to the new element, add the new 
element to the list and remove the exisiting element from the list and by using 
the function 'SLRemoveElement' and 'SLAddListElement'
*/
extern void SLAddToElement(HEAD* head, ELM toEl, ELM addEl) {
	GenNode* newHead = (GenNode*)head;
	GenNode* newToEl = (GenNode*)addEl;
	GenNode* existEl = (GenNode*)toEl;
	existEl->pointTo = SLFindElement(newHead, existEl->pointTo);
	//if the added to- element inputted by user isn't in the list
	if (existEl->pointTo == NULL) {
		//free all the structs pointers and return
		newToEl->free_elm(newToEl->pointTo);
		free(newToEl);
		existEl->free_elm(existEl->pointTo);
		free(existEl);
		return;
	}
		//
		else {
			//add the new element to the list and remove the old element
			newToEl->pointTo = newToEl->add_elm_to_elm
			(newToEl->pointTo, existEl->pointTo);
			SLAddListElement(head, newToEl);
			SLRemoveElement(head, existEl);
	}
}
/*
Function name: SLDestroy
The input: head of the linked list(void*)
the output: none
The function operation: the function first cast the input to be genNode type
and the new next pointer to general struct,
*/
extern void SLDestroy(HEAD head) {
	GenNode* current = (GenNode*)head;
	GenNode* next;
	while (current != NULL) {
		next = current->next;
		current->free_elm(current->pointTo);
		free(current);
		current = next;
	}
	head = NULL;
	return;
}
/*
Function name: SLPrint
The input: Head (void*)
the output: none
The function operation: the function first cast the input to be genNode type
then it uses a while function to go through the list to print and count each 
node, and print count number*tabs after the first node
*/
extern void SLPrint(HEAD head) {
	GenNode* newHead = (GenNode*)head;
	int index = 0,index2 = 0;
	while (newHead != NULL) {
		for (index = index2; index > 0; index--) {
			printf("\t");
		}
		newHead->print_elm(newHead->pointTo);
		if (newHead->next == NULL) {
			return;
		}
		newHead = newHead->next;
		index2++;
	}
}
/*
Function name: SLPrintSize
The input: Head (void*) 
the output: int (size of the list)
The function operation: the function first cast the input to be genNode type
then it uses a while function to go through the list and count the nodes, then
the function returns the count number of nodes
*/
extern int SLPrintSize(HEAD head) {
	GenNode* newHead = (GenNode*)head;
	int index = 0;
	while (newHead != NULL) {
		newHead = newHead->next;
		index++;
	}
	return index;
}
/*
Function name: SLFindElement
The input: Head (void*) and ELM (void*)
the output: Head*(void*) or NULL
The function operation: the function first cast the input to be genNode type
then the function checks if the user's input is equal to any
of the nodes in the list by using their private compare function, if it's
equal to any of them, free the input and return the node.
if it isn't equal free the input and return NULL
*/
extern ELM SLFindElement(HEAD head, ELM inputNode) {
	GenNode* newHead = (GenNode*)head;
	while (newHead != NULL) {
		if (newHead->cmp_elm(newHead->pointTo, inputNode) == 0) {
			return inputNode;
		}
		newHead = newHead->next;
	}
	free(inputNode);
	return NULL;
}