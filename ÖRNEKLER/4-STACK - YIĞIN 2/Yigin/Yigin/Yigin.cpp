#include "stdafx.h"
#include<iostream>
#include<string>
#include"Stack.h"
#include"Hata.h"
#include "StackBagliListe.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "Turkish");
	//string isim;
	//Stack<char> *stack = new Stack<char>(5);
	StackBL<double> *stack = new StackBL<double>();
	string postfix = "7 2.5 5 7 + - *";
	string deger = "";
	char deger1[10];
	int k = 0;
	double sayi1, sayi2,sonuc;
	for (int i = 0;postfix[i] != '\0';i++)
	{
		
		//double sayi1, sayi2;
		if (postfix[i + 1] == '\0' || postfix[i] == ' ')
		{
			if (postfix[i + 1] == '\0')
			{
				deger += postfix[i];
			}
			deger1[k++] = '\0';
			if (deger == "+" || deger == "-" || deger == "*" || deger == "/")
			{
				sayi2 = stack->POP();
				sayi1 = stack->POP();
				if (deger == "+") sonuc = sayi1 + sayi2;
				else if (deger == "-") sonuc = sayi1 - sayi2;
				else if (deger == "*") sonuc = sayi1 * sayi2;
				else if (deger == "/") sonuc = sayi1 / sayi2;
				cout << sayi1<<" "<<deger<<" "<<sayi2<<" : "<< sonuc << endl;
				stack->PUSH(sonuc);
			}
			else
			{
				stack->PUSH(atof(deger1));
			}
			deger = "";
			k = 0;
		}
		else
		{
			deger += postfix[i];
			deger1[k++] = postfix[i];
		}
		/*for (;postfix[i] != ' ';i++)
		{
			if (postfix[i] == '\0')break;
			deger += postfix[i];
		}
		cout << deger << endl;*/
	}
	cout << stack->POP() << endl;



	system("pause");
    return 0;
}

