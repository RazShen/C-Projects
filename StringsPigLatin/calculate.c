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

/*declaring the matrices and the first matrix value global for multy functional
usage, also operation char for the option to return to main 
*/ 

int mat1[15][15], mat2[15][15], matAfterCal[15][15], row, column;
char operation;

/*
Function name: caclculate
The input: none
the output: none
The function operation: the function prints out the welcome message, and
then invocate the MainFun()
*/ 
void calculate() {
	printf("Welcome to the Matrix calculator\n");
	MainFun();
} 
/*
Function name: MainFun
The input: none
the output: none
The function operation: the function includes a do while loop within a
do while loop, the first do while loop invocate the GetRowCol function
and Get1Matrix function if the rows and columns inputted are bigger than 1,
, enters a second do while loop which invocate the operation function.
*/
void MainFun() {
	do {
		GetRowCol();
		Get1Matrix();
		do {
			//initialize operation value to 0
			operation = '0';
			printf("Please enter operation:(+,-,*,t,c,q)\n");
			scanf(" %c", &operation);
			Operate();
			//keep the loop running unless user's input is 'q'
		} while (operation != 'q');
			return;
		//keep the loop running usless row and column are 1 or lower
	} while (row > 1 && column > 1|| operation != 'q');
}
/*
Function name: GetRowCol
The input: none
the output: none
The function operation: the function asks the user to enter the row and column
for the first matrix, and if the values are lower than 1, it prints out error
and ask for row and column again
*/
void GetRowCol() {
	printf("Please enter first matrix dimensions (row col):\n");
	scanf(" %d %d", &row, &column);
	if (row < 1 || column < 1) {
		printf("Error\n");
		GetRowCol();
	}
}
/*
Function name: Get1Matrix
The input: none
the output: none
The function operation: the function asks the user to enter the the elements 
for the matrix by the previously inputted row and column, then the function
scans the values and enter it to the first matrix by order
*/
void Get1Matrix() {
	//creating index integers for 'for loops'
	int r, c;
	printf("Please enter matrix elements(%dx%d):\n", row, column);
	for (r = 0; r < row; r++) {
		for (c = 0; c < column; c++) {
			/*the for loop within a for loop is for scanning the columns first
			and the rows after each column is filled
			*/
			scanf(" %d", &mat1[r][c]);
		}
	}
}	
/*
Function name: Operate
The input: char 'operate'- user's input for the wanted operation
the output: none
The function operation: the function initialize a switch case by the value
of the 'operation' char in the MainFun, if the user enters a unfamiliar
value for 'operation' it prints out a notification and return to the MainFun
for getting another value.
when a case is chosen the function inside of it are being invocated, and after 
that it asks the user for another 'operation' input
*/
void Operate() {
	switch (operation) {
	case '-':
		Get2Matrix();
		DecreaseMatrices();
		break;
	case '+':
		Get2Matrix();
		SumMatrices();
		break;
	case '*':
		GetMultyMat();
		break;
	case 'c':
		MainFun();
		break;
	case 'q':
		return;
		break;
	case 't':
		Transpose();
		break;
	default:
		printf("This operation does not exist!\n");
		break;
	}
}
/*
Function name: Get2Matrix
The input: none
the output: none
The function operation: for the operation '+' and '-' the we can use the same
size matrix, so Get2Matrix asks the user to enter a same size (to the original
matrix size) matrix.
*/
void Get2Matrix() {
	//creating index integers for 'for loops'
	int r, c;
	printf("Please enter matrix elements(%dx%d):\n", row, column);
	for (r = 0; r < row; r++) {
		for (c = 0; c < column; c++) {
			scanf(" %d", &mat2[r][c]);
		}
	}
}
/*
Function name: SumMatrices
The input: none
the output: none
The function operation: for the operation '+' we use the SumMatrices after we
received another matrix from to user in the same size as the original one.
we create a new matrix in the same size of the original matrix and each element
of the new matrix is the addition of the same spot element in the original 
matrix and the new matrix. then it updates the value of the original matrix 
to the result for further use
*/
void SumMatrices() {
	//creating index integers for 'for loops'
	int r, c;
	for (r = 0; r < row; r++) {
		for (c = 0; c < column; c++) {
			matAfterCal[r][c] = (mat1[r][c] + mat2[r][c]);
			//change the value of the new matrix to the new one
			mat1[r][c] = matAfterCal[r][c];
		}
	}
	//print out the new matrix by printing each element and 4 spaces afte it
	printf("The answer is:\n");
	for (r = 0; r < row; r++) {
		for (c = 0; c < column; c++) {
			printf("%4d", matAfterCal[r][c]);
		}
		printf("\n");
	}
}
/*
Function name: DecreaseMatrices
The input: none
the output: none
The function operation: for the operation '-' we use the DecreaseMatrices after we
received another matrix from to user in the same size as the original one.
we create a new matrix in the same size of the original matrix and each element
of the new matrix is the substraction of the same spot element in the original
matrix and the new matrix. then it updates the value of the original matrix 
to the result for further use
*/
void DecreaseMatrices() {
	//creating index integers for 'for loops'
	int r, c;
	for (r = 0; r < row; r++) {
		for (c = 0; c < column; c++) {
			matAfterCal[r][c] = (mat1[r][c] - mat2[r][c]);
			//change the value of the new matrix to the new one
			mat1[r][c] = matAfterCal[r][c];
		}
	}
	//print out the new matrix by printing each element and 4 spaces afte it
	printf("The answer is:\n");
	for (r = 0; r < row; r++) {
		for (c = 0; c < column; c++) {
			printf("%4d", matAfterCal[r][c]);
		}
		printf("\n");
	}
}
/*
Function name: GetMultyMat
The input: none
the output: none
The function operation: the function asks the user in input a column dimension
for the second matrix (must be 1 or above or error and repeat), the function
scan the new column dimension and then asks the user to input matrix elements
(by the value of original columnXuser inputted column), then it scans the new
matrix. after that it invocate MultyMat function.
*/
void GetMultyMat() {
	//creating index integers for 'for loops'
	int r, c, rMul=0, cMul=0;
	printf("Please enter column dimension of second matrix:\n");
	scanf(" %d", &cMul);
	//new column value must be 1 or above
	while (cMul < 1) {
		printf("Error\nPlease enter column dimension of second matrix:\n");
		scanf(" %d", &cMul);
	}
	printf("Please enter matrix elements(%dx%d):\n", column, cMul);
	//scan matrix2 elements
	for (r = 0; r < column; r++) {
		for (c = 0; c < cMul; c++) {
			scanf(" %d", &mat2[r][c]);
		}
	}
	//initializing matAfterCal to be 0
	for (r = 0; r < 15; r++) {
		for (c = 0; c < 15; c++) {
			matAfterCal[r][c] = 0;
		}
	}
	MultyMat(cMul);
}
/*
Function name: MultyMat
The input: int newCol- new column dimension for the new matrix (inputted by 
user)
the output: none
The function operation: the function caculates the new matrix by multypling
each row of the original matrix in the column of the previously inputted matrix.
after that it prints out the new value. then it changes the value of the 
original matrix to the new one for further use
*/
void MultyMat(int newCol) {
	//creating index integers for 'for loops'
	int r, c, tempRow;
	//calculate the new matrix by multypling each row of the original matrix
	for (tempRow = 0; tempRow < row; tempRow++) {
		for (c = 0; c < newCol; c++) {
			for (r = 0; r < column; r++) {
				matAfterCal[tempRow][c] += mat1[tempRow][r] * mat2[r][c];
			}
		}
	}
	//print the new  matrix with 4 spaces after each element
	printf("The answer is:\n");
	for (r = 0; r < tempRow; r++) {
		for (c = 0; c < newCol; c++) {
			printf("%4d", matAfterCal[r][c]);
			//change the value of the original matrix to the new one
			mat1[r][c] = matAfterCal[r][c];
			//updates original matrix column value
			column = newCol;
		}
		printf("\n");
	}
}
/*
Function name: Transpose  
The input: none
the output: none
The function operation: the function caculates the value of the transpose of 
the original matrix by replacing the elements in location [r][c] to be in
location [c][r] and then initialize PrintTranspose
*/
void Transpose() {
	//creating index integers for 'for loops'
	int r, c;
	//initializing the 'to be' transpose matrix to 0
	for (r = 0; r < 15; r++) {
		for (c = 0; c < 15; c++) {
			matAfterCal[r][c] = 0;
		}
	}
	//caculating the transpose of mat1
	for (r = 0; r < row; r++) {
		for (c = 0; c < column; c++) {
			matAfterCal[c][r] = mat1[r][c];
		}
	}
	PrintTranspose();
}
/*
Function name: PrintTranspose
The input: none
the output: none
The function operation: compare new column to the original row and new row to 
the original column (making the dimensions of the transposed matrix) and then
it prints out the transposed matrix and updates the value of the original matrix 
and it's values to the transposed matrix and it's values. for further. 
*/
void PrintTranspose() {
	//creating index integers for 'for loops'
	int r, c;
	int trR = 0, trC = 0;
	//compare new column to the original row and new row to the original column 
	trC = row;
	trR = column;
	//print the new transpose matrix
	printf("The answer is:\n");
	for (r = 0; r < trR; r++) {
		for (c = 0; c < trC; c++) {
			printf("%4d", matAfterCal[r][c]);
			//compare the original matrix to the transposed one (for further use)
			mat1[r][c] = matAfterCal[r][c];
		}
		printf("\n");
	}
	//compare the original row and column to the new values (for further use)
	row = trR;
	column = trC;
}
