#pragma once

// ЛР 2
double* create_array(int size);                      // создание массива
void fill_array(double* arr, int size);              // заполнение массива случайными вещественными числами
void print_array(const double* arr, int size);       // вывод массива
double find_max(const double* arr, int size);        // максимальный элемент
double find_min(const double* arr, int size);        // минимальный элемент
double find_difference(const double* arr, int size); // разность максимального и минимального элементов
int count_less_than(const double* arr, int size, double limit); // подсчёт элементов, меньших limit
double* filter_elements(const double* arr, int size, int* count_out); // новый массив из элементов, меньших limit

// ЛР 3
int** generateMatrix(int rows, int cols);
void printMatrix(int** matrix, int rows, int cols);
void freeMatrix(int** matrix, int rows);
int findRowOfMax(int** matrix, int rows, int cols);
int* formNewArray(int** matrix, int rows, int cols, int threshold, int* new_size);

// ЛР 4
void generate_string(char str[], int size); // Формирование случайной строки
int remove_duplicates(const char source[], int size, char result[]); // Удаление повторных вхождений символов
								     
// ЛР 5 — Задание 1 (текстовый файл для строк)
int write_string_to_file(const char* filename, const char* str);
int read_string_from_file(const char* filename, char* buffer, int max_size);
int append_string_result_to_file(const char* filename, const char* result, int new_len);

// ЛР 5 — Задание 2 (текстовый файл для массивов)
int write_arrays_to_txt(const char* filename, const double* arr1, int size1, const double* arr2, int size2);
int read_and_print_arrays_from_txt(const char* filename);

// ЛР 5 — Задание 3 (экспорт в CSV)
int write_arrays_to_csv(const char* filename, const double* arr1, int size1, const double* arr2, int size2);
