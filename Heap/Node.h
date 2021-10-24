#pragma once
#include <iostream>
#include <string>;
using namespace std;

template<typename T>
class Node
{
private:
	bool exist_;
	T element_;
public:
	Node(T);
	bool exist();
	void set_exist(bool);
	T element();
	void set_element(T);
	void Show();
};

