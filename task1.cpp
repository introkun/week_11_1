#include <iostream>
#include <locale.h>

using namespace std;

int yearLeap(int(&dataStart)[3], int(&dataStop)[3]);
int daysMonth(int(&dataStart)[3], int(&dataStop)[3]);
int day(int(&dataStart)[3], int(&dataStop)[3]);

int main()
{
	setlocale(LC_ALL, "rus");
	int const size = 3;
	int dataStart[size];
	int dataStop[size];

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (j == 0)
			{
				cout << "введите год";
			}
			else if (j == 1)
			{
				cout << "введите месяц";
			}
			else
			{
				cout << "вветеде день";
			}
			if (i == 0)
			{
				cin >> dataStart[j];
			}
			else
			{
				cin >> dataStop[j];
			}
		}
	}
	cout << day(dataStart, dataStop) << endl;
}

int day(int(&dataStart)[3], int(&dataStop)[3])
{
	int result;
	int year = yearLeap(dataStart, dataStop);
	int month = daysMonth(dataStart, dataStop);
	int day = dataStart[2] + dataStop[2];
	result = year - (month - day);
	return result;
}
int yearLeap(int(&dataStart)[3], int(&dataStop)[3])
{
	int result = 0;
	for (; dataStart[0] <= dataStop[0]; dataStart[0]++)
	{
		if (dataStart[0] % 4 == 0 &&
			dataStart[0] % 100 != 0 ||
			dataStart[0] % 400 == 0)
		{
			result += 366;
		}
		else
		{
			result += 365;
		}
	}
	return result;
}

int daysMonth(int(&dataStart)[3], int(&dataStop)[3])
{
	int result = 0;
	int l = 0;
	int i = 0;
	for (int j = 0; j < 2; j++)
	{
		if (j == 0)
		{
			l = dataStart[1];
			i = 1;
		}
		else
		{
			l = 12;
			i = dataStop[1];
		}

		for (; i <= l; i++)
		{
			if (i == 4 ||
				i == 6 ||
				i == 9 ||
				i == 11)
			{
				result += 30;
			}
			else if (i == 2 &&
				dataStart[1] % 4 == 0 &&
				dataStart[1] % 100 != 0 ||
				i == 2 &&
				dataStart[1] % 400 == 0)
			{
				result += 29;
			}
			else if (i == 2 &&
				dataStart[1] % 4 != 0 &&
				dataStart[1] % 100 == 0 ||
				i == 2 &&
				dataStart[1] % 400 != 0)
			{
				result += 28;
			}
			else
			{
				result += 31;
			}
		}
	}
	return result;
}