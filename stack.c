#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX 15

int top = -1;

void push (int ARR[MAX], int val)
{
	top++;
	ARR[top] = val;
}

int pop(int ARR[MAX]) 
{
	int val =  ARR[top];
	top--;
	return val;
	
}

void view(int ARR[MAX]) 
{
	int i;
	int temp = top;
	while(temp>= 0){
		printf("%d\t",ARR[temp]);
		temp--;
	}
	printf("\n");
	
}

void pause_t() 
{
	printf("Enter a character to continue:");
	getchar();
	getchar();
}

int menu() 
{
	int val;
	
	printf("*************************  MENU OPTIONS *****************\n");
	printf("      Enter 1 to PUSH an Element into STACK\n");
	printf("      Enter 2 to POP an element from STACK \n");	
	printf("      Enter 3 to DISPLAY all the elemnts of STACK\n");
	printf("      ENter any other element to exit the program\n");
	
	scanf("%d",&val);
	return val;
}
	
void refresh()
{
	write(STDOUT_FILENO, "\x1b[2J",4 );
	write(STDOUT_FILENO, "\x1b[H",3);
}

int main()
{
	int *ARR = calloc(10,sizeof(int));
	refresh();
	
	while(1) {
	
	int data,val,num;
	data = menu();
	
		switch(data) {
		
			case 1:
				scanf("%d",&val);		
				push(ARR,val);
				break;
			case 2:
				num = pop(ARR);
				printf("\n Popped element is = %d\n",num);
				pause_t();
				break;
			case 3:
				view(ARR);
				pause_t();
				break;
			default :
				exit(1);
		}
		refresh();
	}
	return 0;
	
}
