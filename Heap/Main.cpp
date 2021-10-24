#include "Heap.h"
#include "Heap.cpp"

int main()
{
    Heap<int, 100> heap;
    heap.Insert(85);
    heap.Insert(55);
    heap.Insert(70);
    heap.Insert(33);
    heap.Insert(54);
    heap.Insert(68);
    heap.Insert(99);
    heap.Show();
    cout << "-----------------" << endl;
    int aux = heap.DeleteFirst();
    cout << "--------" << endl;
    heap.Show();
}