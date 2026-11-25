#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Functions.h"

int LR3(void) {
	system("cls");
	system("chcp 1251 > nul");
	srand(time(NULL));

	int rows, cols;
	printf("Введите размер матрицы, количество строк и колонок через пробел (целые числа больше нуля): ");
	if (scanf("%d %d", &rows, &cols) != 2 || rows <= 0 || cols <= 0) {
		printf("Ошибка: размеры матрицы должны быть целыми числами больше нуля!\n");
		return 1;
	}

	int** matrix = generateMatrix(rows, cols);
	if (matrix == NULL) {
		printf("Ошибка выделения памяти для матрицы!\n");
		return 1;
	}

	printf("\nИсходная матрица:\n");
	printMatrix(matrix, rows, cols);

	int max_row = findRowOfMax(matrix, rows, cols);
	printf("\nНомер строки, содержащей максимальный элемент: %d\n", max_row);

	int new_size = 0;
	int* result_array = formNewArray(matrix, rows, cols, max_row, &new_size);

	if (result_array == NULL || new_size == 0) {
		printf("Нет элементов, которые строго больше %d\n", max_row);
	}
	else {
		printf("Новый одномерный массив (элементы больше %d, всего %d шт.):\n", max_row, new_size);
		for (int i = 0; i < new_size; i++) {
			printf("%d ", result_array[i]);
		}
		printf("\n");

		free(result_array);
	}

	freeMatrix(matrix, rows);
	return 0;
}
