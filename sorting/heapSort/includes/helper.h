#include <stdio.h>
#include <stdlib.h>

void heapSort(int A[],int);

int parent(int);

int left(int);

int right(int);

void maxHeapify(int A[],int,int);

void buidMaxHeap(int A[],int);

void swap(int *, int *);
