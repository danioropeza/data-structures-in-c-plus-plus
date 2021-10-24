// ArbolRojoNegro.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "RedBlackTree.h"
using namespace std;

void tarea()
{
    RedBlackTree<int> numeros;
    //1.-Insertar
    numeros.insertar(33);
    numeros.insertar(15);
    numeros.insertar(8);
    numeros.insertar(12);
    numeros.insertar(9);
    numeros.insertar(5);
    numeros.insertar(3);
    numeros.insertar(2);
    numeros.insertar(37);
    //2.-MostrarArbol
    numeros.mostrar();
    //3.-RecorrerOrden
    numeros.recorrerOrderN();
    cout << endl;
    numeros.recorrerPostOrder();
    cout << endl;
    numeros.recorrerPreOrder();
    cout << endl;
    //4.-Buscar
    if (numeros.buscar(15) != 1)
    {

        cout << "No existe" << endl;
    }
    else
    {
        cout << "Lo encontro" << endl;
    }
    //5.-Menor
    cout << "Menor:" << numeros.menor()->getElemento() << endl;
    //6.-Contar nodos
    cout << "Nodos:" << numeros.nodos() << endl;
    //7.-Altura
    cout << "Altura:" << numeros.altura() << endl;
    //8.-Mayor
    cout << "Mayor:" << numeros.mayor()->getElemento() << endl;
    //9.- Mostrar todos los menores a un Elemento
    cout << "Menores a 3:" << endl;
    numeros.mostrarMenoresElemento(5);
    //10.- Mostrar Nivel
    cout << "Nivel 1:";
    numeros.mostrarNivel(2);

}
void insertarArchivo()
{
    RedBlackTree<int> numeros;
    numeros.insertarArchivo();
    numeros.mostrar();
}
int main()
{
    tarea();
    //insertarArchivo();
}
