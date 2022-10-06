#include<iostream>
using namespace std;
using std:: cin;
using std:: cout;
using std:: endl;
#define tab "\t";

template<typename T> T** Allocate(const int rows, const int cols);
template<typename T> void Clear(T** arr, const int rows);

void FillRand(int arr[], const int n);
void FillRand(double arr[], const int n);
void FillRand(char arr[], const int n);

void FillRand(int** arr, const int rows,const int cols);
void FillRand(double** arr, const int rows,const int cols);
void FillRand(char** arr, const int rows,const int cols);

template<typename T> void Print(T* arr, const int n);
template<typename T> void Print(T** arr, const int rows,const int cols);

template<typename T> T* push_back(T* arr,  int& n, T value);
template<typename T> T** push_row_back(T** arr, int& rows, const int cols);
template<typename T> void push_col_back(T** arr, int rows,int& cols);

template<typename T> T* push_front(T* arr, int& n, int value);
template<typename T> T** push_row_front(T** arr, int& rows, const int cols);
template<typename T> void push_col_front(T** arr, int rows, int& cols);

template<typename T> T* insert(T* arr, int& n, int value, int index);
template<typename T> T** insert_row(T** arr, int& rows, int cols, int index);


template<typename T> T* pop_back(T* arr, int& n);
template<typename T> T** pop_row_back(T** arr, int& rows, int cols);
template<typename T> void pop_col_back(T** arr, int rows, int& cols);
 

template<typename T> T* pop_front(T* arr, int& n);
template<typename T> T** pop_row_front(T** arr, int& rows, int cols);
template<typename T> void pop_col_front(T** arr,const int rows, int& cols);

template<typename T> T* pop_erase(T* arr, int& n,int index);
template<typename T> T** erase_row(T** arr, int& rows, int cols, int index);

//#define DYNAMIC_MEMORY_1
#define DYNAMIC_MEMORY_2_ROWS
//#define DYNAMIC_MEMORY_3_COLS

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
	
#ifdef DYNAMIC_MEMORY_2_ROWS

	int rows, cols, index{};
	cout << "Введите количество строк: "; cin >> rows;
	cout << "Введите количество элементов строк: "; cin >> cols;

	char** arr = Allocate<char>(rows, cols);
	FillRand(arr, rows, cols);
	Print(arr, rows, cols);

	cout << "Добавляем строку в конец массива: " << endl;
	arr = push_row_back(arr, rows, cols);
	FillRand(arr[rows - 1], cols);
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

#ifdef DYNAMIC_MEMORY_3_COLS

	int rows, cols, index{};
	cout << "Введите количество строк: "; cin >> rows;
	cout << "Введите количество элементов строк: "; cin >> cols;

	char** arr = Allocate<char>(rows, cols);
	FillRand(arr, rows, cols);
	Print(arr, rows, cols);

	cout << "Добавляем столбец в конец массива: " << endl;
	push_col_back(arr, rows, cols);
	for (int i = 0; i < rows; i++)arr[i][cols - 1] = rand();
	Print(arr, rows, cols);

	cout << "Добавляем столбец в начало массива: " << endl;
	push_col_front(arr, rows, cols);
	Print(arr, rows, cols);

	cout << "Удаляем столбец в конце массива: " << endl;
	pop_col_back(arr, rows, cols);
	Print(arr, rows, cols);

	cout << "Удаляем нулевой столбец из массива: " << endl;
	pop_col_front(arr, rows, cols);
	Print(arr, rows, cols);

	Clear(arr, rows);
#endif // DYNDYNAMIC_MEMORY_3_COLS

}
template<typename T>T** Allocate(const int rows, const int cols)
{
	//1) Создаем массив указателей:
	T** arr = new T * [rows];
	//2) Выделяем память под строки двумерного массива:
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new T[cols]{};
	}
	return arr;
}
template<typename T>void Clear(T** arr, const int rows)
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
void FillRand(double arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		//Через арифметику указателей и разыменования
		*(arr + i) = rand() % 10000;
		*(arr+1) /= 100;
	}
}
void FillRand(char arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		//Через арифметику указателей и разыменования
		*(arr + i) = rand();
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
void FillRand(double** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % 10000;
			arr[i][j] /= 100;
		}
	}
}
void FillRand(char** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand();
		}
	}
}

template<typename T>void Print(T* arr, const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}
template<typename T>void Print(T** arr, const int rows, const int cols)
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

