#pragma once
#include <iostream>
using namespace std;
template<class T>
class Node
{
private:
	int color;
	T elemento;
	Node<T>* izquierdo;
	Node<T>* derecho;
public:
	Node(T elemento);
	Node();
	~Node();
	void setColor(int color);
	void setElemento(T elemento);
	void setIzquierdo(Node* izquierdo);
	void setDerecho(Node* derecho);
	Node<T>*& getIzquierdo();
	Node<T>*& getDerecho();
	T getElemento();
	int getColor();
};

template<class T>
inline Node<T>::Node(T elemento)
{
	this->elemento = elemento;
	izquierdo = NULL;
	derecho = NULL;
	color = NULL;
}
template<class T>
inline Node<T>::Node()
{
	elemento = NULL;
	izquierdo = NULL;
	derecho = NULL;
	color = NULL;
}

template<class T>
inline Node<T>::~Node()
{
}

template<class T>
inline void Node<T>::setColor(int color)
{
	this->color = color;
}

template<class T>
inline void Node<T>::setElemento(T elemento)
{
	this->elemento = elemento;
}

template<class T>
inline void Node<T>::setIzquierdo(Node* izquierdo)
{
	this->izquierdo = izquierdo;
}

template<class T>
inline void Node<T>::setDerecho(Node* derecho)
{
	this->derecho = derecho;
}

template<class T>
inline Node<T>*& Node<T>::getIzquierdo()
{
	return izquierdo;
}

template<class T>
inline Node<T>*& Node<T>::getDerecho()
{
	return derecho;
}

template<class T>
inline T Node<T>::getElemento()
{
	return elemento;
}

template<class T>
inline int Node<T>::getColor()
{
	return color;
}
