#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Functions.h"

// ---------- Задание 1: строки и текстовый файл ----------

// Запись исходной строки в текстовый файл
int write_string_to_file(const char* filename, const char* str) {
	FILE* fp = fopen(filename, "w");
	if (fp == NULL) {
		printf("Ошибка: не удалось открыть файл %s для записи!\n", filename);
		return 0;
	}
	fprintf(fp, "%s\n", str);
	fclose(fp);
	return 1;
}

// Чтение строки из текстового файла
int read_string_from_file(const char* filename, char* buffer, int max_size) {
	FILE* fp = fopen(filename, "r");
	if (fp == NULL) {
		printf("Ошибка: не удалось открыть файл %s для чтения!\n", filename);
		return 0;
	}
	if (fgets(buffer, max_size, fp) == NULL) {
		printf("Ошибка: файл %s пуст или не удалось прочитать строку!\n", filename);
		fclose(fp);
		return 0;
	}
	// Удаляем символ переноса строки, если он считался
	buffer[strcspn(buffer, "\r\n")] = '\0';
	fclose(fp);
	return 1;
}

// Дописывание результата обработки (строка без повторов) в конец того же файла
int append_string_result_to_file(const char* filename, const char* result, int new_len) {
	FILE* fp = fopen(filename, "a");
	if (fp == NULL) {
		printf("Ошибка: не удалось открыть файл %s для добавления данных!\n", filename);
		return 0;
	}
	fprintf(fp, "Строка без повторных вхождений символов: %s\n", result);
	fprintf(fp, "Длина новой строки: %d\n", new_len);
	fclose(fp);
	return 1;
}

// ---------- Задание 2: массивы (double, из ЛР 2) и текстовый файл ----------

// Запись исходного и результирующего массивов в текстовый файл
int write_arrays_to_txt(const char* filename, const double* arr1, int size1, const double* arr2, int size2) {
	FILE* fp = fopen(filename, "w");
	if (fp == NULL) {
		printf("Ошибка: не удалось открыть файл %s для записи!\n", filename);
		return 0;
	}

	fprintf(fp, "Исходный массив (%d элементов):\n", size1);
	for (int i = 0; i < size1; i++) {
		fprintf(fp, "%.2f ", arr1[i]);
	}
	fprintf(fp, "\n");

	fprintf(fp, "Результирующий массив (%d элементов):\n", size2);
	if (size2 == 0 || arr2 == NULL) {
		fprintf(fp, "Нет подходящих элементов");
	}
	else {
		for (int i = 0; i < size2; i++) {
			fprintf(fp, "%.2f ", arr2[i]);
		}
	}
	fprintf(fp, "\n");

	fclose(fp);
	return 1;
}

// Чтение файла и вывод на экран
int read_and_print_arrays_from_txt(const char* filename) {
	FILE* fp = fopen(filename, "r");
	if (fp == NULL) {
		printf("Ошибка: не удалось открыть файл %s для чтения!\n", filename);
		return 0;
	}

	printf("\n--- Содержимое файла %s ---\n", filename);
	char line[4096];
	while (fgets(line, sizeof(line), fp) != NULL) {
		printf("%s", line);
	}
	printf("\n--------------------------------------\n");

	fclose(fp);
	return 1;
}

// ---------- Задание 3: экспорт в CSV ----------

// Запись исходного и результирующего массивов в CSV-файл по столбцам
int write_arrays_to_csv(const char* filename, const double* arr1, int size1, const double* arr2, int size2) {
	FILE* fp = fopen(filename, "w");
	if (fp == NULL) {
		printf("Ошибка: не удалось открыть CSV-файл %s для записи!\n", filename);
		return 0;
	}

	fprintf(fp, "Source_Array,Result_Array\n");

	int max_rows = (size1 > size2) ? size1 : size2;

	for (int i = 0; i < max_rows; i++) {
		if (i < size1) {
			fprintf(fp, "%.2f", arr1[i]);
		}
		fprintf(fp, ",");

		if (i < size2 && arr2 != NULL) {
			fprintf(fp, "%.2f", arr2[i]);
		}
		fprintf(fp, "\n");
	}

	fclose(fp);
	return 1;
}
