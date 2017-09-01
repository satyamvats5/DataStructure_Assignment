#include <stdio.h>

int main()
{
	int r1, c1, r2, c2, i, j, s1 = 0, s2 = 0;

	printf("Enter no. of rows for first matrix = ");
	scanf("%d",&r1);

	printf("Enter no. of columns for first matrix = ");
	scanf("%d",&c1);

	int A[r1][c1];

	for(i = 0; i < r1; i++) {              // Taking the value of 1st matrix from user
		for(j = 0; j < c1; j++) {
			scanf("%d",&A[i][j]);
		}
	}

	printf("Enter no. of rows for second matrix = ");
	scanf("%d",&r2);

	printf("Enter no. of columns for second matrix = ");
	scanf("%d",&c2);

	int B[r2][c2];

	for(i = 0; i < r2; i++) {
		for(j = 0; j < c2; j++) {      // Takinhg the value of 2nd matrix from user
			scanf("%d",&B[i][j]);
		}
	}

	for(i = 0; i < r1; i++) {			// Calculating the number of non-zero elements of 1st matrix
		for(j = 0; j < c1; j++) {
			if(A[i][j] != 0)
				s1++;
		}
	}

	for(i = 0; i < r2; i++) {			// CAlculating the number of non- zero elemnts of 2nd matrix
		for(j = 0; j < c2; j++) {
			if(B[i][j] != 0) {
				s2++;
			}
		}
	}

	int SP1[s1+1][3];
	int SP2[s2+1][3];
	int e1 = 1, e2 = 1;

	SP1[0][0] = r1, SP1[0][1] = c1, SP1[0][2] = s1;
	SP2[0][0] = r2, SP2[0][1] = c2, SP2[0][2] = s2; 

	for(i = 0; i < r1; i++) {
		for(j = 0; j < c1; j++) {
			if(A[i][j] != 0) {
				SP1[e1][0] = i;
				SP1[e1][1] = j;
				SP1[e1][2] = A[i][j];
				e1++;
			}
		}
	}
	for(i = 0; i < r2; i++) {
		for(j = 0; j < c2; j++) {
			if(B[i][j] != 0) {
				SP2[e2][0] = i;
				SP2[e2][1] = j;
				SP2[e2][2] = B[i][j];
				e2++;
			}
		}
	}
	printf("values of 1st sparse matix are:-\n");
	for(i = 0;i < s1+1; i++) {
		for(j = 0; j < 3; j++) {
			printf("%d ",SP1[i][j]);
		}
		printf("\n");
	}

	printf("values of 2nd sparse matix are:-\n");
	for(i = 0;i < s2 + 1; i++) {
		for(j = 0; j < 3; j++) {
			printf("%d ",SP2[i][j]);
		}
		printf("\n");
	}
	int RES[s1+1][3];
	RES[0][0] = r2, RES[0][1] = c2, RES[0][2] = s2; 

	for(i=1; i < s1 +1 ;i++) {
		for(j=0; j < 3; j++) {
			if(j != 2) {
				RES[i][j] = SP1[i][j];
			} else {
				RES[i][j] = SP1[i][j] + SP2[i][j];
			}
		}
	}
	int c = 1;
	printf("Final matrix=\n");		
	for(i = 0 ; i < RES[0][0]; i++) {
		for(int z = 0; z < RES[0][1]; z++) {
			if( i == RES[c][0] && z == RES[c][1] && c <= RES[0][2]) {
				printf("%d\t",RES[c][2]);
				c++;
			} else 
				printf("0\t");
		}
	    	printf("\n");
	}
			
	return 0;
}
