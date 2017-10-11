

#define MAX 20


typedef struct node {
	int A[MAX];
	int rear;
	int front;
}node;

node list;

#ifndef __stdlib_h
#include <stdlib.h>
#endif
#ifndef __stdbool_h
#include <stdbool.h>
#endif
#ifndef __stdio_h
#include <stdio.h>
#endif

int menu();

void insert(int);

bool is_empty();

bool is_full();


int delete();

int display();

