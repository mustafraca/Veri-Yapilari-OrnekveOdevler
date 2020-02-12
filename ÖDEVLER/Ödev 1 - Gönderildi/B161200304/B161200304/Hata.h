#ifndef HATA_H
#define HATA_H

#include <iostream>
using namespace std;
class Hata
{
private:int hataKodu;
public:Hata(int hataKodu)
{
	this->hataKodu = hataKodu;
}
public:void Mesaj()
{
	switch (hataKodu)
	{
	case 1: cout << "Harf Metnin Ýçerisinde Bulunamamýþtýr."; break;
	case 2: cout << endl << "Boþ Geçilemez."; break;
	case 3: cout << "Metin Giriþi Bulunamadý."; break;
	default:cout << "Bilinmeyen Hata"; break;
	}
}
public:void Mesaj(int hataKodu)
{
	switch (hataKodu)
	{
	case 1:cout << "Harf Metnin Ýçerisinde Bulunamamýþtýr."; break;
	case 2:cout << endl << "Boþ Geçilemez."; break;
	case 3:cout << "Metin Giriþi Bulunamadý."; break;
	default:cout << "Bilinmeyen Hata"; break;
	}
}
};

#endif // !HATA_H
