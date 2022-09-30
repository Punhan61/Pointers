#include<iostream>
using namespace std;
using std:: cin;
using std:: cout;
using std:: endl;
#define tab "\t";

int** Allocate(const int rows, const int cols);
void Clear(int** arr, const int rows);

void FillRand(int arr[], const int n);
void FillRand(int** arr, const int rows,const int cols);

void Print(int* arr, const int n);
void Print(int** arr, const int rows,const int cols);

int* push_back(int* arr,  int& n, int value);
int** push_row_back(int** arr, int& rows, const int cols);
void push_col_back(int** arr, int rows,int& cols);

int* push_front(int* arr, int& n, int value);
int** push_row_front(int** arr, int& rows, const int cols);
void push_col_front(int** arr, int rows, int& cols);

int* insert(int* arr, int& n, int value, int index);
int** insert_row(int** arr, int& rows, int cols, int index);
//int** insert_col(int** arr, int rows, int& cols, int index);

int* pop_back(int* arr, int& n);
int** pop_row_back(int** arr, int& rows, int cols);
void pop_col_back(int** arr, int rows, int& cols);
 

int* pop_front(int* arr, int& n);
int** pop_row_front(int** arr, int& rows, int cols);
void pop_col_front(int** arr,const int rows, int& cols);

int* pop_erase(int* arr, int& n,int index);
int** erase_row(int** arr, int& rows, int cols, int index);

//#define DYNAMIC_MEMORY_1
//#define DYNAMIC_MEMORY_2_ROWS

void main()
{
	setlocale(LC_ALL, "");
#ifdef DYNAMIC_MEMORY_1
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
	arr = insert(arr, n, value, index);
	Print(arr, n);

	cout << "Удаления значения из конца массива: " << endl;
	arr = pop_back(arr, n);
	Print(arr, n);

	cout << "Удаления значения с начала массива: " << endl;
	arr = pop_front(arr, n);
	Print(arr, n);

	cout << "Введите индекс удаляемого значения: "; cin >> index;
	arr = pop_erase(arr, n, index);
	Print(arr, n);
	delete arr;
#endif // DYNAMIC_MEMORY_1
	
	int rows, cols, index;
	cout << "Введите количество строк: "; cin >> rows;
	cout << "Введите количество элементов строк: "; cin >> cols;
	
	int**arr = Allocate(rows, cols);
	FillRand(arr, rows, cols);
	Print(arr, rows, cols);
#ifdef DYNAMIC_MEMORY_2_ROWS
	cout << "Добавляем строку в конец массива: " << endl;
	arr = push_row_back(arr, rows, cols);
	Print(arr, rows, cols);
	
	cout << "Добавляем строку в начало массива: " << endl;
	arr = push_row_front(arr, rows, cols);
	Print(arr, rows, cols);

	cout << "Добовляем строку в массив по индексу: "; cin >> index;
	arr = insert_row(arr, rows, cols, index);
	Print(arr, rows, cols);

	cout << "Удаляем последнюю строку из массива: " << endl;
	arr = pop_row_back(arr, rows, cols);
	Print(arr, rows, cols);

	cout << "Удаляем нулевую строку массива: " << endl;
	arr = pop_row_front(arr, rows, cols);
	Print(arr, rows, cols);

	cout << "Удаляем строку в массив по индексу: "; cin >> index;
	arr = erase_row(arr, rows, cols, index);
	Print(arr, rows, cols);
#endif // DYNAMIC_MEMORY_2_ROWS

	cout << "Добавляем столбец в конец массива: " << endl;
	push_col_back(arr, rows, cols);
	Print(arr, rows, cols);

	cout << "Добавляем столбец в начало массива: " << endl;
	push_col_front(arr, rows, cols);
	Print(arr, rows, cols);

	/*cout << "Добавляем столбец по идексу в массив: "; cin >> index;
	arr=insert_col(arr, rows, cols,index);
	Print(arr, rows, cols);*/

	cout << "Удаляем столбец в конце массива: " << endl;
	pop_col_back(arr, rows, cols);
	Print(arr, rows, cols);

	cout << "Удаляем нулевой столбец из массива: " << endl;
	pop_col_front(arr, rows, cols);
	Print(arr, rows, cols);

	Clear(arr, rows);
}
int** Allocate(const int rows, const int cols)
{
	//1) Создаем массив указателей:
	int** arr = new int* [rows];
	//2) Выделяем память под строки двумерного массива:
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols]{};
	}
	return arr;
}
void Clear(int** arr, const int rows)
{
	//1) Сначала удаляются строки двумерного массива:
	for (int i = 0; i < rows; i++)
	{
		delete[]arr[i];
	}
	//2) Удаляем массив указателей:
	delete[]arr;
}

