#include "stdafx.h"
#include <iostream>
#include <string>
#include "Stack.h"
#include "Hata.h"
#include "StackBagliListe.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "Turkish");

	string isim;
	cout << "Ýsim: ";
	cin >> isim;
	//Stack<char> *stack = new Stack<char>(5);
	StackBL<char> *stack = new StackBL<char>();
	for (int i = 0;i < 7, isim[i] != '\0';i++)
	{
		try
		{
			stack->PUSH(isim[i]);
		}
		catch (Hata h)
		{
			h.Mesaj();
		}
	}
	cout << "---------" << endl;
	for (int i = 0;i < 7, isim[i] != '\0';i++)
	{
		try
		{
			stack->POP();
		}
		catch (Hata h)
		{
			h.Mesaj();
		}
	}

	system("PAUSE");
    return 0;
}

