#pragma once
#include <iostream>
#include <string>;
using namespace std;

template<typename T>
class Node
{
private:
	Node* left_;
	Node* right_;
	T element_;
public:
	Node();
	Node(T);
	Node*& left();
	void set_left(Node*);
	Node*& right();
	void set_right(Node*);
	T element();
	void set_element(T);
	void ShowElement();
};
