#ifndef FIELD
#define FIELD

#include <iostream>
#include "Matrix.hpp"
#include "GameObject/Plant/Plant.hpp"
using namespace std;

class Field : public Matrix<Plant*> {
    public :
        Field(int, int);
        void printHarvest();
};

#endif