#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "Functions.h"

int LR4(void) {
	int len;

	printf("Введите длину строки (целое число больше нуля): ");
	if (scanf("%d", &len) != 1 || len <= 0) {
		printf("Ошибка: длина строки должна быть целым числом больше нуля!\n");
		return 1;
	}

	// Память под исходную строку (+1 для '\0')
	char *str = (char *)malloc((len + 1) * sizeof(char));
	// В худшем случае все символы уникальны, поэтому новая строка не длиннее исходной (+1 для '\0')
	char *unique_str = (char *)malloc((len + 1) * sizeof(char));

	if (str == NULL || unique_str == NULL) {
		printf("Ошибка выделения памяти!\n");
		free(str);
		free(unique_str);
		return 1;
	}

	// Генерация и вывод исходной строки
	generate_string(str, len);
	printf("Исходная строка: %s\n", str);

	// Обработка строки
	int new_len = remove_duplicates(str, len, unique_str);
	printf("Строка без повторных вхождений символов: %s\n", unique_str);
	printf("Длина новой строки: %d\n", new_len);

	// Освобождение памяти
	free(str);
	free(unique_str);
	return 0;
}
