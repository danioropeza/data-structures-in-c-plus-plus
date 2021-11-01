#pragma once
#include <iostream>
#include <string>;
using namespace std;

template<typename T>
class Value
{
private:
	T element_;
	bool exist_;
public:
	Value();
	T element();
	void set_element(T);
	bool exist();
	void set_exist(bool);
	void show();
};

