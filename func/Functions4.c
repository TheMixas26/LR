#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include "Functions.h"

// Формирование случайной строки длины size.
void generate_string(char str[], int size) {
	const char charset[] =
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		"abcdefghijklmnopqrstuvwxyz"
		"0123456789"
		"!@#$%";
	int charset_len = (int)sizeof(charset) - 1;

	for (int i = 0; i < size; i++) {
		str[i] = charset[rand() % charset_len];
	}
	str[size] = '\0';
}

// Формирование строки, в которой оставлено только первое вхождение каждого символа.
// Возвращает длину результирующей строки.
int remove_duplicates(const char source[], int size, char result[]) {
	int seen[256] = { 0 }; // seen[c] == 1, если символ c уже встречался
	int res_idx = 0;

	for (int i = 0; i < size; i++) {
		unsigned char c = (unsigned char)source[i];
		if (!seen[c]) {
			seen[c] = 1;
			result[res_idx] = source[i];
			res_idx++;
		}
	}
	result[res_idx] = '\0';

	return res_idx;
}
