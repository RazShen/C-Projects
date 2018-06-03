/*
Student name: Raz Shenkman
Student: 311130777
Course Exercise Group: 4
Exercise name: ex2
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main()
{
	//defining all the variables for the program
	int menuSelect;
	int testScore;
	int num1, num2, num3;
	int low, middle, high;
	float average;
	char a, b, c;
	float csTest1, csTest2;
	float csExe1, csExe2;
	char s1, s2; 
	float finGrade1, finGrade2;
	//Receive an input from the user, from 0 to 4
	printf("Please enter your input:\n");
	scanf("%d", &menuSelect);
	/*
    switch-case Statement getting an input from 0 to 4, each choice leads to 
	diffrent case
	*/
	switch (menuSelect) {
	case 1:
		//asking the user to enter a number, saving it as testScore
		printf("Please enter your score:\n");
		scanf("%d", &testScore);
		/*
		ranking the students score(testScore): if it's below 0 or above 100 
		it ranks it generally from A to E
		*/
		if (testScore >= 0 && testScore <= 100) {
			if (testScore >= 90) {
				printf("The rank for %d is: A\n", testScore);
			}
			else if (testScore >= 80) {
				printf("The rank for %d is: B\n", testScore);
			}
			else if (testScore >= 70) {
				printf("The rank for %d is: C\n", testScore);
			}
			else if (testScore >= 60) {
				printf("The rank for %d is: D\n", testScore);
			}
			else {
				printf("The rank for %d is: E\n", testScore);
			}
		}
		// if the user enter testScore above 100 or below 0 it print out error
		if (testScore > 100 || testScore < 0) {
			printf("Error\n");
		}
		break;
	case 2:
		//receive 3 numbers from the user, saving them as num1, num2, num3
		printf("Please enter three numbers:\n");
		scanf(" %d %d %d", &num1, &num2, &num3);
		/*
		arranging the numbers by low, medium and high decides which number is 
		greater from the first two numbers, then decides if the third number is
		low then each one of the two others, and then decides which one is
		the highest number
		*/
		if (num1 > num2) {
			middle = num1;
			low = num2;
		}
		else {
			middle = num2;
			low = num1;
		}
		if (num3 < middle) {
			high = middle;
			if (num3 < low) {
				middle = low;
				low = num3;
			}
		}
		else {
			high = num3;
		}
		//caculates the average by casting the sum of the numbers to a float
		average = ((float)(num1 + num2 + num3) / 3);
		//printing the lowest number, the highest number, and the average
		printf("The minimal value is: %d\n", low);
		printf("The maximal value is: %d\n", high);
		printf("The average is: %.2f\n", average);
		break;
	case 3:
		//scanning 3 chars
		printf("Please enter three chars:\n");
		scanf(" %c %c %c", &a, &b, &c);
		//printing out the asked chars combinations
		printf("%c\n%c\n%c\n%c\n", a, a, b, c);
		printf("%c@%c@%c\n", a, b, c);
		printf("%c\n", c);
		printf("%c#%c#%c\n", c, b, a);
		break;
	case 4:
		//scan test result, exercise result and the student name
		printf("Please enter two course details:\n");
		scanf(" %f %f %c", &csTest1, &csExe1, &s1);
		scanf(" %f %f %c", &csTest2, &csExe2, &s2);
		/*
		gets the score and print out error or final grade 
		(equation of the tests and excersie)  checks if
		the numbers are vaild(betweeen 0 to 100), if so- it caculates the final
		grade and printing
		*/
		if (csTest1 < 0 || csTest1 > 100 || csTest2 < 0 || csTest2 > 100 ||
			csExe1 < 0 || csExe1 > 100 || csExe2 < 0 || csExe2 > 100) {
			printf("Error\n");
		}
		else {
			finGrade1 = 8 * (sqrt(csTest1)) + csExe1*0.1;
			finGrade2 = 8 * (sqrt(csTest2)) + csExe2*0.1;
			printf("The final grade of %c is: %.2f\n", s1, finGrade1);
			printf("The final grade of %c is: %.2f\n", s2, finGrade2);
		}
		break;
	case 0:
		//the program does nothing therefore it ends
		break;
	default:
		printf("You didn't enter the number correctly\n");
	}
	return 0;
}

