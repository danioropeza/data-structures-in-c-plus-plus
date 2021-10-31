#include "Hash.h"
#include "Hash.cpp"

int main()
{
    Hash<string, 100> hash;
    hash.Insert("wolf");
    hash.Insert("turtle");
    hash.Insert("cat");
    hash.Insert("dog");
    hash.Show();
    hash.Delete("wolf");
    hash.Show();
    Triple<string>* searchedTriple = hash.Search("turtle");
    cout << "Encontro: " << searchedTriple->element() << endl;
}