template<typename T>T* push_back(T* arr, int& n, T value)
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
template<typename T>T** push_row_back(T** arr, int& rows, const int cols)
{
	//1)Создаем новый буферный массив указателей нужного размер: 
	T** buffer = new T * [rows + 1];
	//2)Копируем адреса строк из исходного массива указателей в буферный:
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = arr[i];
	}
	//3)Удаляем исходный массив указателей:
	delete[]arr;
	//4)создаем новую строку:
	buffer[rows] = new T[cols]{};
	//5)После добавления строки в массив количество строк увеличивается
	rows++;
	//6)Возвращаем адрес нового массива
	return buffer;
}
template<typename T>void push_col_back(T** arr, int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		//1) Создаем новую строку нужного размера
		T* buffer = new T[cols + 1]{};
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

template<typename T>T* push_front(T* arr, int& n, int value)
{
	T* buffer = new T[n + 1];

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
template<typename T>T** push_row_front(T** arr, int& rows, const int cols)
{
	T** buffer = new T * [rows + 1];

	for (int i = 0; i < rows + 1; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[]arr;

	buffer[0] = new T[cols]{};
	rows++;
	return buffer;
}
template<typename T>void push_col_front(T** arr, int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols + 1]{};
		for (int j = 0; j < cols + 1; j++)buffer[j + 1] = arr[i][j];
		delete[] arr[i];

		arr[i] = buffer;
	}
	cols++;
}

template<typename T>T* insert(T* arr, int& n, int value, int index)
{
	T* buf = new T[n + 1];
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
template<typename T>T** insert_row(T** arr, int& rows, int cols, int index)
{
	T** buffer = new T * [rows + 1];
	int counter = 0;
	for (int i = 0; i < rows + 1; i++)
	{
		/*if (i == index)buffer[i] = new int[cols] {};
		else buffer[i] = arr[counter++];*/
		i == index ? buffer[i] = new T[cols]{} : buffer[i] = arr[counter++];
	}
	delete[] arr;
	arr = buffer;
	rows++;
	return arr;
}

template<typename T>T* pop_back(T* arr, int& n)
{
	T* buffer = new T[n - 1];
	for (int i = 0; i < n - 1; i++)
	{
		buffer[i] = arr[i];
	}
	delete[]arr;
	arr = buffer;
	n--;
	return arr;
}
template<typename T>T** pop_row_back(T** arr, int& rows, int cols)
{
	/*T** buffer = new T*[rows - 1];
	for (int i = 0; i < rows - 1; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	buffer[rows] = new T[cols] {};
	rows--;
	return buffer;*/

	//1)Удаляем строку из памяти
	delete[] arr[rows - 1];
	//2)Переопределяем массив указателей
	T** buffer = new T * [--rows]{};
	for (int i = 0; i < rows; i++)buffer[i] = arr[i];
	delete[] arr;
	return buffer;
}
template<typename T>void pop_col_back(T** arr, int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols - 1]{};
		for (int j = 0; j < cols - 1; j++)
			buffer[j] = arr[i][j];
		delete[]arr[i];
		arr[i] = buffer;
	}
	cols--;
}

template<typename T>T* pop_front(T* arr, int& n)
{
	T* buffer = new T[n - 1];
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i + 1];
	}
	delete[]arr;
	arr = buffer;
	n--;
	return arr;
}
template<typename T>T** pop_row_front(T** arr, int& rows, int cols)
{
	T** buffer = new T * [rows - 1];
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = arr[i + 1];
	}
	delete[] arr;
	buffer[rows] = new T[cols]{};
	rows--;
	return buffer;
}
template<typename T>void pop_col_front(T** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols - 1]{};
		for (int j = 1; j < cols; j++)
			buffer[j - 1] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;

	}
	cols--;
}

template<typename T>T* pop_erase(T* arr, int& n, int index)
{
	T* buffer = new T[n - 1];
	int counter = 0;
	for (int i = 0; i < n; i++, counter++)
	{
		if (i == index)buffer[i] = arr[++counter];
		else buffer[i] = arr[counter];
	}
	delete[]arr;
	arr = buffer;
	n--;
	return arr;
}
template<typename T>T** erase_row(T** arr, int& rows, int cols, int index)
{
	T** buffer = new T * [rows - 1];

	for (int i = 0; i < rows - 1; i++)
	{

		if (i >= index)buffer[i] = arr[i + 1];
		else buffer[i] = arr[i];
	}

	delete[] arr;
	rows--;
	return buffer;
}



