#ifndef POLY_H
#define POLY_H
#include "List.h"
#include <string>
using namespace std;

class Poly
{
    public:
     //   Poly();
        void insert(float arr[],int len);
        string multiply(Poly* p2);
        float evaluate(float x);
        string differentiate();
        string toString();

    private:
   //     List<float> coeffList;

};

#endif // POLY_H
