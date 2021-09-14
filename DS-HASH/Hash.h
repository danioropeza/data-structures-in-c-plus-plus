#pragma once
#include "List8.h"
#include "List8.cpp"
#include <algorithm>

template<typename T, int TAM>
class Hash
{
private:
	List8<T>* hash[TAM] = { NULL };
	int GetHashValue(T);
public:
	Hash();
	void Insert(T);
	void Delete(T);
	Triple<T>* Search(T);
	void Show();
};

