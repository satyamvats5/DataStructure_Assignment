/* Write a menu driven program (in C) for complete implementation of stack using array with push, pop and display operation. */



#include<stdio.h>


int top = -1;	//the global variable


int PUSH(int MAX, int STACK[])	// function for push opertion in a stack

{

	int value;


	if(top == MAX-1)

		printf("\nSTACK OVERFLOW\n\n");

	else

	{

		printf("\nEnter a value : ");

		scanf("%d", &value);

		top++;

		STACK[top] = value;

	}

	return 0;

}



int POP(int MAX, int STACK[])	// function for pop operation in the stack

{

	int  value;

	if(top == -1)

		printf("\n\nTHE STACK IS EMPTY\n\n");

	else

	{

		value = STACK[top];

		top--;

		printf("\n%d is deleted from the STACK. \n\n", value);

	}

	return 0;

}



int DISPLAY(int MAX, int STACK[])	// to display the elements in stack

{

	int i;

	if(top == -1)

		printf("\nTHE STACK IS EMPTY\n\n");

	else

	{

		printf("The STACK is : \n");
	
	for(i=top; i>= 0; i--)

			printf("\n\t%d", STACK[i]);

		printf("\n");

	}

	return 0;

}

int MENU(int MAX, int STACK[])	// to implement the menu

{

	int option;

	printf("\n--------------------");

	printf("\n*****MAIN MENU*****");

	printf("\nEnter 1. To PUSH");

	printf("\nEnter 2. To POP");

	printf("\nEnter 3. To DISPLAY");

	printf("\nEnter 4. To EXIT");

	printf("\n____________________\n");

	printf("\nEnter your choice : ");

	scanf("%d", &option);	

	printf("\n--------------------\n\n");

		

	switch(option)

	{

		case 1:

		{

			PUSH(MAX, STACK);

			MENU(MAX, STACK);

		}

		break;


		case 2:

		{

			POP(MAX, STACK);

			MENU(MAX, STACK);

		}

		break;


		case 3:

		{

			DISPLAY(MAX, STACK);

			MENU(MAX, STACK);

		}

		break;


		case 4:

			return 0;
	
	break;


		default:

		{

			printf("\nSorry ...!\nWrong entry...\nPlease enter the correct one.\n\n");

			MENU(MAX, STACK);

		}

		break;

	}

	return 0;
}





int main()

{

	int MAX;

	printf("\nEnter the size of stack : ");

	scanf("%d", &MAX);

	int STACK[MAX];

	MENU(MAX, STACK);

	return 0;

}



