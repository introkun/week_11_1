#include <iostream>
#include <locale.h>

using namespace std;

int average(int(&arr)[10]);

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
	average(arr);
	return 0;
}

int average(int(&arr)[10])
{
	int const size = 10;
	int result[3]{ 0, 0, 0};

	for (int i = 0; i < size; i++)
	{
		if (arr[i] < 0)
		{
			result[0]++;
		}
		else if (arr[i] == 0)
		{
			result[1]++;
		}
		else
		{
			result[2]++;
		}
	}
	cout << "<0 = " << result[0] << endl << "=0 = " << result[1] << endl << ">0 = " << result[2] << endl;
	return result[3];
}