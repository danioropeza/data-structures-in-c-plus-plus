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
	int factor_;
	T element_;
public:
	Node();
	Node(T);
	Node*& left();
	void set_left(Node*);
	Node*& right();
	void set_right(Node*);
	int factor();
	void set_factor(int);
	T element();
	void set_element(T);
	void ShowElement();
};

