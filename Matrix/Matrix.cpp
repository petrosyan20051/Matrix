#include <iostream>
#include <iomanip>
#include <windows.h>
#include <conio.h>

using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int i = 0, j = 0; //i - число строк матрицы, j - число столбцов

	cout << "Введите количества строк i и столбцов j (i > 0, j > 0): ";
	while (i <= 0 || j <= 0)
	{
		cin >> i >> j;
		if (i <= 0 || j <= 0)
			cout << "Введены неверные значения, попробуйте ещё раз!" << endl;
	}
	int** matrix{ new int* [i] }; // создаём динамический массив с строками
	for (int temp = 0; temp < j; temp++) // создаём динамический массив со столбцами
		matrix[temp] = new int[j];

	cout << "Введите элементы матрицы построчно" << endl; // заполняем матрицу
	for (int temp_row = 0; temp_row < i; temp_row++)
	{
		for (int temp_column = 0; temp_column < j; temp_column++)
		{
			cout << "matrix[" << temp_row << "][" << temp_column << "] = ";
			cin >> matrix[temp_row][temp_column];
		}
	}
	/*
	for (int temp_row = 0; temp_row < i; temp_row++) // выводим матрицу в консоль
	{
		for (int temp_column = 0; temp_column < j; temp_column++)
		{
			cout << setw(6) << matrix[temp_row][temp_column] << " ";
			if (temp_column == j - 1)
				cout << endl;
		}
	}
	cout << endl;
	*/

	int s = 1, n; // s - предполагаемая нулевая сумма элементов какого-то столбца, n - номер "0" столбца
	for (int temp_column = 0; temp_column < j; temp_column++)
	{
		for (int temp_row = 0; temp_row < i; temp_row++)
		{
			s += matrix[temp_row][temp_column];
		}
		if (s - 1 == 0)
		{
			//cout << temp_column << " столбец";
			n = temp_column; // запоминаем номер "0" столбца
			break;
		}

	}

	int max = matrix[0][0]; // максимальное значение в чётных строках (начальное значение берём первое)
	for (int temp_row = 1; temp_row < i; temp_row += 2) // ищем максимальное значение в чётных строках
	{
		for (int temp_column = 0; temp_column < j; temp_column++)
		{
			if (matrix[temp_row][temp_column] > max)
				max = matrix[temp_row][temp_column];
		}
	}

	for (int temp_row = 0; temp_row < i; temp_row++) // заменяем "0" столбец
		matrix[temp_row][n] = max;

	for (int temp_row = 0; temp_row < i; temp_row++) // выводим конечную матрицу в консоль
	{
		for (int temp_column = 0; temp_column < j; temp_column++)
		{
			cout << setw(6) << matrix[temp_row][temp_column] << " ";
			if (temp_column == j - 1)
				cout << endl;
		}
	}
	_getch();
	return 0;
}