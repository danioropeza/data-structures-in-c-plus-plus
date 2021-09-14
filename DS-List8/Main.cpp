#include "List8.h"
#include "List8.cpp"

int main()
{
    List8<string> list8;
    list8.AddFront(NULL);
    list8.AddFront("Wolf");
    list8.AddFront("Turtle");
    list8.ShowList();
    list8.DeleteFront();
    list8.ShowList();
    list8.AddFront("Lion");
    list8.ShowList();
    list8.AddBack("Butterfly");
    list8.ShowList();
    list8.DeleteBack();
    list8.ShowList();
    if (list8.SearchRecursive("Tiger") != NULL) {
        cout << "Encontro" << endl;
    }
    else {
        cout << "No encontro" << endl;
    }
    if (list8.Search("Lion") != NULL) {
        cout << "Encontro" << endl;
    }
    else {
        cout << "No encontro" << endl;
    }
    cout << "El menor es: " << list8.SearchTheMinor()->element() << endl;
    cout << "En la posicion: " << list8.Nth(3)->element() << endl;
}