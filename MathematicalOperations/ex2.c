#include <stdio.h>

void BiggerNum();
void MathTable();
void GetDeviders();
void DevOr();
void DevBoth();
void Fibonacchi();
void PrintBiggerAndSmaller(int x, int y);
void SmallestPos();
void FindSmallPos();
int  DigitSum(unsigned long int longNum);
//the U2 is not recognzing _CRT_INT_MAX so I set up the value manually
# define _CRT_INT_MAX 2147483647
//global variablesint smallPos;
int maxInput = _CRT_INT_MAX;
int num1, num2, bigNum, smallNum, Fibo, minInput = _CRT_INT_MAX, smallPos;
unsigned int n, div1, div2;
char k;
/*the int main function is the body of the program, it includes a switch within
a while loop and has 5 diffrent option to choose from
*/
int main() {
	//getting the input from the user to select the assignment
	int menuSelect;
	printf("Please select the assignment:\n");
	scanf("%d", &menuSelect);
	//enum to define the choices of the user
	enum Selection {EndProgram, Table , Deviders, Fibonacci, SmallPositive, Sum};
	//enters the switch loop- unless the user input is 0
	while (menuSelect != 0) {
		//switch case to enter the user's value (by the 'enum selection' name)
		switch (menuSelect) {
			case EndProgram:
				return 0;
			case Table:
				//invocation of MathTable
				MathTable();
				break;
			case Deviders:
				//calls the function to get the user values 
				GetDeviders();
				//switch case to the value of k, for 4 diffrent inputs
				switch (k) {
					case 'o':
						DevOr();
						break;
					case 'O':
						DevOr();
						break;
					case 'a':
						DevBoth();
						break;
					case 'A':
						DevBoth();	
						break;
					default:
						printf("ERROR IN KEY\n");
				break;
				}
				break;
			case Fibonacci:
				/*getting input from the user, if value of n is less than 1 
				it prints out error, if not it caculates fibonacci sequence 
				by it*/
				printf("Please enter n:\n");
				scanf("%d", &Fibo);
				//if the user enters a value less than 1, print out error
				if (Fibo < 1) 
					printf("INPUT ERROR\n");
					//if not, invocating the function Fibonacchi
					else 
						//invocates the function Fibonacchi
						Fibonacchi();
				break;
			case SmallPositive:
				//invocates the function SmallesPos
				SmallestPos();
				break;
			case Sum:
				//asking the user to enter a number, declaring variables
				printf("Please enter your number:\n");
				int finalCount;
				unsigned long int longNumber;
				scanf("%lu", &longNumber);
				//invocation of the function
				finalCount = DigitSum(longNumber);
				//printing the return of the function DigitSum
				printf("%d\n", finalCount);
				break;
			//if the user enters a value not from 0-5
			default:
				printf("NO SUCH ASSIGNMENT!\n");
		}
		//repeat of the while loop
		printf("Please select the assignment:\n");
		scanf("%d", &menuSelect);
	}
	return 0;
}
/*
function name: BiggerNum
input: none
output: none
Note: a bigger number and a smaller number
operation function: checks if one number is bigger than the other, if so
it stores it's value in a integer
*/
void BiggerNum() {
	printf("Please enter two numbers for the multiplication table:\n");
	scanf(" %d %d", &num1, &num2);
	if (num1 >= num2) {
		bigNum = num1;
		smallNum = num2;
	}
	else {
		bigNum = num2;
		smallNum = num1;
	}
}
/*
function name: MathTable
input: none
output: none
operation function: the function gets 2 numbers from BiggerNum Function. 
a mathematical duplication table from the smaller number to the bigger
the for loop is duplicating the smaller number by a
number with the same value untill it reach the value of bigger number,
than it moves to a new line and raise the duplicator number by one and repeate.
Note: the function moves 4 spaces to the right from each duplication result.
*/
void MathTable() {
	BiggerNum();
	int multyNum, baseNum;
	multyNum = smallNum;
	baseNum = smallNum;
	for (multyNum; multyNum <= bigNum; multyNum++) {
		for (smallNum; smallNum <= bigNum; smallNum++)
			printf("%d\t", smallNum*multyNum);
			smallNum = baseNum;
			printf("\n");
	}
}
/*
function name: GetDeviders
input: none 
output: none 
operation function:the function asks from the user to enter an n, 2 dividers,
and a key. the function stores it each time.
Note: the function stores the numbers for using in function DevOr/DevBoth.
*/
void GetDeviders() {
	printf("Please enter n:\n");
	scanf(" %d", &n);
	printf("Please enter two dividers:\n");
	scanf(" %d %d", &div1, &div2);
	printf("Please enter the key:\n");
	scanf(" %c", &k);
}
/*
function name: DevOr
input: none
output: none
operation function: the function uses interger n from user input in GetDeviders,
the function prints all the numbers from 1 to n if they divide fully
in div1 or div2 (using a for loop if the divide result is 0)
Note: skips a line after it finishes printing the session, one space between
each number in the session
*/
void DevOr() {
	unsigned int devider = 1;
	for (devider; devider <= n; devider++) {
		if (devider%div1 == 0 || devider%div2 == 0) {
			printf("%d ", devider);
		}
	}
	printf("\n");
}
/*
function name: DevBoth
input: none
output: none
operation function: the function uses interger n from user input in GetDeviders,
the function prints all the numbers from 1 to n if they divide fully
in div1 andd div2, if they both divide fully in div1 and div2 it prints out 
the divider.
Note: skips a line after it finishes printing the session, one space between
each number in the session
*/
void DevBoth() {
	unsigned int devider = 1;
	for (devider; devider <= n; devider++) {
		if (devider%div1 == 0 && devider%div2 == 0) {
			printf("%d ", devider);
		}
	}
	printf("\n");
}
/*
function name: Fibonacchi
input: none
output: none
operation function: the function uses interger Fibo from user input in
case Fibonacci (function int main). then the function prints the numbers of sub
fibonacci sequence by the value from 1 to the user input. the function caculates
the first number and the second number always as 1, and after that it gives the
next number the sum of the 2 numbers before it (F(n+2)=F(n)+F(n+1))
Note: skips a line after it finishes printing the session, one space between
each number in the sequence
*/
void Fibonacchi() {
	int i, a, b, nextNum;
	a = 1;
	b = 1;
	
	for (i=1; i <= Fibo; ++i) {
		// sets first element to be 1
		if (i == 1) {
			printf("%d ", a);
			continue;
		 }
		// sets second element to be 1
		if (i == 2) {
			printf("%d ", b);
			continue;
		}
		//the function F(n+2)=F(n)+F(n+1)
		nextNum = a + b;
		a = b;
		b = nextNum;
		printf("%d ", nextNum);
	}
	printf("\n");
}
/*
function name : PrintBiggerAndSmaller
input : 2 integers 
output:the function return nothing, but print the numbers from smaller to bigger
operation function: the function takes 2 integers, asks if one is greater then
the other, if so it moves on to printing, if not, it switches the smaller and 
the bigger number and moves on to printing the smaller one first and the bigger
one second.
Note :
*/
void PrintBiggerAndSmaller(int x, int y) {
	int temp = 0;
	if (x > y) {
		x = x;
		y = y;
	}
	if (x < y){
		temp = x;
		x = y;
		y = temp;
	}
	printf("%d %d\n", y, x);
}
/*
function name : FindSmallPos
input : None
output:None
operation function: the function caculates the 2 smallest number in an input 
(the loop is in the function SmallestPos), it takes the user input smallPos and 
see if it's smaller then  2 integers, if so it gives the first int maxInput 
the value of the minInput and gives the smaller one the value of user's input.
after it happends the minInput will be the user input and maxInput will be
biggest int possible, so it checks again and if the maxInput is greater than
the user input- it gives it the value of the user's input (another condition- 
if the user enters 2 same positive minimums, it adds 1 to the maxInput to
make sure maxInput and minInput won't be the same)
Note : none
*/
void FindSmallPos() {
	scanf(" %d", &smallPos);
	if (maxInput > smallPos && smallPos > 0) {
		if (minInput > smallPos && smallPos >0) {
			maxInput = minInput;
			minInput = smallPos;
		}
		else {
			maxInput = smallPos;
		}
		if (maxInput == minInput) {
			minInput++;
		}
	}
}
/*
function name: SmallestPos
input: None
output: None. invocating he function PrintBiggerAndSmaller with the inputs
from FindSmallerPos
operation function: The function runs a do while loop if the user input is
diffrent from -1 it invocates the function FindSmallestPos which finds the two
smallest positive numbers, after the loop is finished it takes the values from
FindSmallPos and enters them to PrintBiggerAndSmaller
Note: none
*/
void SmallestPos() {
	printf("Please enter your sequence:\n");
	do {
		FindSmallPos();
	} while (smallPos != (-1));
		PrintBiggerAndSmaller(maxInput,minInput);
}
/*
function name: DigitSum
input: the function uses unsigned long input longNuber
output: the function return the sum of the digits
operation function: the function counts the remainder of the input divided by 10,
and than adds to an variable countSum which adds the value of the remainder to 
himself, every time the number has bigger value than 0, it divides itself by 10,
so every digit in the number will be the remainder of the division by 10.
the function return the sum of the remainders of the input divided by 10
Note: 
*/
	int DigitSum(unsigned long int longNum) {
	int countSum =0;
	while (longNum != 0) {
		countSum = countSum + longNum % 10;
		longNum = longNum / 10;
	}
	return countSum;
}


		
	

