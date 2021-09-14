#pragma once
#include "Value.h"
#include "Value.cpp"

template<typename T, int TAM>
class ArrayBinaryTree
{
private:
	Value<int>*  array_[TAM];
public:
	ArrayBinaryTree();
	bool Insert(T, T, int);
	int Count(int);
	int CalculateHeight(int);
	void ShowInOrder(int);
	void ShowPreOrder(int);
	void ShowPostOrder(int);
};

