#ifndef FARM
#define FARM

#include <iostream>
#include "Matrix.hpp"
#include "GameObject/Animal/Animal.hpp"
using namespace std;

class Farm : public Matrix<Animal*> {
    public :
        Farm(int col, int row);
        void printHarvest();
        vector<Animal*> harvest();
};
#endif