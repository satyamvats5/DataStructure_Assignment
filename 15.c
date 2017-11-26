#include <stdio.h>
#include <stdlib.h>
typedef struct node {
int data;
struct node *next;
}node;
node *list = NULL;
void ins_beg() {
int x;
scanf("%d",&x);
node *p;
p = (node *)malloc(sizeof(node));
p->data = x;
p->next = list;
list = p;
}
void del_beg(){
node *p;
p = list;
int x = p->data;
printf("%d is deleted\n",x);
list = p->next;
free(p);
}
void display() {
int c = 0;
node *p = list;
while(p != NULL) {
c++;
int y = p->data;
printf("%d ",y);
p = p->next;
}
printf("\n");
}
int main()
{
int n;
int choice;
do
{
printf("1)Insert \n2)Delete \n3)Display\n4)Exit\n");
scanf("%d",&choice);switch(choice)
{
case 1:
ins_beg();
break;
case 2:
del_beg();
break;
case 3:
display();
break;
case 4:
exit(0);
}
}while(choice!=4);
return 0;
}
