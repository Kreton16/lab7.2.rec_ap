#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
void Create(int** a, const int n, const int l, const int Low, const int High, int i, int j);
void Print(int** a, const int n, const int l, int i, int j);
void Print_in(int** a, const int n, const int l, int i, int j);
void CalcMax_in(int** a, const int n, const int l, int& max, int& sum, int i, int j);
void CalcMax(int** a, const int n, const int l, int& max, int& sum, int i, int j);
int main()
{
	srand((unsigned)time(NULL));
	int Low = -23;
	int High = 26;
	int n, l;
	int i = 0, j = 0;
	cout << "k = "; cin >> l;
	cout << "n = "; cin >> n;
	int** a = new int* [n];
	for (int i = 0; i < n; i++)
		a[i] = new int[n];
	Create(a, n, l, Low, High, i, j);
	cout << endl;
	Print(a, n, l, i, j);
	cout << endl;
	int max;
	int sum = 0;
	CalcMax(a, n, l, max, sum, i, j);
	cout << "Sum of max = " << sum;
	for (int i = 0; i < n; i++)
		delete[] a[i];
	delete[] a;
	return 0;
}

void Create(int** a, const int n, const int l, const int Low, const int High, int i, int j)
{
	if (i < l) {
		if( j < n) {
			a[i][j] = Low + rand() % (High - Low + 1);
			Create(a, n, l, Low, High, i, j + 1);
		}
		Create(a, n, l, Low, High, i + 1, j);
	}
}

void Print(int** a, const int n, const int l, int i, int j)
{
	if (i < l)
	{
		Print_in(a, n, l, i, j);
		cout << endl;
		Print(a, n, l, i + 1, j);
	}
}

void Print_in(int** a, const int n, const int l, int i, int j)
{
	if (j < n) {
		cout << setw(4) << a[i][j];
		Print_in(a, n, l, i, j + 1);
	}
}

void CalcMax_in(int** a, const int n, const int l, int& max, int& sum, int i, int j)
{
		if (j < l) {
			if (a[j][i] > max)
				max = a[j][i];
			CalcMax_in(a, n, l, max, sum, i, j + 1);
		}
}

void CalcMax(int** a, const int n, const int l, int& max, int& sum, int i, int j)
{
	if(i < n) {
		max = a[0][i];
		CalcMax_in(a, n, l, max, sum, i, j);
		sum += max;
		CalcMax(a, n, l, max, sum, i + 2, j);
	}
}