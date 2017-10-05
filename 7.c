#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int top = -1;

#define MAX 50
typedef enum {false,true} boolean;

boolean isempty(int top) 
{
	if(top == -1) 
		return true;
	else 
		return false;
}

void view(char ARR[MAX]) 
{
	int i;
	int temp = top;
	while(temp>= 0){
		printf("%c\t",ARR[temp]);
		temp--;
	}
	printf("\n");
	
}

char peek(char ARR[MAX], char val) 
{
	return ARR[val];
}

int priority(char c) 
{
	if(c == '/' || c == '*' || c == '%' )
		return 1;
	else 
		return 0;
}
 
void push (char ARR[MAX], char val)
{
	top++;
	ARR[top] = val;
	//printf("Pushed element = %c\n",val);
}

char pop(char  ARR[MAX]) 
{
	char val =  ARR[top];
	top--;
	//printf("Popped elkement = %c\n",val);
	return val;
	
}

int main() 
{
	char *S = calloc(MAX,sizeof(char));
	char *A = calloc(MAX,sizeof(char));
	char *res = calloc(MAX,sizeof(char));

	int l=0,i;

	PRINTF("eNTER THE INFIX EXPRESSION\n");
	fflush(stdin);
	scanf("%s",S);

	ssize_t len = strlen(S);

	fflush(stdout);

	for(i = 0; i < len; i++) {
		if( S[i] == ' '|| S[i] == '\n' )
			continue;
		else if( S[i] == '(' ) {
				push(A,S[i]);
		} else if( S[i] == ')' ) {
			while( (!isempty(top)) && (peek(A,top) != '(') ) {
				res[l] = pop(A);
				l++;
			}
			pop(A);
		} else if( isdigit(S[i]) || isalpha(S[i]) ) {
			res[l] = S[i];
			l++;
		} else if( S[i] == '*' || S[i] == '+' || S[i] == '/' || S[i] == '-') {
			while( (!isempty(top)) && (peek(A,top) != '(') && ( (priority(S[i])) <= (priority(peek(A,top)))) ) {
				res[l] = pop(A);
				l++;
			}
			push(A,S[i]);
		} else {
			printf("Incorrect expression is given\n");
			return 0;
		}
	}

	while((!isempty(top)) && (peek(A,top) != '(')) {
		res[l] = pop(A);
		l++;
		
	} 

	if(peek(A,top) == '(') {
		printf("Invalid expression\n");
		return 0;
	}

	res[l] ='\0';
	printf("%s\n",res);

	return 0;
}
		
