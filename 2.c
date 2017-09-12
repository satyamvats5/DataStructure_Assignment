#include <stdio.h>
int main()
{
	int limit1, limit2, m, n, i = 0,j = 0, k, l;

	printf("Enter the array limit for 1st array\n");
	scanf("%d",&limit1);
	int array1[limit1];

	printf("Enter the elemets of 1st array:-\n");
	for(m = 0; m < limit1; m++) {
		scanf("%d",&array1[m]);
	}
	
	printf("ENter the array limit for 2nd array\n");
	scanf("%d",&limit2);
	int array2[limit2];
	
	printf("Enter elements of 2nd array\n");
	for(n = 0; n < limit2;n++) {
		scanf("%d",&array2[n]);
	}
		
	int array3[limit1 + limit2];
	
	for( k = 0; k < limit1 +  limit2; k++) {
		if(j<limit2 && i < limit1) {
			if(array1[i] > array2[j]) {
				array3[k] = array2[j];
				j++;
				continue;
			} else {
				array3[k] = array1[i];
				i++;
				continue;
			}
		}

		if((j == limit2) && (i < limit1)) {
			array3[k] = array1[i];
			i++;
			continue;
		}
		
		if((i == limit1) && (j < limit2)) {
			array3[k] = array2[j];
			j++;
			continue;
		}
	}

	for(i = 0; i < limit1 + limit2; i++) {
		printf("%d ",array3[i]);
	}
	printf("\n");
	
	return 0;
} 

	
