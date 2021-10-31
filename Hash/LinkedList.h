#pragma once
#include "Triple.h"
#include "Triple.cpp"

template<typename T>
class LinkedList
{
private:
	Triple<T>* first_;
	Triple<T>* last_;
	Triple<T>* SearchRecursiveImpl(T, Triple<T>*);
public:
	LinkedList();
	Triple<T>* first();
	Triple<T>* last();
	void AddFront(T);
	void DeleteFront();
	void AddBack(T);
	void DeleteBack();
	void Delete(T);
	Triple<T>* Search(T);
	Triple<T>* SearchRecursive(T);
	Triple<T>* SearchTheMinor();
	Triple<T>* Nth(int);
	void Show();
};