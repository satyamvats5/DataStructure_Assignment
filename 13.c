#include <stdio.h>
#include <stdlib.h>
struct node
{
int data;
struct node *next;
};
struct node *start=NULL;
struct node *creat(struct node*);
struct node *display(struct node*);
struct node *delete_beg(struct node *);
struct node *delete_end(struct node *start);
struct node *insert_beg(struct node *start);
int main(void)
{
int option;
printf("1.creat a link list\n2.display link list\n3.insert at the bigning\n4.delete from the begning\n5.delete from the end\n");
printf("enter your option\n");
scanf("%d",&option);
do
{
switch(option)
{
case 1:
start=creat(start);
break;
case 2:
start=display(start);
break;
case 3:
start=insert_beg(start);
break;
case 4:
start=delete_beg(start);
break;
case 5:
start=delete_end(start);
break;/*
case 6:
start=reverse(start);*/
}
printf("1.creat a link list\n2.display link list\n3.insert at the bigning\n4.delete from the begning\n5.delete from the end\n");
printf("enter your option\n");
scanf("%d",&option);
} while(option!=-1);
}
struct node *creat(struct node *start)
{
int num;
struct node *ptr,*new_node;
new_node=(struct node*)malloc(sizeof(struct node));
printf("enter the data\n");
scanf("%d",&num);
new_node->data=num;
if(start==NULL)
{
start=new_node;
new_node->next=start;
}
else
{
ptr=start;
while(ptr->next!=start)
ptr=ptr->next;
ptr->next=new_node;
new_node->next=start;
}
return start;
}
struct node *display(struct node *start)
{
struct node *ptr;
if(start==NULL)
printf("linl list is empty\n");
else
{
ptr=start;
while(ptr->next!=start)
{
printf("\t%d",ptr->data);
ptr=ptr->next;
}
printf("\t%d",ptr->data);
printf("\n");
}
return start;
}
struct node *insert_beg(struct node *start)
{
int num;printf("enter the data\n");
scanf("%d",&num);
struct node *new_node,*ptr;
ptr=start;
new_node=(struct node*)malloc(sizeof(struct node));
new_node->data=num;
new_node->next=start;
while(ptr->next!=start)
ptr=ptr->next;
ptr->next=new_node;
start=new_node;
return start;
}
struct node *delete_end(struct node *start)
{
struct node *ptr,*preptr;
if(start==NULL)
printf("link list is empty\n");
else
{
ptr=start;
preptr=ptr;
while(ptr->next!=start)
{
preptr=ptr;
ptr=ptr->next;
}
preptr->next=start;
free(ptr);
}
return start;
}
struct node *delete_beg(struct node *start)
{
struct node *ptr,*preptr;
ptr=start;
while(ptr->next!=start)
ptr=ptr->next;
ptr->next=start->next;
ptr=start;
start=start->next;
free(ptr);
return start;
}
