#include <iostream>
#include <iomanip>
#include <windows.h>
#include <conio.h>

using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int i = 0, j = 0, max; //i - число строк матрицы, j - число столбцов

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
	for (int temp_row = 0; temp_row < i; temp_row++) // выводим матрицу в консоль
	{
		for (int temp_column = 0; temp_column < j; temp_column++)
		{
			cout << matrix[temp_row][temp_column] << " ";
			if (temp_column == j - 1)
				cout << endl;
		}
	}
	
	/*int s; // s - предполагаемая нулевая сумма элементов какого-то столбца
	for (int temp_row = 0; temp_row < i; temp_row++)
	{
		for (int temp_column = 0; temp_column < j; temp_column++)
		{
			cout << "matrix[" << temp_row << "][" << temp_column << "] = ";
			cin >> matrix[temp_row][temp_column];
	*/
	return 0;
}