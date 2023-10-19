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

	cout << "Ведите количества строк i и столбцов j (i > 0, j > 0): ";
	while (i <= 0 || j << 0)
	{
		cin >> i >> j;
		if (i <= 0 || j <= 0)
			cout << "Введены неверные значения, попробуйте ещё раз!";
	}
	
	int matrix[i][j]; // вводим матриц
}