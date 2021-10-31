#include "Node.h"

template<typename T>
Node<T>::Node() {
	left_ = NULL;
	right_ = NULL;
	element_ = "";
}
template<typename T>
Node<T>::Node(T new_element) {
	left_ = NULL;
	right_ = NULL;
	element_ = new_element;
}
template<typename T>
Node<T>*& Node<T>::left() {
	return left_;
}
template<typename T>
void Node<T>::set_left(Node* new_left) {
	left_ = new_left;
}
template<typename T>
Node<T>*& Node<T>::right() {
	return right_;
}
template<typename T>
void Node<T>::set_right(Node* new_right) {
	right_ = new_right;
}
template<typename T>
T Node<T>::element() {
	return element_;
}
template<typename T>
void Node<T>::set_element(T new_element) {
	element_ = new_element;
}
template<typename T>
void Node<T>::ShowElement() {
	cout << element_;
}