void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		//Через арифметику указателей и разыменования
		*(arr + i) = rand() % 100;
	}
}
void FillRand(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % 100;
		}
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
void Print(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << arr[i][j] << tab;
		}
		cout << endl;
	}
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
int** push_row_back(int** arr,int& rows, const int cols)
{
	//1)Создаем новый буферный массив указателей нужного размер: 
	int** buffer = new int* [rows + 1];
	//2)Копируем адреса строк из исходного массива указателей в буферный:
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = arr[i];
	}
	//3)Удаляем исходный массив указателей:
	delete[]arr;
	//4)создаем новую строку:
	buffer[rows] = new int[cols] {};
	//5)После добавления строки в массив количество строк увеличивается
	rows++;
	//6)Возвращаем адрес нового массива
	return buffer;
}
void push_col_back(int** arr, int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		//1) Создаем новую строку нужного размера
		int* buffer = new int[cols + 1]{};
		//2) Копируем все элементы 1-й строки в новую строку(буфер)
		for (int j = 0; j < cols; j++)buffer[j] = arr[i][j];
		//3) удаляем исходную строку
		delete[]arr[i];
		//4) подменяем исходную строку новой
		arr[i] = buffer;
	}
	//5) после того как в каждую строку добавлен элемент
	// в массиве появляется еще один столбец
	cols++;
}

int* push_front(int* arr, int& n, int value)
{
	int* buffer = new int[n + 1];
	
	for (int i = 1; i <= n; i++)
	{
		buffer[i] = arr[i - 1];
	}
	delete[]arr;
	arr = buffer;
	arr[0] = value;
	n++;
	return arr;
}
int** push_row_front(int** arr, int& rows, const int cols)
{
	int** buffer = new int* [rows + 1];
	
	for (int i = 0; i < rows+1; i++)
	{
		buffer[i+1] = arr[i];
	}
	delete[]arr;

	buffer[0] = new int[cols] {};
	rows++;
	return buffer;
}
void push_col_front(int** arr, int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols + 1]{};
		for (int j = 0; j < cols+1; j++)buffer[j+1] = arr[i][j];
	delete[] arr[i];
	
	arr[i] = buffer;
	}
	cols++;
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
int** insert_row(int** arr, int& rows, int cols, int index)
{
	int** buffer = new int* [rows + 1];
	int counter = 0;
	for (int i = 0; i < rows+1; i++)
	{
		/*if (i == index)buffer[i] = new int[cols] {};
		else buffer[i] = arr[counter++];*/
		i == index ? buffer[i] = new int[cols] {} : buffer[i] = arr[counter++];
	}
	delete[] arr;
	arr = buffer;
	rows++;
	return arr;
}
//int** insert_col(int** arr, int rows, int& cols, int index)
//{
//	for (int i = 0; i < rows; i++)
//	{
//		int* buffer = new int[cols + 1]{};
//		for (int j = 0; j < cols+1; j++)
//		{
//			if (j == index)buffer[j];
//			else buffer[j] = arr[i][j+1];
//		}
//		delete[]arr[i];
//		arr[i] = buffer;
//	    return arr;
//	}
//	cols++;
//}


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
int** pop_row_back(int** arr, int& rows, int cols)
{
	/*int** buffer = new int*[rows - 1];
	for (int i = 0; i < rows - 1; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	buffer[rows] = new int[cols] {};
	rows--;
	return buffer;*/

	//1)Удаляем строку из памяти
	delete[] arr[rows - 1];
	//2)Переопределяем массив указателей
	int** buffer = new int* [--rows]{};
	for (int i = 0; i < rows; i++)buffer[i] = arr[i];
	delete[] arr;
	return buffer;
}
void pop_col_back(int** arr, int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols - 1]{};
		for (int j = 0; j < cols - 1; j++)
			buffer[j] = arr[i][j];
		delete[]arr[i];
		arr[i] = buffer;
	}
	cols--;
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
int** pop_row_front(int** arr, int& rows, int cols)
{
	int** buffer = new int* [rows - 1];
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = arr[i + 1];
	}
	delete[] arr;
	buffer[rows] = new int[cols] {};
	rows--;
	return buffer;
}
void pop_col_front(int** arr,const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols-1]{};
		for (int j = 0; j < cols; j++)
			buffer[j-1] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols--;
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
int** erase_row(int** arr, int& rows, int cols, int index)
{
	int** buffer = new int* [rows - 1];
	
	for (int i = 0; i < rows-1; i++)
	{
		
		if (i >= index)buffer[i]=arr[i+1];
		else buffer[i] = arr[i];
	}

	delete[] arr;
	rows--;
	return buffer;
}
