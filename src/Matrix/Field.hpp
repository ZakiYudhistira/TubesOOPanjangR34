#ifndef FIELD
#define FIELD

#include <iostream>
#include "Matrix.hpp"
using namespace std;

template<class T>
class Field : public Matrix {
    public :
        Field(int, int);
        void printHarvest();
};
#endif