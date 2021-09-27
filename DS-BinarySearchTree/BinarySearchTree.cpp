#include "BinarySearchTree.h"

template<typename T>
BinarySearchTree<T>::BinarySearchTree() {
	root_ = NULL;
}
template<typename T>
void BinarySearchTree<T>::Insert(T element) {
	InsertImpl(root_, element);
}
template<typename T>
void BinarySearchTree<T>::InsertImpl(Node<T>*& root_iterator, T element) {
	if (root_iterator == NULL)
	{
		root_iterator = new Node<T>(element);
	}
	else
	{
		if (element < root_iterator->element())
		{
			InsertImpl(root_iterator->left(), element);
		}
		if (element > root_iterator->element())
		{
			InsertImpl(root_iterator->right(), element);
		}
	}
}
template<typename T>
Node<T>*& BinarySearchTree<T>::Search(T element) {
	return SearchImpl(root_, element);
}
template<typename T>
Node<T>*& BinarySearchTree<T>::SearchImpl(Node<T>*& root_iterator, T element) {
	if (root_iterator == NULL)
	{
		return root_iterator;
	}
	else
	{
		if (element < root_iterator->element())
		{
			return SearchImpl(root_iterator->left(), element);
		}
		if (element > root_iterator->element())
		{
			return SearchImpl(root_iterator->right(), element);
		}
		if (element == root_iterator->element())
		{
			return root_iterator;
		}
	}
}
template<typename T>
Node<T>*& BinarySearchTree<T>::FindMinor() {
	return FindMinorImpl(root_);
}
template<typename T>
Node<T>*& BinarySearchTree<T>::FindMinorImpl(Node<T>*& root_iterator) {
	if (root_iterator == NULL) {
		return root_iterator;
	}
	
	if (root_iterator->left() == NULL) {
		return root_iterator;
	}
	return FindMinorImpl(root_iterator->left());
}
template<typename T>
Node<T>*& BinarySearchTree<T>::FindMayor() {
	return FindMayorImpl(root_);
}
template<typename T>
Node<T>*& BinarySearchTree<T>::FindMayorImpl(Node<T>*& root_iterator) {
	if (root_iterator == NULL) {
		return root_iterator;
	}

	if (root_iterator->right() == NULL) {
		return root_iterator;
	}
	return FindMayorImpl(root_iterator->right());
}
template<typename T>
void BinarySearchTree<T>::ShowAllElementsLessThan(T element) {
	return ShowAllElementsLessThanImpl(root_, element);
}
template<typename T>
void BinarySearchTree<T>::ShowAllElementsLessThanImpl(Node<T>*& root_iterator, T element) {
	Node<T>*& element_found = SearchImpl(root_, element);
	Node<T>*& element_found_left_side = element_found->left();
	if (element_found_left_side != NULL) 
	{
		ShowInOrderImpl(element_found_left_side);
	}
}
template<typename T>
int BinarySearchTree<T>::Count() {
	return CountImpl(root_);
}
template<typename T>
int BinarySearchTree<T>::CountImpl(Node<T>*& root_iterator) {
	int result;
	if (root_iterator == NULL)
	{
		result = 0;
	}
	else
	{
		int left_count = CountImpl(root_iterator->left());
		int right_count = CountImpl(root_iterator->right());
		result = left_count + right_count + 1;
	}
	return result;
}
template<typename T>
int BinarySearchTree<T>::GetHeight() {
	return GetHeightImpl(root_);
}
template<typename T>
int BinarySearchTree<T>::GetHeightImpl(Node<T>*& root_iterator) {
	int result;
	if (root_iterator == NULL)
	{
		result = 0;
	}
	else
	{
		int left_height = GetHeightImpl(root_iterator->left());
		int right_height = GetHeightImpl(root_iterator->right());
		if (left_height > right_height)
		{
			return left_height + 1;
		}
		return right_height + 1;
	}
	return result;
}
template<typename T>
void BinarySearchTree<T>::ShowInOrder() {
	ShowInOrderImpl(root_);
}
template<typename T>
void BinarySearchTree<T>::ShowInOrderImpl(Node<T>* root_iterator) {
	if (root_iterator == NULL)
	{
		return;
	}
	else
	{
		ShowInOrderImpl(root_iterator->left());
		cout << root_iterator->element() << endl;
		ShowInOrderImpl(root_iterator->right());
	}
}
template<typename T>
void BinarySearchTree<T>::ShowPreOrder() {
	ShowPreOrderImpl(root_);
}
template<typename T>
void BinarySearchTree<T>::ShowPreOrderImpl(Node<T>* root_iterator) {
	if (root_iterator == NULL)
	{
		return;
	}
	else
	{
		cout << root_iterator->element() << endl;
		ShowPreOrderImpl(root_iterator->left());
		ShowPreOrderImpl(root_iterator->right());
	}
}
template<typename T>
void BinarySearchTree<T>::ShowPostOrder() {
	ShowPostOrderImpl(root_);
}
template<typename T>
void BinarySearchTree<T>::ShowPostOrderImpl(Node<T>* root_iterator) {
	if (root_iterator == NULL)
	{
		return;
	}
	else
	{
		ShowPostOrderImpl(root_iterator->left());
		ShowPostOrderImpl(root_iterator->right());
		cout << root_iterator->element() << endl;
	}
}
