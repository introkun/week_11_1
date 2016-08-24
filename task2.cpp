#include <iostream>
#include <locale.h>

using namespace std;

int average(int[10]);

int main()
{
	setlocale(LC_ALL, "rus");

	int const size = 10;
	int arr[size];
	for (int i = 0; i < size; i++)
	{
		cout << "введите значение " << i + 1 << " = ";
		cin >> arr[i];
	}
	cout << average(arr) << endl;
}

int average(int arr[10])
{
	int const size = 10;
	int result = 0;

	for (int i = 0; i < size; i++)
	{
		result += arr[i];
	}
	result /= size;
	return result;
}
