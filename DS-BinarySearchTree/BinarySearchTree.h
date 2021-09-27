#pragma once
#include "Node.h"
#include "Node.cpp"

template <typename T>
class BinarySearchTree
{
private:
	Node<T>* root_;
	void InsertImpl(Node<T>*&, T);
	Node<T>*& SearchImpl(Node<T>*&, T);
	Node<T>*& FindMinorImpl(Node<T>*&);
	Node<T>*& FindMayorImpl(Node<T>*&);
	void ShowAllElementsLessThanImpl(Node<T>*&, T);
	int CountImpl(Node<T>*&);
	int GetHeightImpl(Node<T>*&);
	void ShowInOrderImpl(Node<T>*);
	void ShowPreOrderImpl(Node<T>*);
	void ShowPostOrderImpl(Node<T>*);
public:
	BinarySearchTree();
	void Insert(T);
	Node<T>*& Search(T);
	Node<T>*& FindMinor();
	Node<T>*& FindMayor();
	void ShowAllElementsLessThan(T);
	int Count();
	int GetHeight();
	void ShowInOrder();
	void ShowPreOrder();
	void ShowPostOrder();
};

