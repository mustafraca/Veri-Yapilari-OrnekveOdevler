#ifndef BAGLILÝSTE_H
#define BAGLILÝSTE_H

#include "Dugum.h"
template <typename T>

class bagliListe
{
private:
	Dugum<T> *ilk;
	Dugum<T> *yeniilk;
public:bagliListe()
{
	ilk = NULL;
	yeniilk = NULL;
}
void BasaDon()
{
	ilk = NULL;
}
void Ekle(T eleman)
{
	Dugum<T> *eklenecek = new Dugum<T>(eleman);
	if (eleman != '\r')
	{
		if (ilk)
		{
			Dugum<T> *son = ilk;
			while (son->sonraki != NULL)
				son = son->sonraki;
			son->sonraki = eklenecek;
		}
		else ilk = eklenecek;
	}
	if (ilk == NULL) throw Hata(2);
}
int Uzunluk()
{
	int uzunluk = 0;
	Dugum<T> *son = ilk;
	while (son != NULL)
	{
		uzunluk++;
		son = son->sonraki;
	}
	return uzunluk;
}
void TersCevir()
{
	Dugum<T> *gecici;
	Dugum<T> *onceki = NULL;
	Dugum<T> *son = ilk;
	while (son != NULL)
	{
		gecici = son->sonraki;
		son->sonraki = onceki;
		onceki = son;
		son = gecici;
	}
	ilk = onceki;
}
int Bul(char istenen)
{
	int sira = 0;
	Dugum<T> *son = ilk;
	while (son != NULL)
	{
		sira++;
		if (istenen == son->bilgi)
			return sira;
		son = son->sonraki;
	}
	throw Hata(1);
}
void BasaEkle(T eleman)
{
	Dugum<T> *eklenecek = new Dugum<T>(eleman);
	if (eleman != '\r')
	{
		if (yeniilk)
		{
			Dugum<T> *son = yeniilk;
			while (son->sonraki != NULL)
				son = son->sonraki;
			son->sonraki = eklenecek;
		}
		else yeniilk = eklenecek;
	}
	else
	{
		if (yeniilk == NULL) throw Hata(2);
		Dugum<T> *son = yeniilk;
		while (son->sonraki != NULL)
			son = son->sonraki;
		son->sonraki = ilk;
		ilk = yeniilk;
		yeniilk = NULL;
	}
}
void ArayaEkle(T eleman, char istenen)
{
	if (eleman != '\r')
	{
		Dugum<T> *eklenecek = new Dugum<T>(eleman);
		if (yeniilk)
		{
			Dugum<T> *son = yeniilk;
			while (son->sonraki != NULL)
				son = son->sonraki;
			son->sonraki = eklenecek;
		}
		else yeniilk = eklenecek;
	}
	else
	{
		if (yeniilk == NULL) throw Hata(2);
		Dugum<T> *son = ilk;
		while (son != NULL)
		{
			if (istenen == son->bilgi)
			{
				Dugum<T> *gecici = son->sonraki;
				son->sonraki = yeniilk;
				Dugum<T> *son = yeniilk;
				while (son->sonraki != NULL)
					son = son->sonraki;
				son->sonraki = gecici;
				yeniilk = NULL;
				return;
			}
			son = son->sonraki;
		}
	}
}
void MetniYaz()
{
	Dugum<T> *son = ilk;
	if (son == NULL)
		throw Hata(3);
	while (son->sonraki != NULL)
	{
		cout << son->bilgi;
		son = son->sonraki;
	}
	cout << son->bilgi;
}
};

#endif // !BAGLILÝSTE_H