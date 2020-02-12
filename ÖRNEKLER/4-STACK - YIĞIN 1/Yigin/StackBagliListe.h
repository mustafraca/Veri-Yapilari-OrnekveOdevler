#ifndef STACKBL_H
#define STACKBL_H
#include "Dugum.h"
#include "Hata.h"
template<typename T>

class StackBL
{
private:
	Node<T> *ilk;
public:
	StackBL()
	{
		ilk = NULL;
	}
	bool EMPTY() { return ilk == NULL; }
	T TOP()
	{
		if (EMPTY()) throw(2);
		return ilk->data;
	}
	void PUSH(T eleman)
	{
		Node<T> *node = new Node<T>(eleman);
		node->next = ilk;
		ilk = node;
	}
	T POP()
	{
		if (EMPTY()) throw Hata(2);
		Node<T> *silinecek = ilk;
		T data = ilk->data;
		ilk = ilk->next;
		delete silinecek;
		return data;
	}
};

#endif // !STACKBL_H

