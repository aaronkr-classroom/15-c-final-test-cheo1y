// final_test.c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_SIZE 100

typedef struct
{
	char name[20];	// �̸�
	int kor_score;	// ����
	int eng_score;	// ����
	int mat_score;	// ����
} Student;

int main(void)
{
	// ����ü ����ϱ�
	Student students[MAX_SIZE];
	int std_count = 0, 
		menu_num;

	FILE* p_file;
	char* filename = "students.dat";

	while (1)
	{
		printf("[Menu]\n");
		printf("1. .dat ���Ͽ��� ������ �б�\n");
		printf("2. �߰� �л� ���� �Է�\n");
		printf("3. .dat ���� ����\n");
		printf("4. ���� Ȯ�� (��� ��� ��)\n");
		printf("5. ����\n");
		printf("-------------------\n");
		printf("����(1~5): ");
		scanf_s("%d", &menu_num);

		// 5�� �Է������� ���α׷� ����
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
			printf("�л� �̸�: ");
			scanf_s("%s", students[std_count].name, sizeof(students[std_count].name));
			printf("���� ����: ");
			scanf_s("%d", &students[std_count].kor_score);
			printf("���� ����: ");
			scanf_s("%d", &students[std_count].eng_score);
			printf("���� ����: ");
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
				printf(" �̸�  ����  ����  ����  ����  ���  ���\n");
				printf("-------------------------------------------------------\n");

				for (int i = 0; i < std_count; i++)
				{
					int total = students[i].kor_score + students[i].eng_score + students[i].mat_score;
					int avg = total / 3;

					printf("%s  %d    %d    %d    %d    %d    %d��\n",
						students[i].name, students[i].kor_score, students[i].eng_score, students[i].mat_score, total, avg, i + 1);
				}

				printf("\n");
			}
			break;
		default:
			printf("1~5 ��ȣ�� ������ �� �ֽ��ϴ�!!\n\n");
		}
	}

	return 0;
}