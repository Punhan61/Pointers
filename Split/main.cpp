#include<iostream>
using namespace std;

void FillRand(int arr[], const int n);
void Print(int arr[], const int n);

void main()
{
	setlocale(LC_ALL, "");
	const int n = 10;
	int arr[n];
	FillRand(arr, n);
	Print(arr, n);

	int even, odd;
	even = odd = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] % 2 == 0)even++;
		else odd++;
	}
	cout << "Количество четных элементов: " << even << endl;
	cout << "Количество нечетных элементов: " << odd << endl;

	int* even_arr = new int[even];
	int* odd_arr = new int[odd];
	for (int i = 0, j = 0, k = 0; i < n; i++)
	{
		/*if (arr[i] % 2 == 0)even_arr[j++] = arr[i];
		else odd_arr[k++] = arr[i];*/
		(arr[i] % 2 == 0 ? even_arr[j++] : odd_arr[k++]) = arr[i];
	}
	Print(even_arr, even);
	Print(odd_arr, odd);
	delete[]even_arr;
	delete[]odd_arr;
}
void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
	}
}

void Print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}