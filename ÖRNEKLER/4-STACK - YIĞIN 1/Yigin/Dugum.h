#ifndef DUGUM_H
#define DUGUM_H
template<typename T>
class Node
{
public:
	T data;
	Node<T> *next;
	Node(T eleman)
	{
		data = eleman;
		next = NULL;
	}
};


#endif // !DUGUM_H
