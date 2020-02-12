#ifndef STACH_H //K�T�PHANEN�N TEKRARLI �A�IRILMASINI ENGELLER. 1 KERE �A�IRILMASI DURUMUNDA TEKRARDAN �A�IRILMAZ. SON �A�IRILAN KULLANILIR.
#define STACK_H
#include "Hata.h"
template<typename N>
class Stack 
{
private: 
	int kapasite;
	int yer;
	N *stack;
public:
	Stack()
	{
		kapasite = 4;
		yer = -1;
		stack = new N[kapasite];
	}
	Stack(int kapasite)
	{
		this->kapasite = kapasite;
		yer = -1;
		stack = new N[kapasite];
	}
	bool EMPTY() { return yer == -1 };
	bool FULL() { return (yer + 1 == kapasite) }
	N TOP() { return stack[yer] }
	void PUSH(N eleman)
	{
		if (FULL()) throw Hata(1);
		stack[++yer] = eleman;
	}
	N POP()
	{
		if (EMPTY()) throw Hata(2);
		N eleman = stack[yer--];
		return eleman;
	}
};

#endif // !STACH_H
