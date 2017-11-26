#include <stdio.h>

int main()
{
	int j,i,A[5],temp;
	for(i=0;i<5;i++) {
		scanf("%d",&A[i]);
	}
	//int steps=0;
	for(i=0;i<4;i++) {
		//steps++;
		int swap=0;
		for(j=0;j<4-i;j++) {
			//steps++;
			if(A[j]>A[j+1]){
				swap++;
				temp=A[j];
				A[j]=A[j+1];
				A[j+1]=temp;
			}
		}
		if(swap ==0) 
			break;
	}
	for(i=0;i<5;i++)
		printf("%d ",A[i]);
	printf("\n");
	//printf("Steps taken =%d\n",steps);
	return 0;
}
