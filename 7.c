// Seminar Chapte 17 
#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 

#define S_SIZE 100

typedef struct MOVIE { 
	char title[S_SIZE];
	int year;
	struct MOVIE *link; 
} MOVIE; 

int main()
{
	MOVIE *head = NULL; 
	MOVIE *tail, *addMovie, *next, *tmp; 

	char buffer[S_SIZE]; 
	int tmpYear, select; 

	printf("\t ----------연결 리스트를 활용한 영화 정보 출력----------\n\n\n");
	
	while(1)
	{
		printf("-------------------------------------------\n");
		printf(" 1. 영화정보 추가\n 2. 영화정보 출력\n 3. 종료 \n");
		scanf("%d", &select);  

		addMovie = ( MOVIE * )malloc( sizeof(MOVIE) ); 
		if( addMovie == NULL ) 
		{
			fprintf(stderr, "동적할당 실패\n");
			exit(1); 
		}

		switch ( select ) 
		{
			case 1 :
				getchar();
				printf("영화 제목 : ");
				fgets(buffer, S_SIZE, stdin); 
				strcpy(addMovie->title, buffer);

				printf("영화 개봉 연도 : ");
				fgets(buffer, S_SIZE, stdin);
				tmpYear = atoi(buffer); 
				addMovie->year = tmpYear;

				if( head == NULL)
					 head = addMovie;
				else 
					tail -> link = addMovie;

				addMovie->link = NULL; 
				tail = addMovie; 
				break;

			case 2 :
				printf("\n\n");
				system("clear");
				tmp = head;
				while( tmp != NULL) 
				{
					 printf("영화 : %s, %d년 개봉\n", tmp->title, tmp->year);
					 tmp = tmp -> link; 
				}
				break;

			case 3 : 
				printf("종료 합니다. \n\n");
				return 0; 
			default :
				printf("Retry!!\n");
		}
	}
	tmp = head; 

	while( tmp != NULL )
	{
		next = tmp->link;
		free(tmp); 
		tmp  = next;
	}

	return 0; 
}
