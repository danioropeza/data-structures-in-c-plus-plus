#pragma once
#include "LinkedList.h"
#include "LinkedList.cpp"
#include <algorithm>

template<typename T, int TAM>
class Hash
{
private:
	LinkedList<T>* hash[TAM] = { NULL };
	int GetHashValue(T);
public:
	Hash();
	void Insert(T);
	void Delete(T);
	Triple<T>* Search(T);
	void Show();
};

