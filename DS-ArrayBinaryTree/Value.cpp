#include "Value.h"

template<typename T>
Value<T>::Value() {
	element_ = -1;
	exist_ = false;
}
template<typename T>
T Value<T>::element() {
	return element_;
}
template<typename T>
void Value<T>::set_element(T newElement) {
	element_ = newElement;
}
template<typename T>
bool Value<T>::exist() {
	return exist_;
}
template<typename T>
void Value<T>::set_exist(bool newExist) {
	exist_ = newExist;
}
template<typename T>
void Value<T>::show() {
	cout << element_ << " ";
}