#include "stdafx.h"
#include <string>
#include <iostream>
#include <conio.h>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Turkish");

	//TEORİK OLARAK SONSUZ UZUNLUK METİN GİRİŞİ
	c/*out << "Sonsuz uzunlukta bir cümle giriniz: ";
	char karakter;
	do
	{
		karakter = _getche();

	} while (!(karakter == '\r'));*/

	/*cout << "Sonsuz uzunlukta bir cümle giriniz: ";
	char karakter;
	int kelime = 0, harf = 0;
	do
	{
		karakter = _getche();
		if (karakter == ' ') kelime++;
		else harf++;

	} while (!(karakter == '\r'));
	
	system("CLS");
	cout << "Kelime Sayısı: " << kelime + 1 << endl;
	cout << "Harf Sayısı: " << harf - 1 << endl;*/

	system("PAUSE");
    return 0;
}

