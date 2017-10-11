#include "9.h"

int menu()
{
	int i;
	printf("MENU\n");
	printf("eNTER 1 TO INSERT\n");
	printf("Enter 2 to delete\n");
	printf("eNTER 3 TO display\n");
	printf("Enter any other character to exit\n");
	scanf("%d",&i);
	
	return i;
}

void insert(int i)
{
	if(list.front == -1  && list.rear  == -1) {
			list.rear = 0;
			list.front = 0;
			list.A[list.rear] = i;
		} else {
			list.rear =  list.rear + 1;
			list.A[list.rear] = i;
		}
		
}

int delete()
{
	int temp = list.front;
	list.front = list.front + 1;
	return list.A[temp];
}

bool is_empty()
{
	return (list.front == list.rear ==  -1 || list.front > list.rear)? true: false;
} 

bool is_full()
{
	return (list.rear == MAX - 1)? true:false;
} 

int display () 
{
	int i;
	for(i = list.front; i <= list.rear; i++ ) {
		printf("%d  ",list.A[i]);
	}
	printf("\n");
}


