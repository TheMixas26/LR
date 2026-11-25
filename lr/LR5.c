#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Functions.h"

// Очистка буфера ввода после неудачного scanf
static void clear_input(void) {
	int c;
	while ((c = getchar()) != '\n' && c != EOF) {}
}

// Задание 1: строка -> файл -> чтение -> удаление повторов (ЛР 4) -> дописывание результата
static void task1(void) {
	int len;
	printf("\n[Задание 1] Введите длину случайной строки: ");
	if (scanf("%d", &len) != 1 || len <= 0) {
		clear_input();
		printf("Ошибка: длина должна быть целым числом больше нуля!\n");
		return;
	}

	char* generated = (char*)malloc((len + 1) * sizeof(char));
	char* from_file = (char*)malloc((len + 2) * sizeof(char)); // строка + '\n' + '\0'
	char* result = (char*)malloc((len + 1) * sizeof(char));

	if (!generated || !from_file || !result) {
		printf("Ошибка выделения памяти!\n");
		free(generated);
		free(from_file);
		free(result);
		return;
	}

	// 1. Формируем строку и пишем в файл
	generate_string(generated, len);
	if (write_string_to_file("task1.txt", generated)) {
		printf("Сгенерированная строка записана в task1.txt: %s\n", generated);

		// 2. Читаем строку из файла, обрабатываем и дописываем результат
		if (read_string_from_file("task1.txt", from_file, len + 2)) {
			int actual_len = (int)strlen(from_file);
			int new_len = remove_duplicates(from_file, actual_len, result);

			printf("Строка без повторных вхождений символов: %s\n", result);
			printf("Длина новой строки: %d\n", new_len);

			if (append_string_result_to_file("task1.txt", result, new_len)) {
				printf("Результаты дописаны в конец файла task1.txt.\n");
			}
		}
	}

	free(generated);
	free(from_file);
	free(result);
}

// Задания 2 и 3: массив (ЛР 2) -> TXT и CSV
static void task2_3(void) {
	int N;
	printf("\n[Задания 2 и 3] Введите размер массива (N > 0): ");
	if (scanf("%d", &N) != 1 || N <= 0) {
		clear_input();
		printf("Ошибка: размер массива должен быть целым числом больше нуля!\n");
		return;
	}

	double* first = create_array(N);
	if (first == NULL) {
		printf("Ошибка выделения памяти!\n");
		return;
	}

	fill_array(first, N);
	printf("Исходный массив:\n");
	print_array(first, N);

	// Алгоритм из ЛР 2
	double difference = find_difference(first, N);
	printf("Разность максимального и минимального элементов: %.2f\n", difference);

	int count = 0;
	double* second = filter_elements(first, N, &count);

	if (count == 0 || second == NULL) {
		printf("Результирующий массив пуст (нет элементов, меньших %.2f).\n", difference);
		count = 0;
	}
	else {
		printf("Результирующий массив (элементы меньше %.2f):\n", difference);
		print_array(second, count);
	}

	// Задание 2: запись в TXT и чтение обратно
	if (write_arrays_to_txt("task2.txt", first, N, second, count)) {
		printf("Массивы записаны в task2.txt.\n");
		read_and_print_arrays_from_txt("task2.txt");
	}

	// Задание 3: экспорт в CSV
	if (write_arrays_to_csv("arrays.csv", first, N, second, count)) {
		printf("Массивы экспортированы в arrays.csv для обработки в Python.\n");
	}

	free(second);
	free(first);
}

int LR5(void) {
	int sub_choice;

	do {
		printf("\n--- ЛАБОРАТОРНАЯ РАБОТА № 5 ---\n");
		printf("1. Задание 1: Обработка строки с использованием текстового файла\n");
		printf("2. Задание 2 и 3: Обработка массивов (запись в TXT и CSV)\n");
		printf("0. Вернуться в главное меню\n");
		printf("Выберите пункт: ");

		if (scanf("%d", &sub_choice) != 1) {
			clear_input();
			sub_choice = -1;
		}

		switch (sub_choice) {
		case 1: task1(); break;
		case 2: task2_3(); break;
		case 0: break;
		default: printf("Такого пункта нет.\n");
		}
	} while (sub_choice != 0);

	return 0;
}
