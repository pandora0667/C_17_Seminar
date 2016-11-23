#include <stdio.h>
#include <stdlib.h>

#define SIZE 100 

int main()
{
	char **string = NULL; 
	int count, i ; 

	printf("문자열의 개수 : "); 
	scanf("%d", &count);

	if( string = malloc(count*sizeof(char *)) != NULL )
		for( i =0; i<count; i++) 
		{
			string[i] = (char *)malloc(SIZE);
			if( string == NULL )
			{
				fprintf(stderr, "%d 크기의 동적할당 실패 \n", SIZE); 
				exit(1);
			}
		}
	else 
	{
		fprintf(stderr, "동적메모리 할당 실패 \n"); 
		exit(1);
	}

	printf("%d개의 문자열을 저장할 수 있는 공간이 할당되었습니다. \n"); 

	free(string);

	return 0;
}



