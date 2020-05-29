/***************************************************************
|                     SAKARYA UNÝVERSÝTESÝ					   |
|			BÝLGÝSAYAR VE BÝLÝÞÝM BÝLÝMLERÝ FAKÜLTESÝ	       |				
|				 BÝLÝÞÝM SÝSTEMLERÝ MÜHENDÝSLÝÐÝ               |
|						2017-2018 GÜZ                          |
|						VERÝ YAPILARI                          |
|                                                              |
|                                                              |
|           ÖDEV NUMARASI:    1                                |
|			ÖÐRENCÝ NUMARASI: B161200304                       |
|			ÖÐRENCÝ AD SOYAD: Mustafa ACAR                     |
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

//Düðüm içerisinde tutulan deðerlerin ekrana yazdýrýlmasýný tek fonksiyonda kullandým.
void MetniYazdir()
{
	system("CLS");
	Liste->MetniYaz();
}

int main()
{
	setlocale(LC_ALL, "Turkish");

	int secim;
	//Eleman deðiþkeni, karakter giriþi için kullanýlmaktadýr.
	//Ýstenen deðiþkeni, arama ve istenen harften sonrasýna metin giriþi için kullanýlmaktadýr.
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
		cout << endl << "Devam etmek için bir tuþa basýnýz...";
		_getch();
	} while (true);

	do
	{
		system("CLS");
		cout << ":::MENÜ:::" << endl;
		cout << "1- Metni Deðiþtir" << endl;
		cout << "2- Metnin Karakter Sayýsý" << endl;
		cout << "3- Metni Tersine Çevir" << endl;
		cout << "4- Metin Ýçerisinde Bir Deðer Ara" << endl;
		cout << "5- Metnin Öncesine Yeni Metin Ekle" << endl;
		cout << "6- Metnin Sonrasýna Yeni Metin Ekle" << endl;
		cout << "7- Seçilen Karakterden Sonrasýna Yeni Metin Ekle" << endl;
		cout << "8- Metni Yazdýr" << endl;
		cout << "99- ÇIKIÞ" << endl;
		cout << "Seçiminiz: ";
		cin >> secim;
		system("CLS");
		try
		{
			switch (secim)
			{
			case 1:
				Liste->BasaDon(); //Baðlý liste header sayfasýnda kullanýlan ilk adlý pointerýn adresini "NULL" yapar.
				cout << "Yeni Metin Giriniz: ";
				do
				{
					eleman = _getche();
					Liste->Ekle(eleman);

				} while (!(eleman == '\r'));
				break;
			case 2:
				cout << "Metindeki Karakter Sayýsý: " << Liste->Uzunluk();
				break;
			case 3:
				Liste->TersCevir();
				MetniYazdir();
				break;
			case 4:
				cout << "Aramak Ýstediðiniz Harf: ";
				cin >> istenen;
				if (Liste->Bul(istenen) == false) break;
				cout << istenen << " Harfi Metnin Ýçerisinde Vardýr. " << "Sýrasý: " << Liste->Bul(istenen);
				break;
			case 5:
				cout << "Baþa Eklenecek Metni Giriniz: ";
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
				cout << "Hatalý Giriþ Yaptýnýz!";
				break;
			}
		}
		catch (Hata h)
		{
			h.Mesaj();
		}
		if (secim == 99)
			break;
		cout << endl << "Devam etmek için bir tuþa basýnýz...";
		_getch();
	} while (secim != 99);
    return 0;
}

