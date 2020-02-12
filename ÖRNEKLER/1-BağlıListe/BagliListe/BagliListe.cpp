#include "stdafx.h"
#include "bagliListe.h"
#include <conio.h>
#include <iostream>
#include <string>
#include "Hata.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "Turkish");
	int secim;
	int eleman, indis;
	bagliListe<int> *Liste = new bagliListe<int>();
	do
	{
		system("cls");
		cout << "..��LEMLER" << endl;
		cout << "..1-Eleman Say�s�" << endl;
		//cout << "..2-Kapasite" << endl;
		cout << "..3-Eleman Ekle" << endl;
		cout << "..4-Eleman Bul" << endl;
		cout << "..5-�ndis Bul" << endl;
		cout << "..6-Eleman Sil" << endl;
		cout << "..7-�ndis ile Eleman Sil" << endl;
		cout << "..71-De�eri ile Eleman Sil" << endl;
		cout << "..8-Eleman Listeleme" << endl;
		cout << "..9-�ndis ikle Eleman Ekle" << endl;
		cout << "..10-Eleman De�i�tir" << endl;
		cout << "..11-BosMu ?:" << endl;
		cout << "..12-Son Eleman:" << endl;
		cout << "..13-�lk Elemanan :" << endl;
		cout << "..99-��k��" << endl;
		cout << ".. Se�iminiz :::"; cin >> secim;
		system("cls");
		try
		{
			switch (secim)
			{
			case 1:cout << "Eleman Say�s�:" <<
				Liste->Uzunluk() << endl;
				break;
			/*case 2:cout << "Listesinin Kapasitesi:" <<
				diziListesi->kapasiteGetir() << endl;
				break;*/
			case 3:
				cout << "Ekelenecek de�er: ";
				cin >> eleman;
				Liste->Ekle(eleman);
				break;
			case 4:cout << "Aranan de�er: ";
				cin >> eleman;
				cout << "Aranan de�er indisi: " <<
				Liste->Bul(eleman) << endl;
				break;
			case 5:
				cout << "Eleman�n indisi:";
				cin >> indis;
				cout << "�ndisdeki Eleman : " <<
					Liste->indisileBul(indis) << endl;
				break;
			case 6:
				Liste->Sil();
				cout << "Eleman Silindi" << endl;
				break;
		    case 7:
				cout << "Eleman�n indisi:";
				cin >> indis;
				Liste->indisdekiniSil(indis);
				cout << "Eleman Silindi" << endl;
				break;
			case 71:
				cout << "Eleman�n de�eri:";
				cin >> eleman;
				Liste->degerileSil(eleman);
				cout << "Eleman Silindi" << endl;
				break;
			case 8:
				Liste->Listele();
				break;
			case 9:
				cout << "Ekelenecek de�er: ";
				cin >> eleman;
				cout << "Eleman�n indisi:";
				cin >> indis;
				Liste->arayaEkle(eleman,indis);
			case 10:
				cout << "De�i�tirilecek de�er: ";
				cin >> eleman;
				cout << "Eleman�n indisi:";
				cin >> indis;
				Liste->Degistir(eleman, indis);
			case 11:
				if (Liste->bosMu()) cout << "Liste Bo�" << endl;
				else cout << "Liste Bo� De�il" << endl;
				break;
			case 12:
				cout << "Son Eleman : " << Liste->son() << endl;
				break;
			case 13:
				cout << "�lk Eleman : " << Liste->ilki() << endl;
				break;
			case 14:
				cout << Liste->deneme() << endl;
			case 99: break;
			default:
				cout << "Hatal� Se�im" << endl;
				break;
			}
		}
		catch (Hata h)
		{
			h.Mesaj();
		}
		if (secim != 99)
		{
			cout << "Devam Etmek i�in Bir tu�a bas�n�z...";
			_getch();
		}
	} while (secim != 99);
	return 0;
}

