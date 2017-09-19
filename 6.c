#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 15

int top = -1;

typedef enum {false,true} boolean;

void push (char ARR[MAX], char val)
{
	top++;
	ARR[top] = val;
}

int isEmpty()
{
	if(top == -1) {
			return 1;
	} else 
		return 0;
}

int isFull()
{
	if(top == MAX-1) {
		return 1;
	}
	else 
		return 0;
}

int braces_checker(char c1,char c2) 
{
	if( c1 == '[') 	{
		if( c2 == ']') 
			return 1;
		else 
			return 0;
	}
	
	if( c1 == '{') {
		if(c2 == '}') 
			return 1;
		else 
			return 0;
	}
	
	if(c1 == '(') {
		if(c2 == ')' ) 
			return 1;
		else 
			return 0;
	}
}

char pop(char  ARR[MAX]) 
{
	char val =  ARR[top];
	top--;
	return val;
	
}
			
int main()
{
	int i;

	char *S = calloc(50,sizeof(char));	
	char *A = calloc(MAX,sizeof(char));

	printf("ENter the expression to be checked:-\n");
	scanf("%s",S);

	ssize_t len = strlen(S);

	for(i = 0; i < len; i++) {
		if(S[i] == '{' || S[i] == '[' || S[i] == '(' ) {
			int z = isFull();

			if(z == 0) 
				push(A,S[i]);
			else {
				printf("Stack overflow\n");
				return 0;
			}
	
		} else if( S[i] == '}' || S[i] == ']' || S[i] == ')') {
			if( isEmpty()) {
				printf("Not valid\n");
				return 0;
			} else {
				int z = isEmpty();
				if(z == 0) {
					char c = (char)pop(A);
					int l = braces_checker(c,S[i]);
					if(l == 0) 
					{
						printf("Not valid\n");
						return 0;
					}
				}
			}
		}
	}
	if(isEmpty()) 
		printf("True expression\n");
	else 
		printf("Not valid\n");
	
	return 0;
}
