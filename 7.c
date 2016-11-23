// Seminar Chapte 17 
#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 

#define S_SIZE 100

typedef struct movie { 
	char title[S_SIZE];
	int year;
	struct MOVIE *link; 
} MOVIE; 

int main()
{
	MOVIE *list; 
	MOVIE *prev, *linkMovie, *next; 

	char buffer[S_SIZE]; 
	int tmpYear, select; 

	printf("\t ----------연결 리스트를 활용한 영화 정보 출력----------\n\n\n");
	
	while(1)
	{
		printf("-------------------------------------------\n");
		printf(" 1. 영화정보 추가\n 2. 영화정보 출력\n 3. 종료 \n");
		scanf("%d", &select); 

		if( select == 3 )
			break; 

		linkMovie = ( MOVIE * )malloc( sizeof(MOVIE) ); 
		if( linkMovie == NULL ) 
		{
			fprintf(stderr, "동적할당 실패\n");
			exit(1); 
		}

		switch ( select ) 
		{
			case 1 : 
				   printf("영화 제목 : ");
				   fgets(buffer, S_SIZE, stdin); 
				   strcpy(linkMovie -> title, buffer);

				   printf("영화 개봉 연도 : ");
				   fgets(buffer, S_SIZE, stdin);
				   tmpYear = atoi(buffer); 
				   linkMovie -> year = tmpYear;

				   if( list == NULL)
					  list = linkMovie;
				   else 
					   prev -> link = linkMovie; 
				   
				   linkMovie -> link = NULL; 
				   prev = linkMovie; 

				   break;
			case 2 :
				   printf("\n\n");
				   while( linkMovie != NULL) 
				   {
					   printf("\t  %s \t %d 개봉\n", linkMovie -> title, linkMovie -> year);
					   linkMovie = linkMovie -> link; 
				   }
				   break; 
			case 3 : 
					printf("종료 합니다. \n\n");
					return 0; 
			default :
					printf("Retry!!\n");
		}

		linkMovie = list;
	}

	while( linkMovie != NULL )
	{
		next = linkMovie -> link;
		free(linkMovie); 
		linkMovie = next;
	}

	return 0; 
}
