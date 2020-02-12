#ifndef STACK_H
#define STACK_H
#include"Hata.h"
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
	bool EMPTY() { return yer == -1; }
	bool FULL() { return (yer + 1 == kapasite); }
	N TOP() { 
		if (EMPTY()) throw Hata(2);
		return stack[yer];}
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

#endif // !STACK_H

