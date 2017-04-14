#include <iostream>
#include "List.h"
using namespace std;

int main()
{
    List l;
    l.addFront(3);
    l.reverseList();
    l.printALll();
cout<<endl;
    l.addFront(2);
    l.printALll();
cout<<endl;
    l.reverseList();
    l.printALll();
cout<<endl;
    l.addFront(1);
    l.printALll();
cout<<endl;
    l.reverseList();
    l.printALll();
cout<<endl;
    l.clear();
    l.addFront(5);
    l.addFront(4);
    l.addFront(3);
    l.addFront(2);
    l.addFront(1);
    l.printALll();
cout<<endl;
    l.reverseList();
    l.printALll();
   // return 0;
}
