#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#include "Functions.h"


int LR1(void) {
	double x, y, z, a, b, c, result;

	system("chcp 1251 > nul");
	srand((unsigned int)time(NULL));

	// Три числа берём из динамического массива вместо ручного ввода
	double* numbers = create_array(3);
	if (numbers == NULL) {
		printf("Ошибка: не удалось выделить память!\n");
		return 1;
	}

	fill_array(numbers, 3);

	printf("Сгенерированные числа (x, y, z): ");
	print_array(numbers, 3);

	x = numbers[0];
	y = numbers[1];
	z = numbers[2];

	free(numbers);

	if (z < y) {
		printf("Тест ветви 1\n");

		a = x * x;
		b = cos(z);
		c = exp(y);

		if (a > b) { result = a; } else { result = b; }
		if (c > result) { result = c; }
	}

	else if (y <= z && z <= x) {
		printf("Тест ветви 2\n");

		a = sin(x);
		b = log(y * y + 1);
		c = x + z;

		if (a < b) { result = a; } else { result = b; }
		if (c < result) { result = c; }
	}

	else {
		printf("Тест ветви 3\n");
		double min, max;

		a = x + y;
		b = y + z;
		c = z + x;

		if (a < b) { min = a; } else { min = b; }
		if (c < min) { min = c; }

		if (fabs(x) > fabs(y)) { max = fabs(x); } else { max = fabs(y); }
		if (fabs(z) > max) { max = fabs(z); }

		result = min + max;
	}

	printf("Ваше число: %.3f\n", result);
	return 0;
}
