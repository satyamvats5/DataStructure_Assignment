#include <stdio.h>

void merge1(int A[],int l,int m,int mid) 
{
	int N1= mid-l+1;
	int N2=m-mid;
	int L[N1],R[N2];
	for(int i=0;i<N1;i++) {
		L[i] = A[l+i];		//Constructing left matrix
	}
	for(int i=0;i<N2;i++) {
		R[i]=A[mid+1+i];	////Constructing right matrix
	}
	int i1=0,i2=0,i3=l;
	while(i1 < N1 && i2 < N2) {  	// merging of two halves if both left and right matrix are present.
		if(L[i1] < R[i2] ) {
			A[i3] = L[i1];
			i1++; i3++;
		} else {
			A[i3] = R[i2];
			i3++; i2++;
		}
	}
	while(i1 < N1) {		//Merging when only left matrix is present.
		A[i3] = L[i1];
		i3++; i1++;
	}
	while(i2 < N2) {		//Merging when only right matrix is present.
		A[i3] = R[i2];
		i3++; i2++;
	}
	return ;
}

void merge(int ARR[],int l,int m,int n) 
{
	if(n<2) 	//Base critera
		return;
	else {
		int mid = l+(m-l)/2;
		merge(ARR,l,mid,(mid-l)+1);	//Recursion using left half 
		merge(ARR,mid+1,m,(m-(mid+1))+1); //Recursion using right half
		merge1(ARR,l,m,mid);		//Merging both left and right halves
	}
}	

int main()
{
	int i,A[6];
	printf("Enter six values to be inserted into the aary : ");
	for(i=0;i<6;i++) {
		scanf("%d",&A[i]);
	}
	printf("Original array is : ");
	for(i=0;i<6;i++) {
		printf("%d ",A[i]);
	}
	printf("\n");
	int l=0,m=5,num=6;
	merge(A,l,m,num);
	printf("Sorted array is as follows : ");
	for(i=0;i<6;i++) {
		printf("%d ",A[i]);
	}
	printf("\n");
	
	return 0;	
}
