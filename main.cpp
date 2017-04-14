#include <iostream>
#include "List.h"
using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    List<float>* l = new List<>();
    l->addFront(1.2);
    return 0;
}
