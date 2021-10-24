#pragma once
#include <iomanip>
#include <fstream>
#include <Windows.h>
#include "Node.h"
template<class T>
class RedBlackTree
{
private:
	Node<T>* raiz;
	void procedimientoInsertar(T elemento, Node<T>*& iterador, bool& continuar, string& paridad, string& lado);
	void procedimientoMostrarOG(Node<T>*& iterador/*, int cont*/);
	void procedimientoMostrar(int cont, Node<T>*& iterador);
	void procedimientoSiguienteAbb(T elemento, Node<T>*& iterador, int& siguente, bool& resp, bool& Resp_Sig);
	Node<T>* procedimientoMenor(Node<T>*& iterador);
	Node<T>* procedimientoMayor(Node<T>*& iterador);
	bool procedimientoEliminar(Node<T>*& iterador, T elementoEliminar);
	bool procedimientoBuscar(Node<T>* iterador, T elementoBuscar);
	int procedimientoNodos(Node<T>*& iterador);
	int procedimientoAltura(Node<T>* iterador);
	void procedimientoMostrarMenoresElemento(Node<T>* iterador, T elemento);
	void procedimientoMostrarNivel(Node<T>* iterador, int nivel);
	void procedimientoRecorrerOrderN(Node<T>* iterador);
	void procedimientoRecorrerPostOrder(Node<T>* iterador);
	void procedimientoRecorrerPreOrder(Node<T>* iterador);
	void rotarIzquierda(Node<T>*& nodo);
	void rotarDerecha(Node<T>*& nodo);

public:
	RedBlackTree();
	~RedBlackTree();
	void mostrar();
	void mostrarOG();
	void insertar(T elemento);
	void siguenteAbb(T Elemento);
	bool eliminar(T elementoEliminar);
	bool buscar(T elementoBuscar);
	int nodos();
	int altura();
	void mostrarMenoresElemento(T elemento);
	void mostrarNivel(int nivel);
	void recorrerOrderN();
	void recorrerPostOrder();
	void recorrerPreOrder();
	void insertarArchivo();
	Node<T>* menor();
	Node<T>* mayor();
};

template<class T>
inline RedBlackTree<T>::RedBlackTree()
{
	raiz = NULL;
}

template<class T>
inline RedBlackTree<T>::~RedBlackTree()
{
}

template<class T>
inline void RedBlackTree<T>::mostrar()
{
	int cont = 0;
	procedimientoMostrar(cont,raiz);
}

template<class T>
inline void RedBlackTree<T>::insertar(T elemento)
{
	bool continuar;
	string paridad;
	string lado;
	procedimientoInsertar(elemento, raiz, continuar, paridad, lado);
}

template<class T>
inline void RedBlackTree<T>::siguenteAbb(T elemento)
{
	bool resp_siguente = false;
	bool resp = false;
	int siguente;
	procedimientoSiguienteAbb(elemento, raiz, siguente, resp, resp_siguente);
	cout << "Siguente:" << siguente << ",Elemento:" << elemento << endl;
}

template<class T>
inline bool RedBlackTree<T>::eliminar(T elementoEliminar)
{
	return procedimientoEliminar(raiz, elementoEliminar);
}

template<class T>
inline bool RedBlackTree<T>::buscar(T elementoBuscar)
{
	return procedimientoBuscar(raiz, elementoBuscar);
}

template<class T>
inline int RedBlackTree<T>::nodos()
{
	return procedimientoNodos(raiz);
}

template<class T>
inline int RedBlackTree<T>::altura()
{
	return procedimientoAltura(raiz);
}

template<class T>
inline void RedBlackTree<T>::mostrarMenoresElemento(T elemento)
{
	procedimientoMostrarMenoresElemento(raiz, elemento);
}

template<class T>
inline void RedBlackTree<T>::mostrarNivel(int nivel)
{
	procedimientoMostrarNivel(raiz, nivel);
}

template<class T>
inline void RedBlackTree<T>::recorrerOrderN()
{
	procedimientoRecorrerOrderN(raiz);
}

