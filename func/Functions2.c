#define _CRT_SECURE_NO_WARNINGS
#include "Functions.h"

#include <stdio.h>
#include <stdlib.h>

// Выделение памяти
double* create_array(int size) {
	return (double*)malloc(size * sizeof(double));
}

// Заполнение массива случайными вещественными числами
// Диапазон: [-50.00; 50.00], два знака после запятой
void fill_array(double* arr, int size) {
	for (int i = 0; i < size; i++) {
		arr[i] = (rand() % 10001 - 5000) / 100.0;
	}
}

// Вывод массива
void print_array(const double* arr, int size) {
	for (int i = 0; i < size; i++) {
		printf("%.2f ", arr[i]);
	}
	printf("\n");
}

// Максимальный элемент массива
double find_max(const double* arr, int size) {
	double max = arr[0];

	for (int i = 1; i < size; i++) {
		if (arr[i] > max) {
			max = arr[i];
		}
	}

	return max;
}

// Минимальный элемент массива
double find_min(const double* arr, int size) {
	double min = arr[0];

	for (int i = 1; i < size; i++) {
		if (arr[i] < min) {
			min = arr[i];
		}
	}

	return min;
}

// Разность максимального и минимального элементов
double find_difference(const double* arr, int size) {
	return find_max(arr, size) - find_min(arr, size);
}

// Подсчёт элементов, значения которых меньше limit
int count_less_than(const double* arr, int size, double limit) {
	int count = 0;

	for (int i = 0; i < size; i++) {
		if (arr[i] < limit) {
			count++;
		}
	}

	return count;
}

// Формирование нового массива из элементов, меньших limit
double* filter_elements(const double* arr, int size, int* count_out) {
        double limit = find_difference(arr, size);
	int count = count_less_than(arr, size, limit);
	double* result;
	int j = 0;

	*count_out = count;

	if (count == 0) {
		return NULL;
	}

	result = (double*)malloc(count * sizeof(double));
	if (result == NULL) {
		*count_out = 0;
		return NULL;
	}

	for (int i = 0; i < size; i++) {
		if (arr[i] < limit) {
			result[j] = arr[i];
			j++;
		}
	}

	return result;
}
