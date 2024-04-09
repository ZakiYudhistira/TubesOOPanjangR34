#ifndef FARM
#define FARM

#include <iostream>
using namespace std;

template<class T>
class Farm : public Matrix {
    public :
        Farm(int, int);
        void printHarvest();
};
#endif