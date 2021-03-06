#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

int main()
{
	setlocale(LC_ALL, "Russian");   // локализация
	int* matr, st, a, b, t, j = 0;   // объявление переменных
	printf("Введите размер квадратной матрицы: ");   // ввод с клавиатуры размера динамической матрицы
	while (!j) {   // умный ввод
		rewind(stdin);
		j = scanf_s("%i", &st);
	}
	if (!(matr = (int*)malloc(st * st * sizeof(int))))   // выделение памяти для матрицы + проверка на нехватку памяти
		return 0;
	printf("Введите элементы матрицы:\n");   // ввод с клавиатуры элементов матрицы

	for (a = 0; a < st; a++) {   // цикл жля строк
		for (b = 0; b < st; b++) {   // цикл для столбцов
			*(matr + a * st + b) = rand() % 41 -20;
		}
	}
	
	printf("Ваша матрица:\n");   // вывод исходной матрицы
	for (a = 0; a < st; a++) {   // цикл для строк
		for (b = 0; b < st; b++) {   // цикл для столбцов
			printf("%4i", *(matr + a * st + b));
		}
		printf("\n");
	}
	a = 1;   // перевод сразу на 2-ую строку
	while (a < st) {   // объявление цикла для транспонирования матрицы + цикл по строкам
		b = 0;   // перевод индекса столбца в начало
		while (b <= a) {   // цикл по столбцам
			t = *(matr + a * st + b);   // помещение одного элемента в буфер
			*(matr + a * st + b) = *(matr + b * st + a);   // перенос противоположного элемента в предыдущий
			*(matr + b * st + a) = t;  // перенос в новый элемент другой элемент из буфера 
			b++;
		}
		a++;
	}
	printf("Ваша новая матрица:\n");   // вывод новой матрицы
	for (a = 0; a < st; a++) {   //  цикл по строкам
		for (b = 0; b < st; b++) {   // цикл по столбцам
			printf("%4i", *(matr + a * st + b));   // вывод элементов матрицы
		}
		printf("\n");
	}
	return 0;
}