template<class T>
inline void RedBlackTree<T>::recorrerPostOrder()
{
	procedimientoRecorrerPostOrder(raiz);
}

template<class T>
inline void RedBlackTree<T>::recorrerPreOrder()
{
	procedimientoRecorrerPreOrder(raiz);
}

template<class T>
inline Node<T>* RedBlackTree<T>::menor()
{
	return procedimientoMenor(raiz);
}

template<class T>
inline Node<T>* RedBlackTree<T>::mayor()
{
	return procedimientoMayor(raiz);
}

template<class T>
inline void RedBlackTree<T>::procedimientoInsertar(T elemento, Node<T>*& iterador, bool& continuar, string& paridad, string& lado)
{
	if (iterador == NULL)
	{
		iterador = new Node<T>();
		iterador->setElemento(elemento);
		iterador->setColor(4);
		continuar = true;
		paridad = "par";
	}
	else
	{
		if (elemento < iterador->getElemento())
		{
			procedimientoInsertar(elemento, iterador->getIzquierdo(), continuar, paridad, lado);
			if (continuar == true)
			{
				if (paridad == "par")
				{
					if (iterador->getColor() == 7)
					{
						continuar = false;
					}
					else
					{
						paridad = "impar";
						lado = "izquierdo";
					}
				}
				else
				{
					if (paridad == "impar")
					{
						if (iterador->getDerecho() != NULL && iterador->getDerecho()->getColor() == 4)
						{
							iterador->getIzquierdo()->setColor(7);
							iterador->getDerecho()->setColor(7);
							iterador->setColor(4);
							paridad = "par";
						}
						else
						{
							continuar = false;
							if (lado == "derecho")
							{
								rotarIzquierda(iterador->getIzquierdo());
							}
							iterador->getIzquierdo()->setColor(7);
							iterador->setColor(4);
							rotarDerecha(iterador);
						}
					}
				}

			}

		}
		if (elemento > iterador->getElemento())
		{
			procedimientoInsertar(elemento, iterador->getDerecho(), continuar, paridad, lado);
			if (continuar == true)
			{
				if (paridad == "par")
				{
					if (iterador->getColor() == 7)
					{
						continuar = false;
					}
					else
					{
						paridad = "impar";
						lado = "derecho";
					}
				}
				else
				{
					if (paridad == "impar")
					{
						if (iterador->getIzquierdo() != NULL && iterador->getIzquierdo()->getColor() == 4)
						{
							iterador->getIzquierdo()->setColor(7);
							iterador->getDerecho()->setColor(7);
							iterador->setColor(4);
							paridad = "par";
						}
						else
						{
							continuar = false;
							if (lado == "izquierdo")
							{
								rotarDerecha(iterador->getDerecho());
							}
							iterador->getDerecho()->setColor(7);
							iterador->setColor(4);
							rotarIzquierda(iterador);
						}
					}
				}
			}
		}
				
	}
}

template<class T>
inline void RedBlackTree<T>::procedimientoMostrarOG(Node<T>*& iterador/*, int cont*/)

{
	if (iterador != NULL)
	{
		procedimientoMostrarOG(iterador->getIzquierdo());
		cout << " " << iterador->getElemento() << "," << iterador->getColor() << endl;
		procedimientoMostrarOG(iterador->getDerecho());
	}
	/*
	if (iterador != NULL)
	{
		if (iterador->getIzquierdo() != NULL)
		{
			procedimientoMostrarOG(iterador->getIzquierdo(), cont + 4);
		}
		if (iterador->getDerecho() != NULL)
		{
			procedimientoMostrarOG(iterador->getDerecho(), cont + 4);
		}
		if (cont)
		{
			std::cout << std::setw(cont) << " ";
		}
		
	}
	cout << iterador->getElemento() << endl;
	*/
}

template<class T>
inline void RedBlackTree<T>::procedimientoMostrar(int cont, Node<T>*& iterador)
{
	
	if (iterador != NULL)
	{
		procedimientoMostrar(cont + 1, iterador->getDerecho());
		for (int i = 0; i < cont; i++)
		{
			cout << "   ";
		}
		//cout << iterador->getElemento()<<endl;
		if (iterador->getColor() == 4)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
			cout << iterador->getElemento() << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			
		}
		else
		{
			cout << iterador->getElemento() << endl;
		}
		procedimientoMostrar(cont + 1, iterador->getIzquierdo());
	}
}

