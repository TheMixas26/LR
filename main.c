#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int LR1(void);
int LR2(void);
int LR3(void);
int LR4(void);
int LR5(void);
int add1(void);

int main(void) {
	srand(time(NULL));
	int choice;

	do {
		system("chcp 65001 > nul");
		printf("\n");
		printf("==== ЛАБОРАТОРНЫЕ РАБОТЫ ====\n");
		printf("1. Лабораторная работа 1\n");
		printf("2. Лабораторная работа 2\n");
		printf("3. Лабораторная работа 3\n");
	        printf("4. Лабораторная работа 4\n");
	        printf("5. Лабораторная работа 5\n");
		printf("-1. Дополнительная задача ЛР4\n");
		printf("0. Выход\n");
		printf("Выберите номер лабораторной работы: ");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
			LR1();
			break;
		case 2:
			LR2();
			break;
		case 3:
			LR3();
			break;
	        case 4:
			LR4();
			break;
	        case 5:
			LR5();
			break;
		case 0:
			printf("Завершение работы.\n");
			break;
	        case -1:
			add1();
			break;
		default:
			printf("Такой лабораторной работы нет.\n");
		}
	} while (choice != 0);


	return 0;
}
