//Seminar Chapter 17 

#include <stdio.h>
#include <stdlib.h> 

int main()
{
	int count, sum, i; 
	int *number = NULL; 

	printf("정수의 갯수 입력 : "); 
	scanf("%d" , &count); 

	number = (int *)malloc( sizeof(int) * count );
	if(number == NULL) 
	{
		fprintf(stderr, "동적 할당 실패 \n"); 
		exit(1);
	}

	for( i=0; i<count; i++)
		scanf("%d", &number[i]);

	for( i=0; i<count; i++)
		sum += number[i];

	printf("Sum = %d \n", sum);

	free(number); 

	return 0; 
}