template<class T>
inline void RedBlackTree<T>::procedimientoSiguienteAbb(T elemento, Node<T>*& iterador, int& siguente, bool& resp, bool& Resp_Sig)
{
	if (iterador == NULL)
	{
		resp = false;
	}
	else
	{
		if (elemento == iterador->getElemento())
		{
			resp = true;
			if (iterador->getDerecho() == NULL)
			{
				Resp_Sig = false;
			}
			else
			{
				siguente = procedimientoMenor(iterador->getDerecho())->getElemento();
				Resp_Sig = true;
			}

		}
		if (elemento > iterador->getElemento())
		{
			procedimientoSiguienteAbb(elemento, iterador->getDerecho(), siguente, resp, Resp_Sig);
		}
		if (elemento < iterador->getElemento())
		{
			procedimientoSiguienteAbb(elemento, iterador->getIzquierdo(), siguente, resp, Resp_Sig);
			if (resp == true && Resp_Sig == false)
			{
				Resp_Sig = true;
				siguente = iterador->getElemento();
			}
		}

	}
}

template<class T>
inline Node<T>* RedBlackTree<T>::procedimientoMenor(Node<T>*& iterador)
{
	if (iterador != NULL)
	{
		if (iterador->getIzquierdo() == NULL)
		{
			return iterador;
		}
	}
	return procedimientoMenor(iterador->getIzquierdo());
}

template<class T>
inline Node<T>* RedBlackTree<T>::procedimientoMayor(Node<T>*& iterador)
{
	if (iterador != NULL)
	{
		if (iterador->getDerecho() == NULL)
		{
			return iterador;
		}
	}
	return procedimientoMayor(iterador->getDerecho());
}

template<class T>
inline bool RedBlackTree<T>::procedimientoEliminar(Node<T>*& iterador, T elementoEliminar)
{
	srand(time(NULL));
	bool resp = false;
	if (iterador == NULL)
		return resp;
	else
	{
		if (elementoEliminar < iterador->getElemento())
			procedimientoEliminar(iterador->getIzquierdo(), elementoEliminar);

		if (elementoEliminar > iterador->getElemento())
			procedimientoEliminar(iterador->getDerecho(), elementoEliminar);

		if (iterador->getElemento() == elementoEliminar)
		{
			if (iterador->getIzquierdo() == NULL && iterador->getDerecho() == NULL)
			{
				iterador = NULL;
				delete(iterador);

			}
			else
			{
				if (iterador->getIzquierdo() != NULL || iterador->getDerecho() != NULL)
				{
					int aux;
					int num = 0;
					num = rand() % 2;
					if (num == 0 && iterador->getIzquierdo() != NULL)
						aux = 0;
					else
						aux = 1;

					if (num == 0 && iterador->getDerecho() != NULL)
						aux = 1;
					else
						aux = 0;

					if (aux == 0)
					{
						int mayor = procedimientoMayor(iterador->getIzquierdo())->getElemento();
						iterador->setElemento(mayor);
						resp = procedimientoEliminar(iterador->getIzquierdo(), mayor);
					}
					if (aux == 1)
					{
						int menor = procedimientoMenor(iterador->getDerecho())->getElemento();
						iterador->setElemento(menor);
						resp = procedimientoEliminar(iterador->getDerecho(), menor);
					}
				}
			}
		}

	}

	return resp;
}

template<class T>
inline bool RedBlackTree<T>::procedimientoBuscar(Node<T>* iterador, T elementoBuscar)
{
	if (iterador == NULL)
	{
		return false;
	}
	else if (iterador->getElemento() == elementoBuscar)
	{
		return true;
	}
	else if (elementoBuscar < iterador->getElemento())
	{
		return procedimientoBuscar(iterador->getIzquierdo(), elementoBuscar);
	}
	else
	{
		return procedimientoBuscar(iterador->getDerecho(), elementoBuscar);
	}
}

