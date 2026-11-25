#include <stdlib.h>
#include <stdio.h>

int** generateMatrix(int rows, int cols) {
	int** arr = (int**)malloc(rows * sizeof(int*));
	if (arr == NULL) return NULL;

	for (int i = 0; i < rows; i++) {
		arr[i] = (int*)malloc(cols * sizeof(int));
		if (arr[i] == NULL) {
			// освобождаем уже выделенные строки
			for (int k = 0; k < i; k++) {
				free(arr[k]);
			}
			free(arr);
			return NULL;
		}

		for (int j = 0; j < cols; j++) {
			arr[i][j] = rand() % 101 - 50;
		}
	}
	return arr;
}

void printMatrix(int** matrix, int rows, int cols) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			printf("%4d ", matrix[i][j]);
		}
		printf("\n");
	}
}

void freeMatrix(int** matrix, int rows) {
	if (matrix == NULL) return;
	for (int i = 0; i < rows; i++) {
		free(matrix[i]);
	}
	free(matrix);
}

// Возвращает номер (с 1) строки, содержащей максимальный элемент матрицы.
// Если максимум встречается несколько раз, возвращается первая такая строка.
int findRowOfMax(int** matrix, int rows, int cols) {
	int max_val = matrix[0][0];
	int max_row = 0;

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (matrix[i][j] > max_val) {
				max_val = matrix[i][j];
				max_row = i;
			}
		}
	}
	return max_row + 1;
}

// Формирует новый массив из элементов матрицы, строго больших threshold.
// В *new_size записывается размер нового массива.
int* formNewArray(int** matrix, int rows, int cols, int threshold, int* new_size) {
	int count = 0;

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (matrix[i][j] > threshold) {
				count++;
			}
		}
	}

	*new_size = count;

	if (count == 0) {
		return NULL;
	}

	int* new_arr = (int*)malloc(count * sizeof(int));
	if (new_arr == NULL) return NULL;

	int index = 0;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (matrix[i][j] > threshold) {
				new_arr[index] = matrix[i][j];
				index++;
			}
		}
	}

	return new_arr;
}
