#ifndef FARM
#define FARM

#include <iostream>
#include "Matrix.hpp"
using namespace std;

class Farm : public Matrix {
    public :
        Farm(int, int, string);
        void printHarvest();
};
#endif