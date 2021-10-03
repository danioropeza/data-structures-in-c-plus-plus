#include <iostream>
#include "BinarySearchTree.h"
#include "BinarySearchTree.cpp"

int main()
{
    BinarySearchTree<int>* example = new BinarySearchTree<int>();
    example->Insert(10);
    example->Insert(7);
    example->Insert(15);
    example->Insert(20);
    example->Insert(3);
    example->Insert(8);
    example->Insert(5);
    example->Show2D();
    bool result = example->Delete(10);
    if (result) {
        cout << "Elimino" << endl << endl << endl;
    } else {
        cout << "No elimino" << endl << endl << endl;
    }
    example->Show2D();



    example->Delete(3);

    //example->ShowPostOrder();
    //example->Search(11)->ShowElement();
    //cout << endl;
    //example->FindMinor()->ShowElement();
    //cout << endl;
    //cout << "Count: " << example->Count() << endl;
    //cout << "Height: " << example->GetHeight() << endl;
    //example->ShowAllElementsLessThan(5);
}