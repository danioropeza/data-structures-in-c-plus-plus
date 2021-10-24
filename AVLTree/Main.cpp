#include "AVLTree.h"
#include "AVLTree.cpp"

int main()
{
    AVLTree<int>* example = new AVLTree<int>();
    example->ReadAndInsert();
    example->Show2D();
    //example->ExampleDeleteLater();
    //example->Show2D();
}