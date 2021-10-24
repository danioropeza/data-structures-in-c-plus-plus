#include "Node.h"

template<typename T>
Node<T>::Node(T element) {
	element_ = element;
	exist_ = true;
}
template<typename T>
bool Node<T>::exist() {
	return exist_;
}
template<typename T>
void Node<T>::set_exist(bool newExist) {
	exist_ = newExist;
}
template<typename T>
T Node<T>::element() {
	return element_;
}
template<typename T>
void Node<T>::set_element(T newElement) {
	element_ = newElement;
}
template<typename T>
void Node<T>::Show() {
	cout << element_ << " ";
}
