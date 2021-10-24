#include <iostream>
#include "ArrayBinaryTree.h"
#include "ArrayBinaryTree.cpp"

int main()
{
    ArrayBinaryTree<int, 100> binaryTree;
    binaryTree.Insert(1, 1, 1);
    binaryTree.Insert(2, 1, 1);
    binaryTree.Insert(3, 1, 1);
    binaryTree.Insert(4, 2, 1);
    binaryTree.Insert(5, 2, 1);
    binaryTree.Insert(6, 3, 1);
    cout << "Show in Order: ";
    binaryTree.ShowInOrder(1);
}