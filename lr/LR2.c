#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Functions.h"

int LR2(void) {
	int N;
	int count = 0;
	double difference;

	system("chcp 1251 > nul");
	srand((unsigned int)time(NULL));

	printf("Введите размер массива (целое число больше нуля): ");
	if (scanf("%d", &N) != 1 || N <= 0) {
		printf("Ошибка: размер массива должен быть больше 0!\n");
		return 1;
	}

	double* first = create_array(N);
	if (first == NULL) {
		printf("Ошибка: не удалось выделить память!\n");
		return 1;
	}

	fill_array(first, N);

	printf("Исходный массив:\n");
	print_array(first, N);

	difference = find_difference(first, N);
	printf("Максимум: %.2f\n", find_max(first, N));
	printf("Минимум: %.2f\n", find_min(first, N));
	printf("Разность максимального и минимального элементов: %.2f\n", difference);

	double* second = filter_elements(first, N, &count);

	if (count == 0) {
		printf("Нет элементов, меньших найденной разности\n");
	}
	else {
		printf("Новый массив (элементы меньше %.2f):\n", difference);
		print_array(second, count);
		free(second);
	}

	free(first);
	return 0;
}
