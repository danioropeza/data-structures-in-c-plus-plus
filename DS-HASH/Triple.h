#pragma once
#include <iostream>
#include <string>;
using namespace std;

template<typename T>
class Triple
{
private:
	Triple* next_;
	Triple* previous_;
	T element_;
public:
	Triple();
	Triple(T);
	Triple* next();
	void set_next(Triple*);
	Triple* previous();
	void set_previous(Triple*);
	T element();
	void set_element(T);
	void Show();
};
