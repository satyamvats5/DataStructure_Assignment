#include "9.c"


node list;

int main()
{	
	list.rear = list.front = -1;
	
	int val;
	int i;
	while(1){
		val = menu();
		
		switch(val) {
		
		
			case 1:
				if(!is_full()) {
					printf("Enter the value to be inserted\n");
					scanf("%d",&i);
					insert(i);
				} else {
					printf("The Queue is full :(\n");
				}
				break;
			case 2:
				if(!is_empty()) {
					i = delete();
					printf("Deleted element is: %d\n",i);
				} else {
					printf("The queue is empty :(\n");
				}
				break;
			case 3:
				if(!is_empty()) {
					printf("Elements of arrays are as follows :)\n");
					display();
				} else {
					printf("The queue is empty :(\n");
				}
				
				break;
			default:
				printf("Thanks for using program\n");
				return 0;
			
		}
	}
	return 0;
}
