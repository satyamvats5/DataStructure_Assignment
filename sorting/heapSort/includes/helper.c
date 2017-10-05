# include "helper.h"

void heapSort(int A[],int n) 
{
	printf("HeapSort accessed\n");
	buidMaxHeap(A,n);
	printf("MAx heap built\n");
	for(int j =1;j<=n ;j++) 
		printf("%d  ",A[j]);	
	printf("\n");
	int i;
	for(i = n; i >= 2; i--) {
		int temp = A[1];
		A[1] = A[i];
		A[i] = temp;
		n--;
		maxHeapify(A,n,1);
	}
		
}

int parent(int i) 
{
	return i/2;
}

int left(int i)
{
	return 2*i;
}

int right(int i) 
{
	return (i*2 + 1);
}

void maxHeapify(int A[],int n,int i)
{
	int l = left(i);
	int r = right(i);
	int largest;
	if( l <= n && A[l] > A[i]) {
		largest = l;
	} else {
		largest = i;
	}
	if( r <= n && A[r] > A[largest]) {
		largest = r;
	}
	if( largest != i) {
		int temp;
		temp = A[i];
		A[i] = A[largest];
		A[largest] = temp;
		maxHeapify(A,n,largest);
	}	
	
}

void buidMaxHeap(int A[],int n) 
{
	int i;
	for(i = n/2; i > 0; i-- ) {
		maxHeapify(A,n,i);
	}
}
 
