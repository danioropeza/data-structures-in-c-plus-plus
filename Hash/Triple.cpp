#include "Triple.h"

template<typename T>
Triple<T>::Triple() {
	next_ = NULL;
	previous_ = NULL;
	element_ = "";
}
template<typename T>
Triple<T>::Triple(T new_element) {
	next_ = NULL;
	previous_ = NULL;
	element_ = new_element;
}
template<typename T>
Triple<T>* Triple<T>::next() {
	return next_;
}
template<typename T>
void Triple<T>::set_next(Triple* new_next) {
	next_ = new_next;
}
template<typename T>
Triple<T>* Triple<T>::previous() {
	return previous_;
}
template<typename T>
void Triple<T>::set_previous(Triple* new_previous) {
	previous_ = new_previous;
}
template<typename T>
T Triple<T>::element() {
	return element_;
}
template<typename T>
void Triple<T>::set_element(T new_element) {
	element_ = new_element;
}
template<typename T>
void Triple<T>::Show() {
	cout << element_;
}
