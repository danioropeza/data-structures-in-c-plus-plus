#pragma once
#include "Node.h"
#include "Node.cpp"

template<typename T,int TAM>
class Heap
{
private:
	Node<T>* heap_[TAM];
	int last_leaf_;
	void RecoverUpDown(int);
	void RecoverDownUp(int);
public:
	Heap();
	void Insert(T);
	T DeleteFirst();
	void Show();
};

