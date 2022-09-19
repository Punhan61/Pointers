#include<iostream>
using namespace std;

void FillRand(int arr[], const int n);
void Print(int* arr, const int n);

int* push_back(int* arr,  int& n, int value);
int* push_front(int* arr, int& n, int value);
int* insert(int* arr, int& n, int value, int index);

int* pop_back(int* arr, int& n);
int* pop_front(int* arr, int& n);
int* pop_erase(int* arr, int& n,int index);


void main()
{
	setlocale(LC_ALL, "");
	int n;
	cout << "Введите размер массива: "; cin >> n;
	int* arr = new int[n];

	FillRand(arr, n);
	Print(arr, n);
	
	int value, index;
	cout << "Введите добовляемое значения в конец массива: "; cin >> value;
	arr = push_back(arr, n, value);
	Print(arr, n);
		
	cout << "Введите добовляемое значения в начало массива: "; cin >> value;
	arr = push_front(arr, n, value);
	Print(arr, n);
	
	cout << "Введите индекс значения: "; cin >> index;
	cout << "Введите добовляемое значения: "; cin >> value;
	arr = insert(arr, n,value,index);
	Print(arr, n);

	cout << "Удаления значения из конца массива: " << endl;
	arr = pop_back(arr, n);
	Print(arr, n);

	cout << "Удаления значения с начала массива: " << endl;
	arr = pop_front(arr, n);
	Print(arr, n);

	cout << "Введите индекс удаляемого значения: "; cin >> index;
	arr = pop_erase(arr, n,index);
	Print(arr, n);
	delete arr;
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

int* push_front(int* arr, int& n, int value)
{
	int* buffer = new int[n+1];
	
	for (int i = 1; i <= n; i++)
	{
		buffer[i] = arr[i-1];
	}
	delete[]arr;
	arr = buffer;
	arr[0] = value;
	n++;
	return arr;
}

int* insert(int* arr, int& n, int value, int index)
{
	int* buf = new int[n + 1];
	int counter = 0;
	for (int i = 0; i <= n; i++)
	{
		/*if (i == index) buf[i] = value;
		else buf[i] = arr[counter++];*/
		i == index ? buf[i] = value : buf[i] = arr[counter++];
	}
	delete[]arr;
	arr = buf;
	n++;
	return arr;
}
int* pop_back(int* arr, int& n)
{
	int* buffer = new int[n - 1];
	for (int i = 0; i < n - 1; i++)
	{
		buffer[i] = arr[i];
	}
	delete[]arr;
	arr = buffer;
	n--;
	return arr;
}
int* pop_front(int* arr, int& n)
{
	int* buffer = new int[n - 1];
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i + 1];
	}
	delete[]arr;
	arr = buffer;
	n--;
	return arr;
}
int* pop_erase(int* arr, int& n, int index)
{
	int* buffer = new int[n - 1];
	int counter = 0; 
	for (int i = 0; i < n ; i++,counter++)
	{
		if (i == index)buffer[i] = arr[++counter];
		else buffer[i] = arr[counter];
	}
	delete[]arr;
	arr = buffer;
	n--;
	return arr;
}