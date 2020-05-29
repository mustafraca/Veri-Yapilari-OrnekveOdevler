/***************************************************************
|                     SAKARYA UN�VERS�TES�					   |
|			B�LG�SAYAR VE B�L���M B�L�MLER� FAK�LTES�	       |				
|				 B�L���M S�STEMLER� M�HEND�SL���               |
|						2017-2018 G�Z                          |
|						VER� YAPILARI                          |
|                                                              |
|                                                              |
|           �DEV NUMARASI:    1                                |
|			��RENC� NUMARASI: B161200304                       |
|			��RENC� AD SOYAD: Mustafa ACAR                     |
|                                                              |
|                                                              |
***************************************************************/
#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <string>
#include "BagliListe.h"
#include "Dugum.h"
#include "Hata.h"
using namespace std;

bagliListe<char> *Liste = new bagliListe<char>();

//D���m i�erisinde tutulan de�erlerin ekrana yazd�r�lmas�n� tek fonksiyonda kulland�m.
void MetniYazdir()
{
	system("CLS");
	Liste->MetniYaz();
}

int main()
{
	setlocale(LC_ALL, "Turkish");

	int secim;
	//Eleman de�i�keni, karakter giri�i i�in kullan�lmaktad�r.
	//�stenen de�i�keni, arama ve istenen harften sonras�na metin giri�i i�in kullan�lmaktad�r.
	char eleman, istenen;

	do
	{
		system("CLS");
		cout << "Bir Metin Giriniz: ";
		try
		{
			do
			{
				eleman = _getche();
				Liste->Ekle(eleman);
			} while (!(eleman == '\r'));
			break;
		}
		catch (Hata h)
		{
			h.Mesaj();
		}
		cout << endl << "Devam etmek i�in bir tu�a bas�n�z...";
		_getch();
	} while (true);

	do
	{
		system("CLS");
		cout << ":::MEN�:::" << endl;
		cout << "1- Metni De�i�tir" << endl;
		cout << "2- Metnin Karakter Say�s�" << endl;
		cout << "3- Metni Tersine �evir" << endl;
		cout << "4- Metin ��erisinde Bir De�er Ara" << endl;
		cout << "5- Metnin �ncesine Yeni Metin Ekle" << endl;
		cout << "6- Metnin Sonras�na Yeni Metin Ekle" << endl;
		cout << "7- Se�ilen Karakterden Sonras�na Yeni Metin Ekle" << endl;
		cout << "8- Metni Yazd�r" << endl;
		cout << "99- �IKI�" << endl;
		cout << "Se�iminiz: ";
		cin >> secim;
		system("CLS");
		try
		{
			switch (secim)
			{
			case 1:
				Liste->BasaDon(); //Ba�l� liste header sayfas�nda kullan�lan ilk adl� pointer�n adresini "NULL" yapar.
				cout << "Yeni Metin Giriniz: ";
				do
				{
					eleman = _getche();
					Liste->Ekle(eleman);

				} while (!(eleman == '\r'));
				break;
			case 2:
				cout << "Metindeki Karakter Say�s�: " << Liste->Uzunluk();
				break;
			case 3:
				Liste->TersCevir();
				MetniYazdir();
				break;
			case 4:
				cout << "Aramak �stedi�iniz Harf: ";
				cin >> istenen;
				if (Liste->Bul(istenen) == false) break;
				cout << istenen << " Harfi Metnin ��erisinde Vard�r. " << "S�ras�: " << Liste->Bul(istenen);
				break;
			case 5:
				cout << "Ba�a Eklenecek Metni Giriniz: ";
				do
				{
					eleman = _getche();
					Liste->BasaEkle(eleman);

				} while (!(eleman == '\r'));
				MetniYazdir();
				break;
			case 6:
				cout << "Sona Eklenecek Metni Giriniz: ";
				do
				{
					eleman = _getche();
					Liste->Ekle(eleman);

				} while (!(eleman == '\r'));
				MetniYazdir();
				break;
			case 7:
				cout << "Hangi Harften Sonra Eklenecek: ";
				cin >> istenen;
				if (Liste->Bul(istenen) == false) break;
				cout << "Araya Eklenecek Metin Giriniz: ";
				do
				{
					eleman = _getche();
					Liste->ArayaEkle(eleman, istenen);

				} while (!(eleman == '\r'));
				MetniYazdir();
				break;
			case 8:
				MetniYazdir();
				break;
			case 99:
				break;
			default:
				cout << "Hatal� Giri� Yapt�n�z!";
				break;
			}
		}
		catch (Hata h)
		{
			h.Mesaj();
		}
		if (secim == 99)
			break;
		cout << endl << "Devam etmek i�in bir tu�a bas�n�z...";
		_getch();
	} while (secim != 99);
    return 0;
}

