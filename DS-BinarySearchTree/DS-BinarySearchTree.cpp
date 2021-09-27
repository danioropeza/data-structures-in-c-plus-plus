#include <iostream>
#include "BinarySearchTree.h"
#include "BinarySearchTree.cpp"

int main()
{
    BinarySearchTree<int>* example = new BinarySearchTree<int>();
    example->Insert(5);
    example->Insert(10);
    example->Insert(11);
    example->Insert(3);
    example->Insert(4);
    example->Insert(7);
    example->Insert(1);
    example->Insert(12);
    example->Insert(6);
    example->Insert(0);
    //example->ShowPostOrder();
    example->Search(11)->ShowElement();
    cout << endl;
    example->FindMinor()->ShowElement();
    cout << endl;
    cout << "Count: " << example->Count() << endl;
    cout << "Height: " << example->GetHeight() << endl;
    example->ShowAllElementsLessThan(5);
}