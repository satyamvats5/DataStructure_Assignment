#include <stdio.h>

int main()
{
	int j,i,A[5],smallest,temp;
	for(i=0;i<5;i++) {
		scanf("%d",&A[i]);
	}
	
	for(i=0;i<5;i++) {
		smallest=i;
		for(j=0+i;j<5;j++) {
			if( A[j] < A[smallest]) {
				smallest =j;
			}
		}
		if(smallest != i) {
			temp= A[i];
			A[i]=A[smallest];
			A[smallest]=temp;
		}		
	}
	for(i=0;i<5;i++) {
		printf("%d ",A[i]);
	}
	printf("\n");
	return 0;
}	