template<class T>
inline int RedBlackTree<T>::procedimientoNodos(Node<T>*& iterador)
{
	int res = 0;
	int r1;
	int r2;
	if (iterador != NULL)
	{
		r1 = procedimientoNodos(iterador->getIzquierdo());
		r2 = procedimientoNodos(iterador->getDerecho());
		res = r1 + r2 + 1;
	}
	return res;
}

template<class T>
inline int RedBlackTree<T>::procedimientoAltura(Node<T>* iterador)
{

	int res = 0;
	int a1, a2 = 0;
	if (iterador != NULL)
	{
		a1 = procedimientoAltura(iterador->getIzquierdo());
		a2 = procedimientoAltura(iterador->getDerecho());
		if (a1 > a2)
		{
			res = a1 + 1;
		}
		else
		{
			res = a2 + 1;
		}
	}
	return res;
}

template<class T>
inline void RedBlackTree<T>::procedimientoMostrarMenoresElemento(Node<T>* iterador, T elemento)
{
	if (iterador != NULL)
	{
		if (iterador->getElemento() < elemento)
		{
			cout << iterador->getElemento() << endl;
		}
		procedimientoMostrarMenoresElemento(iterador->getIzquierdo(), elemento);
		procedimientoMostrarMenoresElemento(iterador->getDerecho(), elemento);
	}
}

template<class T>
inline void RedBlackTree<T>::procedimientoMostrarNivel(Node<T>* iterador, int nivel)
{
	if (iterador != NULL)
	{
		if (nivel == 1)
		{
			cout << iterador->getElemento() << endl;
		}
		nivel--;
		procedimientoMostrarNivel(iterador->getIzquierdo(), nivel);
		procedimientoMostrarNivel(iterador->getDerecho(), nivel);
	}
}

template<class T>
inline void RedBlackTree<T>::procedimientoRecorrerOrderN(Node<T>* iterador)
{
	if (iterador != NULL)
	{
		procedimientoRecorrerOrderN(iterador->getIzquierdo());
		procedimientoRecorrerOrderN(iterador->getDerecho());
		cout << iterador->getElemento();
	}
}

template<class T>
inline void RedBlackTree<T>::procedimientoRecorrerPostOrder(Node<T>* iterador)
{
	if (iterador != NULL)
	{
		procedimientoRecorrerOrderN(iterador->getIzquierdo());
		cout << iterador->getElemento();
		procedimientoRecorrerOrderN(iterador->getDerecho());
	}
}

template<class T>
inline void RedBlackTree<T>::procedimientoRecorrerPreOrder(Node<T>* iterador)
{
	if (iterador != NULL)
	{
		cout << iterador->getElemento();
		procedimientoRecorrerOrderN(iterador->getIzquierdo());
		procedimientoRecorrerOrderN(iterador->getDerecho());

	}
}

template<class T>
inline void RedBlackTree<T>::insertarArchivo()
{
	ifstream Lista;
	int numero;
	Lista.open("ListaNumeros.txt");
	do
	{
		Lista >> numero;
		insertar(numero);
	} while (!Lista.eof());
	Lista.close();
}

template<class T>
inline void RedBlackTree<T>::rotarIzquierda(Node<T>*& nodo)
{
	Node<T>* nuevaRaiz=nodo->getDerecho();
	Node<T>* flotante= nuevaRaiz->getIzquierdo();;
	if (nuevaRaiz->getIzquierdo() == NULL)
	{
		flotante = NULL;
	}
	nuevaRaiz->setIzquierdo(nodo);
	nodo->setDerecho(flotante);
	nodo = nuevaRaiz;
}

template<class T>
inline void RedBlackTree<T>::rotarDerecha(Node<T>*& nodo)
{
	Node<T>* nuevaRaiz = nodo->getIzquierdo();
	Node<T>* flotante = nuevaRaiz->getDerecho();;
	if (nuevaRaiz->getDerecho() == NULL)
	{
		flotante = NULL;
	}
	nuevaRaiz->setDerecho(nodo);
	nodo->setIzquierdo(flotante);
	nodo = nuevaRaiz;
}
