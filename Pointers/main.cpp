#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

//#define POINTERS_BASICS

void main()
{
	setlocale(LC_ALL, "");
#ifdef POINTERS_BASICS
	int a = 2;				//Объявление переменной 'a' и инициализация ее значением 2
	int* pa = &a;			//Объявление укзателя 'pa' и инициализация его адресом переменной 'a'
	//pa - pointer_to_a (указатель на 'a')

	cout << a << endl;	//Вывод значения переменной 'a' на экран
	cout << &a << endl;	//Взятие адреса переменной 'a' прямо при выводе
	cout << pa << endl;	//Вывод адреса переменной 'a', хранящегося в указателе 'pa'
	cout << *pa << endl;//Разыменование указателя 'pa', и вывод на экран значения по адресу

	int* pb;
	int b = 3;
	pb = &b;
	// (int) (int*)
		//int - int
		//int* - указатель на int
		//double - double
		//double* - указатель на double
	cout << b << endl;
	cout << &b << endl;
	cout << pb << endl;
	cout << *pb << endl;
#endif // POINTERS_BASICS

	const int n = 5;
	int arr[n] = { 3, 5, 8, 13, 21 };
	cout << arr << endl;
	cout << *arr << endl;
	for (int i = 0; i < n; i++)
	{
		cout << *(arr + i) << "\t";
	}
	cout << endl;
}



//& - Address-of operator (Оператор взятия адреса)
//* - Dereference operator (Оператор разыменования)