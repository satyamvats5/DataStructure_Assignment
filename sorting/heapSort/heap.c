#include "includes/helper.c"

int main()
{
	int i,n;

	printf("Enter how many numbers you want to enter: ");
	scanf("%d",&n);
	
	int * A = calloc(n+2,sizeof(int));

	for(i = 1; i < n+1; i++) {
		scanf("%d",&A[i]);
	}
	
	heapSort(A,n);	//calling of heapSort function
	
	for(i = 1; i <= n; i++ ) {
		printf("%d  ",A[i]);
	}
	printf("\n");

	return 0;
}
