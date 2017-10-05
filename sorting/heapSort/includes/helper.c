# include "helper.h"


void heapSort(int A[],int n) 
{
	buidMaxHeap(A,n);	//calling buildMaxHeap to build the max heap

	int i;

	for(i = n; i >= 2; i--) {

		swap(&A[1],&A[i]);	//calling swap to swap the two values
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

void maxHeapify(int A[],int n,int i)		// To arrnge the nodes according to property of MAX-NODE
{
	int l = left(i);	// to get the index of left child node.
	int r = right(i);	// to get the indices of right child node
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

		swap(&A[i],&A[largest]);	

		maxHeapify(A,n,largest);	// calling itself recursively if the nodes have been interchanged.
	}	
	
}

void buidMaxHeap(int A[],int n) 
{
	int i;

	for(i = n/2; i > 0; i-- ) {
		maxHeapify(A,n,i);
	}
}
 
void swap(int *i, int * j) 
{
	int temp;
	temp = *i;
	*i = *j;
	*j = temp;
}
