
//3. Пользователь вводит данные о количестве студентов. Для каждого из них вводит: Фамилию и Имя, а так же оценку за лабораторную. Необходимо определить средний балл и вывести список студентов, чей бал выше среднего, подсветив их фамилии.
#define _CRT_SECURE_NO_WARNINGS
#include "stdafx.h"
#include <iostream>
#include<string>
#include<istream>
#include <Windows.h>
using namespace std;

struct study { char name[50]; int ball; };
int main()
{
	SetConsoleCP(1251);// позволяет записывать русские символы в строки/массивы 
	SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");
	
	//3.
	struct study mas[50];
	int n, k = 0;
	cout << endl;
	cout << "Введите количество студентов: " << endl;
	cin >> n;
	cout << "ИФ студента: " << endl;
	cout << "Оценка студента за лабораторную работу: " << endl;
	for (int i = 0; i < n;i++)
	{
		cout << i + 1 << ")" << endl;

		cin.ignore();
		cin.getline(mas[i].name, 50);


	}
	for (int i = 0; i < n; i++)
	{

		cout << mas[i].name << ":";
		cin >> mas[i].ball;
		cin.ignore();
	}

	int middle = 0;
	for (int i = 0;i < n;i++)
	{
		middle += mas[i].ball;
	}
	cout << endl;
	cout << "Средний балл группы: " << middle / n << endl;
	cout << endl;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	for (int i = 0;i < n;i++)
	{
		if (mas[i].ball > middle / n)
		{
			SetConsoleTextAttribute(hConsole, (WORD)((11 << 4) | 0));
			cout << mas[i].name << " " << mas[i].ball << endl;
		}
		else
		{
			SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 7));
			cout << mas[i].name << " " << mas[i].ball << endl;
		}
	}
	cout << endl;
	SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 7));
	system("pause");

	return 0;
}


