#define MAX 10
#include <stdio.h>

void insertion(int a,int A[a])
{
	printf("Welcome to program of insertion sort\n");
	int i,j,k;
	for(i=0;i<a;i++) {
		j = A[i];
		k = i-1;
		while(k >= 0 && A[k] > j) {
			A[k+1] = A[k];
			k = k-1;
		}
		A[k+1] =  j;
	}
}
int main()
{
	int i,j;
	int ARR[MAX];
	printf("enter the number of elements to be inserted into the original array\n for selection sort:-");
	scanf("%d",&i);
	for(j=0;j<i;j++) {
		scanf("%d",&ARR[j]);
	}
	insertion(i,ARR);
	for(j=0;j<i;j++) {
		printf("%d\t",ARR[j]);
	}
	printf("\n");
	return 0;
}
