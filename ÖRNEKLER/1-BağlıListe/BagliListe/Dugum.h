#pragma once
template<typename T>
class Dugum
{
public:T bilgi;
public:Dugum *sonraki;
public:Dugum(T eleman)
{
	bilgi = eleman;
	sonraki = NULL;
}
};
