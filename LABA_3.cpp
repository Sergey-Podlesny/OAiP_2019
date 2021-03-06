#include <stdio.h>
#include <locale.h>

void  input(int mas[]) {
	printf("Введите массив чисел из 10 чисел: \n");   // вывод на экран НАДПИСЬ
	for (int i = 0; i < 10; i++) {   // объявление цикла для ввода массива
		printf("MS[%i] = ", i);   // приглашение
		int j = scanf_s("%i", &mas[i]);   // ввод числа с клавиатуры
		rewind(stdin);   // очистка буфера
		if (j != 1) i--;   // "умный ввод"
	}
}

void output(int mas[], int k) {
	if (k == 1) printf("Исходный массив:        ");   // вывод на экран НАДПИСЬ
	if (k == 2) printf("Отсортированный массив: "); // вывод на экран НАДПИСЬ
	for (int i = 0; i < 10; i++) {   //объявление цикла для вывода массива
		printf("%4i ", mas[i]);   // вывод
	}
	printf("\n");   // пропуск одной строки
}

int main() {
	setlocale(LC_ALL, "Russian");
	int mas_com[10];   // объявление массива
	input(mas_com);   // вызов функции для ввода массива	
	output(mas_com, 1);   // вызов функции для вывода массива
	int mas_pol[10], mas_otr[10], i = -1, na = 0, nb = 0, t, a = 0, b = 0;   // объявление переменных

	while (i++ < 10) {   // объявление цикла для создания полож. и отриц. массивов соотв.

		if (mas_com[i] > 0) {   // если элем. исходного массива > 0
			mas_pol[a++] = mas_com[i];   // то он записывается в массив "mas_pol"
			na++;   // счетчик кол-ва чисел в массиве "mas_pol"
		}

		if (mas_com[i] < 0) {   // если элем. исходного массива < 0
			mas_otr[b++] = mas_com[i];   // то он записывается в массив "mas_otr"
			nb++;   // счетчик кол-ва чисел в массиве "mas_otr"
		}
	}

	for (a = 0; a < (na - 1); a++) {   // объявление цикла для пузырьковой сортировки массива "mas_pol" по возрастанию
		for (int ac = 0; ac < (na - 1 - a); ac++) {
			if (mas_pol[ac] > mas_pol[ac + 1]) {
				t = mas_pol[ac];
				mas_pol[ac] = mas_pol[ac + 1];
				mas_pol[ac + 1] = t;
			}
		}
	}

	for (b = 0; b < (nb - 1); b++) {   // объявление цикла для пузырьковой сортировки массива "mas_otr" по убыванию
		for (int bc = 0; bc < (nb - 1 - b); bc++) {
			if (mas_otr[bc] < mas_otr[bc + 1]) {
				t = mas_otr[bc];
				mas_otr[bc] = mas_otr[bc + 1];
				mas_otr[bc + 1] = t;
			}
		}
	}

	for (int i = 0, a = 0, b = 0; i < 10; i++) {   // объявление цикла для вставления отсорированных массивов

		if (mas_com[i] > 0) {   // елис i-тый элемент исходного массива был положительный
			mas_com[i] = mas_pol[a];   // то туда отправляется а-тый элемент массива "mas_pol"
			a++;   // счетчик для индекса в массиве "mas_pol"
		}

		if (mas_com[i] < 0) {   // елис i-тый элемент исходного массива был отрицательный
			mas_com[i] = mas_otr[b];   // то туда отправляется b-тый элемент массива "mas_otr"
			b++;   // счетчик для индекса в массиве "mas_otr"
		}
	}

	output(mas_com, 2);  // вызов функции для вывода нового массива
	
	return 0;
}
