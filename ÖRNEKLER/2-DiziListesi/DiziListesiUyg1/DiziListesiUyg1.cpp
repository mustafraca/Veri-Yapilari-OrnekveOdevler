#include "stdafx.h"
#include "DiziListesi.h"
#include <conio.h>
#include <iostream>
#include "Hata.h"
using namespace std;
int main()
{
	setlocale(LC_ALL, "Turkish");
	char secim;
	int eleman, indis;
	DiziListesi<int> *diziListesi = new DiziListesi<int>();
	do
	{
		system("cls");
		cout << "..��LEMLER" << endl;
		cout << "..1-Eleman Say�s�" << endl;
		cout << "..2-Kapasite" << endl;
		cout << "..3-Eleman Ekle" << endl;
		cout << "..4-Eleman Getir" << endl;
		cout << "..5-�ndis ile Eleman Getir" << endl;
		cout << "..6-Eleman Sil" << endl;
		cout << "..7-�ndis ile Eleman Sil" << endl;
		cout << "..E-��k��" << endl;
		cout << ".. Se�iminiz :::"; cin >> secim;
		system("cls");
		try
		{
			switch (secim)
			{
			case '1':cout << "Eleman Say�s�:" <<
				diziListesi->elemanSayisi() << endl;
				break;
			case '2':cout << "Listesinin Kapasitesi:" <<
				diziListesi->kapasiteGetir() << endl;
				break;
			case '3':
				cout << "Ekelenecek de�er: ";
				cin >> eleman;
				diziListesi->Ekle(eleman);
				break;
			case '4':cout << "Son eklenen de�er : " <<
				diziListesi->elemanGetir() << endl;
				break;
			case '5':
				cout << "Eleman�n indisi:";
				cin >> indis;
				cout << "�ndisdeki Eleman : " <<
					diziListesi->indisdekiEleman(indis) << endl;
				break;
			case '6':
				diziListesi->Sil();
				cout << "Eleman Silindi" << endl;
				break;
			case '7':
				cout << "Eleman�n indisi:";
				cin >> indis;
				diziListesi->indisdekiniSil(indis);
				cout << "Eleman Silindi" << endl;
				break;
			case 'E': break;
			default:
				cout << "Hatal� Se�im" << endl;
				break;
			}
		}
		catch (Hata h)
		{
			h.Mesaj();
		}
		if (secim != 'E')
		{
			cout << "Devam Etmek i�in Bir tu�a bas�n�z...";
			_getch();
		}
	} while (secim != 'E');
    return 0;
}

