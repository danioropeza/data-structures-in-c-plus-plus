#pragma once
#include <fstream>
#include "Node.h"
#include "Node.cpp"
#define SPACES 10

template<typename T>
class AVLTree
{
private:
	Node<T>* root_;
	void InsertImpl(Node<T>*&, T, bool&);
	int CountImpl(Node<T>*&);
	void Show2DImpl(Node<T>*);
	void Show2DUtil(Node<T>*, int);
	void RotateLeft(Node<T>*&);
	void RotateRight(Node<T>*&);
	void RotateLeftComposed(Node<T>*&);
	void RotateRightComposed(Node<T>*&);
public:
	AVLTree();
	void ExampleDeleteLater();
	void Insert(T);
	int Count();
	void Show2D();
	void ReadAndInsert();
};

