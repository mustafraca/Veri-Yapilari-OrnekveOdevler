#pragma once
#include"Dugum.h"
template<typename T>
class bagliListe
{
private:Dugum<T> *ilk;
public:bagliListe()
{
	ilk = NULL;
}
public:int Uzunluk()
{
	int u = 0;
	Dugum<T> *son = ilk;
	while (son != NULL)
	{
		u++;
		son = son->sonraki;
	}
	return u;
}
public:void Listele()
{
	int u = 0;
	Dugum<T> *son = ilk;
	while (son != NULL)
	{
		u++;
		cout << u << ". eleman : " << son->bilgi << endl;
		son = son->sonraki;
	}
}
public:void Ekle(T eleman)
{
	Dugum<T> *eklenecek = new Dugum<T>(eleman);
	if (ilk)
	{
		Dugum<T> *son = ilk;
		while (son->sonraki != NULL) son = son->sonraki;
		son->sonraki = eklenecek;
	}
	else ilk = eklenecek;
}
public:void arayaEkle(T eleman,int indis)
{
	Dugum<T> *eklenecek = new Dugum<T>(eleman);
	if (indis<0 || indis>Uzunluk()) throw Hata(3);
	else if (indis == Uzunluk()) Ekle(eleman);
	else if (indis == 0)
	{
		eklenecek->sonraki = ilk;
		ilk = eklenecek;
	}
	else
	{
		int ei = 0;
		Dugum<T> *son = ilk;
		while (ei < indis - 1)
		{
			ei++;
			son = son->sonraki;
		}
		eklenecek->sonraki = son->sonraki;
		son->sonraki = eklenecek;
	}	
}
public:void Degistir(T eleman, int indis)
{
	if (indis < 0 || indis >= Uzunluk()) throw Hata(3);
	if (ilk)
	{
		Dugum<T> *degistirilecek = ilk;
		int ei = 0;
		while (ei != indis)
		{
			ei++;
			degistirilecek=degistirilecek->sonraki;
		}
		degistirilecek->bilgi = eleman;
	}
	else throw Hata(2);
}
public:T indisileBul(int indis)
{
	if (indis < 0 || indis >= Uzunluk()) throw Hata(3);
	if (ilk)
	{
		Dugum<T> *aranan = ilk;
		int ei = 0;
		while (ei != indis)
		{
			ei++;
			aranan = aranan->sonraki;
		}
		return aranan->bilgi;
	}
	else throw Hata(2);
}
public:int Bul(T eleman)
{
	if (ilk)
	{
		Dugum<T> *aranacak = ilk;
		int ei = 0;
		while (aranacak != NULL)
		{
			if (aranacak->bilgi == eleman) return ei;
			ei++;
			aranacak = aranacak->sonraki;
		}
		throw Hata(4);
	}
	else throw Hata(2);
}
public:T ilki() {
	if (bosMu()) throw Hata(2);
	return ilk->bilgi;
	   }
public:T son() {
	if(bosMu())throw Hata(2);
	Dugum<T> *son = ilk;
	while (son->sonraki != NULL) son = son->sonraki;
	return son->bilgi;
}
public:bool bosMu() {
	return !(ilk);
}
public:T deneme(){
	Dugum<T> *ornek = ilk->sonraki->sonraki;
	return ornek->bilgi;
}
public:void Sil()
{
	if (bosMu())throw Hata(2);
	if (Uzunluk() == 1)
	{
		delete ilk;
		ilk = NULL;
	}
	else
	{
		Dugum<T> *son = ilk;
		while (son->sonraki->sonraki != NULL) son = son->sonraki;
		delete son->sonraki;
		son->sonraki = NULL;

	}
}
public:void indisdekiniSil(int indis)
{
	if (indis < 0 || indis >= Uzunluk()) throw Hata(3);
	if (indis == Uzunluk() - 1) Sil();
	else if (indis == 0)
	{
		Dugum<T> *silinecek = ilk;
		ilk = ilk->sonraki;
		delete silinecek;
	}
	else
	{
		Dugum<T> *silinecek;
		Dugum<T> *onceki = ilk;
		int ie = 1;
		while (ie != indis) {
			onceki = onceki->sonraki;
			ie++;
		}
		silinecek = onceki->sonraki;
		onceki->sonraki = onceki->sonraki->sonraki;
		delete silinecek;
	}
}
public:void degerileSil(T eleman)
   {
	indisdekiniSil(Bul(eleman));
   }
};
