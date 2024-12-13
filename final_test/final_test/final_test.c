// final_test.c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_SIZE 100

typedef struct
{
	char name[20];	// 이름
	int kor_score;	// 국어
	int eng_score;	// 영어
	int mat_score;	// 수학
} Student;

int main(void)
{
	// 구조체 사용하기
	Student students[MAX_SIZE];
	int std_count = 0, 
		menu_num;

	FILE* p_file;
	char* filename = "students.dat";

	while (1)
	{
		printf("[Menu]\n");
		printf("1. .dat 파일에서 데이터 읽기\n");
		printf("2. 추가 학생 정보 입력\n");
		printf("3. .dat 파일 저장\n");
		printf("4. 성적 확인 (평균 계산 등)\n");
		printf("5. 종료\n");
		printf("-------------------\n");
		printf("선택(1~5): ");
		scanf_s("%d", &menu_num);

		// 5를 입력했으면 프로그램 종료
		if (menu_num == 5) break;

		switch (menu_num)
		{
		case 1:
			p_file = fopen(filename, "rb");
			if (NULL != p_file)
			{
				fread(students, sizeof(Student), MAX_SIZE, p_file);
				fclose(p_file);
			}
			break;
		case 2:
			printf("\n");
			printf("학생 이름: ");
			scanf_s("%s", students[std_count].name, sizeof(students[std_count].name));
			printf("국어 점수: ");
			scanf_s("%d", &students[std_count].kor_score);
			printf("영어 점수: ");
			scanf_s("%d", &students[std_count].eng_score);
			printf("수학 점수: ");
			scanf_s("%d", &students[std_count].mat_score);
			printf("\n");
			std_count++;
			break;
		case 3:
			p_file = fopen(filename, "wb");
			if (NULL != p_file)
			{
				fwrite(students, sizeof(Student), std_count, p_file);
				fclose(p_file);
				
			}
			break;
		case 4:
			p_file = fopen(filename, "rb");
			if (NULL != p_file)
			{
				std_count = fread(students, sizeof(Student), MAX_SIZE, p_file);

				printf("-------------------------------------------------------\n");
				printf(" 이름  국어  영어  수학  총점  평균  등수\n");
				printf("-------------------------------------------------------\n");

				for (int i = 0; i < std_count; i++)
				{
					int total = students[i].kor_score + students[i].eng_score + students[i].mat_score;
					int avg = total / 3;

					printf("%s  %d    %d    %d    %d    %d    %d등\n",
						students[i].name, students[i].kor_score, students[i].eng_score, students[i].mat_score, total, avg, i + 1);
				}

				printf("\n");
			}
			break;
		default:
			printf("1~5 번호만 선택할 수 있습니다!!\n\n");
		}
	}

	return 0;
}