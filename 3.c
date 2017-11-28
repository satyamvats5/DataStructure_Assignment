#include<stdio.h>
#include<stdlib.h>

int main()
{	
	while(1) {
		int row,col,temp;
	
		printf("Enter the upper limit of row:- ");
		scanf("%d", &row);
	
		printf("Enter the upper limit of col:- ");	
		scanf("%d", &col);
	
		int ARR[row][col];
		int rowpos,colpos;
	
		printf("Enter the row number and column number respectively :- ");
		scanf("%d %d", &rowpos,&colpos);
	
		unsigned int val1 ;
	
		printf("Enter base address : "); 

		scanf("%d",&val1);

		int row_add, col_add;
		row_add = val1 + (col * rowpos + colpos)*sizeof(int);    // Calculation of adress in row order.
		printf("%u\n" ,row_add);            //Printing of address in row order.
		printf("\n");
	
		printf("Address of your desird position in column order = ");
		col_add = val1 + (row * colpos + rowpos)*sizeof(int); 		//calculation of address in column order.
		printf("%u\n\n" ,col_add);		// Printing of address in column order.
		
		printf("\tTo know more address enter :-1 \n \tPress 0 to exit ");
		scanf("%d",&temp);
		if(temp == 0) {
			return 0;
		}
	}
}	

