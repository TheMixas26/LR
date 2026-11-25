#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "Functions.h"

int v1(void);
int v2(void);



char* pronouncing(int n) {
    int last_two = n % 100;
    int last_one = n % 10;

    if (last_two >= 11 && last_two <= 14) {
        return "символов";
    }
    if (last_one == 1) {
        return "символ";
    }
    if (last_one >= 2 && last_one <= 4) {
        return "символа";
    }
    return "символов";
}


int add1(void) {
    srand((unsigned int)time(NULL)); // Инициализируем генератор один раз при старте
    system("chcp 1251 > nul");
    system("clear > nul");
    system("cls > nul");

    int choice;
    do {
        printf("\nВыберите вариант работы программы:\n1. Ручной ввод\n2. Генерация строки\n0. Выход\n> ");
        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n');
            choice = -1;
        }
        while (getchar() != '\n');

        switch (choice) {
        case 1:
            v1();
            break;
        case 2:
            v2();
            break;
        case 0:
            printf("Завершение работы.\n");
            break;
        default:
            printf("Нет такой команды.\n");
        }
    } while (choice != 0);

    return 0;
}

int v1(void) {
    int c;
    int i = 0, k = 0;
    int word = 0, word_size = 0;

    char str[1024] = "";
    printf("Введите строку: ");
    while ((c = getchar()) != '\n' && c != EOF && i < 1023) {
        str[i] = (char)c;
        i++;
    }
    str[i] = '\0';

    if (str[0] == '\0') {
        printf("no words\n");
        return 1;
    }

    printf("Строка принята в обработку...\n\n");

    for (int j = 0; j < i; j++) {
        if (str[j] != ' ') {
            word++;
            if (word_size < word) {
                word_size = word;
            }
        }
        else {
            if (word > 0) k++;
            word = 0;
        }
    }
    if (word > 0) k++;

    printf("Кол-во слов - %d, самое длинное слово: %d %s", k, word_size, pronouncing(word_size));
    return 0;
}

int v2(void) {
    int size = 0;
    int k = 0;
    int word = 0;
    int word_size = 0;

    printf("Введите размер строки: ");
    if (scanf("%d", &size) != 1 || size <= 0) {
        printf("Ошибка! Введите положительное целое число.\n");
        while (getchar() != '\n');
        return 1;
    }
    while (getchar() != '\n');

    char* str = (char*)malloc((size + 1) * sizeof(char));
    if (str == NULL) {
        printf("Ошибка выделения памяти!\n");
        return 1;
    }

    generate_string(str, size);
    printf("Исходная строка: %s\n\n", str);

    char spec[] = "!@#$%";

    for (int j = 0; j < size; j++) {
        if (strchr(spec, str[j]) == NULL) {
            word++;
            if (word_size < word) {
                word_size = word;
            }
        }
        else {
            if (word > 0) {
                k++;
                word = 0;
            }
        }
    }

    if (word > 0) {
        k++;
    }

    printf("Кол-во слов - %d, самое длинное слово: %d %s\n", k, word_size, pronouncing(word_size));
    free(str);
    return 0;
}
