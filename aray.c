#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int n=0,max =25,flagg=0;

void insert(int pos, int val, int ARR[max])
{
	int temp,j;
	temp = ARR[pos];
	if(pos == n) {
		if( flagg == 0) { 
			flagg =1;
                }
		ARR[pos] = val;
		n++;
	} else {
		temp = ARR[pos];
		ARR[pos] = val;
		for( j = n; j > pos; j-- )
        		ARR[j] = ARR[j-1];
		ARR[j+1] = temp;
		n++;
	}
}       

int check() 
{
	if(n == 0 && flagg == 0) {
		return 1;
        } else if(n == max-1) { 
		return 0;
        }
}

void delete (int pos,int ARR[max]) 
{
	int j;
	printf("Deleted element is :-%d\n",ARR[pos]);
	if( pos == n) {
		n--;
	} else {
		for(j= pos; j< n-1; j++) {
			ARR[j] = ARR[j+1];
                }
			n--;
	}
}

void display(int ARR[max]) 
{
	int j;
	for( j=0 ;j < n; j++) {
		printf("%d ",ARR[j]);
	}
	printf("\n");
}

void refresh()
{
	write(STDOUT_FILENO, "\x1b[2J",4 );
	write(STDOUT_FILENO, "\x1b[H",3);
}
	 
int main()
{
	int *ARR = calloc(50,sizeof(int));
	
	int i,pos,val;
	refresh();
	printf("          WELCOME TO OUR PROGRAM\n");
	while(1) {
	printf("          Please choose from available options:-\n");
	printf("****************************************************\n");
	printf("     ENTER 1 TO INSERT\n");
	printf("     Enter 2 To delete\n");
	printf("     ENTER 3 TO displaqy\n");
	printf("     Enter 4 To exit\n");
	scanf("%d",&i);
	switch(i) {
		case 1:
				printf("Enter position and value to be inserted :  ");				
				int flag = check();
				if(flag == 0 ){
					printf("Array is full\n");
					printf("Enter a character to continue :");
					getchar(); getchar();
					break;
				}
				scanf("%d %d",&pos,&val);
				insert(pos,val,ARR);
				break;
		case 2:
			printf("Enter position from which we need to perform deletion: \n");
			scanf("%d",&pos);
			int flag1 = check();
			if(flag1 == 1) { 
				printf("Array is empty\n");
				printf("Enter a character to continue :");
				getchar(); getchar();
				break;
			}
			delete(pos,ARR);
			break;
		case 3:
			printf("Elements of arrays are as follows\n");
			display(ARR);
			printf("Enter a character to continue :");
			getchar(); getchar();
			break;
		case 4:
			printf("Thanks for using program\n");
			return 0;
			
		}
		refresh();
	
	}
	return 0;
}
