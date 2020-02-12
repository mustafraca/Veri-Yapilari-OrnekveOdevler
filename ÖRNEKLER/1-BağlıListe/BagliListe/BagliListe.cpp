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
		cout << "..ÝÞLEMLER" << endl;
		cout << "..1-Eleman Sayýsý" << endl;
		//cout << "..2-Kapasite" << endl;
		cout << "..3-Eleman Ekle" << endl;
		cout << "..4-Eleman Bul" << endl;
		cout << "..5-Ýndis Bul" << endl;
		cout << "..6-Eleman Sil" << endl;
		cout << "..7-Ýndis ile Eleman Sil" << endl;
		cout << "..71-Deðeri ile Eleman Sil" << endl;
		cout << "..8-Eleman Listeleme" << endl;
		cout << "..9-Ýndis ikle Eleman Ekle" << endl;
		cout << "..10-Eleman Deðiþtir" << endl;
		cout << "..11-BosMu ?:" << endl;
		cout << "..12-Son Eleman:" << endl;
		cout << "..13-Ýlk Elemanan :" << endl;
		cout << "..99-Çýkýþ" << endl;
		cout << ".. Seçiminiz :::"; cin >> secim;
		system("cls");
		try
		{
			switch (secim)
			{
			case 1:cout << "Eleman Sayýsý:" <<
				Liste->Uzunluk() << endl;
				break;
			/*case 2:cout << "Listesinin Kapasitesi:" <<
				diziListesi->kapasiteGetir() << endl;
				break;*/
			case 3:
				cout << "Ekelenecek deðer: ";
				cin >> eleman;
				Liste->Ekle(eleman);
				break;
			case 4:cout << "Aranan deðer: ";
				cin >> eleman;
				cout << "Aranan deðer indisi: " <<
				Liste->Bul(eleman) << endl;
				break;
			case 5:
				cout << "Elemanýn indisi:";
				cin >> indis;
				cout << "Ýndisdeki Eleman : " <<
					Liste->indisileBul(indis) << endl;
				break;
			case 6:
				Liste->Sil();
				cout << "Eleman Silindi" << endl;
				break;
		    case 7:
				cout << "Elemanýn indisi:";
				cin >> indis;
				Liste->indisdekiniSil(indis);
				cout << "Eleman Silindi" << endl;
				break;
			case 71:
				cout << "Elemanýn deðeri:";
				cin >> eleman;
				Liste->degerileSil(eleman);
				cout << "Eleman Silindi" << endl;
				break;
			case 8:
				Liste->Listele();
				break;
			case 9:
				cout << "Ekelenecek deðer: ";
				cin >> eleman;
				cout << "Elemanýn indisi:";
				cin >> indis;
				Liste->arayaEkle(eleman,indis);
			case 10:
				cout << "Deðiþtirilecek deðer: ";
				cin >> eleman;
				cout << "Elemanýn indisi:";
				cin >> indis;
				Liste->Degistir(eleman, indis);
			case 11:
				if (Liste->bosMu()) cout << "Liste Boþ" << endl;
				else cout << "Liste Boþ Deðil" << endl;
				break;
			case 12:
				cout << "Son Eleman : " << Liste->son() << endl;
				break;
			case 13:
				cout << "Ýlk Eleman : " << Liste->ilki() << endl;
				break;
			case 14:
				cout << Liste->deneme() << endl;
			case 99: break;
			default:
				cout << "Hatalý Seçim" << endl;
				break;
			}
		}
		catch (Hata h)
		{
			h.Mesaj();
		}
		if (secim != 99)
		{
			cout << "Devam Etmek için Bir tuþa basýnýz...";
			_getch();
		}
	} while (secim != 99);
	return 0;
}

