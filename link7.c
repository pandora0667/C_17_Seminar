#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define S_SIZE 100

typedef struct MOVIE { 
	char title[S_SIZE]; 
	int year; 
	struct MOVIE *link;
} MOVIE; 

void inputMovie(MOVIE **head, MOVIE **tail);
void printMovie(MOVIE **head);
int selectMenu(int select);
void memoryFree(MOVIE **head);
void filePrint(MOVIE **head);

int main()
{
	
	MOVIE *head = NULL, *tail;
	int select = 0; 
	
	printf("\t ----------연결 리스트를 활용한 영화 정보 출력----------\n\n\n");

	while(1)
	{
		select = selectMenu(select); 

		switch( select ) 
		{
			case 1: 
				inputMovie(&head, &tail);
				break; 
			case 2:
				printMovie(&head);
				break; 
			case 3:
				filePrint(&head);
				break; 
			case 4:
				printf("종료합니다. \n");
				return 0; 
			default :
				printf("Retry!!\n");
		}
	}

	memoryFree(&head);
	return 0; 
}

int selectMenu(int select)
{
	printf("-------------------------------------------\n");
	printf(" 1. 영화정보 추가\n 2. 영화정보 출력\n 3. 파일 저장 \n 4. 나가기\n");
	scanf("%d", &select);

	return select;
}

void inputMovie(MOVIE **head, MOVIE **tail)
{
	static MOVIE *addMovie; 

	if ( (addMovie = ( MOVIE* )malloc( sizeof(MOVIEr) )) == NULL )
	{
		fprintf(stderr, "동적할당 실패\n");
		exit(1);
	}

	getchar();
	printf("영화 제목 : ");
	fgets(addMovie -> title, S_SIZE, stdin);
	addMovie -> title [strlen(addMovie -> title) - 1] = '\0';

	printf("영화 개봉 연도 : ");
	scanf("%d", &addMovie -> year);

	if( (*head) == NULL)
		(*head) = addMovie;
	else 
		(*tail) -> link = addMovie;
	
	addMovie->link = NULL;
	(*tail) = addMovie;
}

void printMovie(MOVIE **head) 
{
	MOVIE *tmp;
	tmp = (*head);

	printf("\n\n");
	system("clear");

	while( tmp != NULL)
	{
		printf("영화 : %s, %d년 개봉\n", tmp->title, tmp->year);
		tmp = tmp -> link;
	}
}

void memoryFree(MOVIE **head)
{
	MOVIE *tmp;
	tmp = (*head);

	while( tmp != NULL)
	{
		tmp = tmp -> link; 
		free(tmp);
	}
}

void filePrint(MOVIE **head)
{
	MOVIE *tmp; 
	tmp = (*head); 
	FILE *fp; 

	if( (fp = fopen("MovieInfo.txt", "w")) == NULL)
	{
		fprintf(stderr, "파일을 생성할 수 없습니다\n");
		exit(1);
	}

	while( tmp != NULL)
	{
		fprintf(fp, "제목 : %s, 개봉일 : %d \n", tmp -> title, tmp -> year );
		tmp = tmp -> link;
	}
	system("clear");
	printf("\n정상적으로 저장되었습니다.\n");
}

