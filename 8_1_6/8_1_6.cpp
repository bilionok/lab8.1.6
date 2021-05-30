/*
Дано літерний рядок, який містить послідовність символів s0, ..., sn, ... .
1. Вияснити, чи є серед цих символів пара сусідніх букв “no” або “on”.
2. Замінити кожну пару сусідніх букв “no” трійкою зірочок “***”.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
void Change(char* str);

int main()
{
	char str[101]; // оголошується масив
	cout << "Enter string:" << endl;
	cin.getline(str, 100); // вводяться написані символи в масив

	Change(str);
	cout << "Result: " << str << endl;

}

void Change(char* str)
{
	char* t = new char[strlen(str)];
	int d;
	int pos1 = 0;
	int pos2 = 0;
	*t = 0;
	d = strlen(str); // довжина рядка str
	int i = 0;
	while (i < strlen(str) - 1)
	{
		if (str[i] == 'n' && str[i + 1] == 'o')  // провірка на одинакові символи
		{
			pos2 = i + 2; 
			strncat(t, str + pos1, pos2 - pos1 - 2); // в допоміжний масив добавляється все, що стоїть перед однаковими символами
			strcat(t, "***"); // в допоміжний масив вносяться символи, які заміняють однакові символи
			pos1 = pos2; // задається точка, до якої заміна вже проведена
			i += 2;
		}
		i++;
	}
	strcat(t, str + pos1); 
	strcpy(str, t); // копіюється строка t в str
}