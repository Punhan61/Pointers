﻿#include<iostream>
using namespace std;

void FillRand(int arr[], const int n);
void Print(int* arr, const int n);

int* push_back(int* arr,  int& n, int value);

void main()
{
	setlocale(LC_ALL, "");
	int n;
	cout << "Введите размер массива: "; cin >> n;
	int* arr = new int[n];

	FillRand(arr, n);
	Print(arr, n);
	
	int value;
	cout << "Введите добовляемое значения: "; cin >> value;

	arr = push_back(arr, n, value);

	Print(arr, n);

	delete[] arr;
}

void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		//Через арифметику указателей и разыменования
		*(arr + i) = rand() % 100;
	}
}
void Print(int* arr, const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}

int* push_back(int* arr,  int& n, int value)
{
	//1)Создаем буферный массив нужного размера
	int* buffer = new int[n + 1];

	//2) Копируем содержимое исходного массива в буферный
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}

	//3) После того как все данные скопированы из исходного массива в буферный,
	// исходный массив больше не нужен, и его можно удалить
	delete[] arr;

	//4) Подменяем адрес исходного массива в указателе arr адресом нового массива
	arr = buffer;

	//5) И только после всего этого можно написать вот так
	// поскольку только сейчас в массиве arr появился еще один элемент ,в который можно сохранить значения
	arr[n] = value;

	//6) После того как мы добавили в массив элемент,кол-во элементов массива увеличивается
	n++;
	//7) Mission complete - Элемент добавлен
	return arr;
}