#ifndef FIELD
#define FIELD

#include <iostream>
#include <vector>
#include "Matrix.hpp"
#include "GameObject/Plant/Plant.hpp"
using namespace std;

class Field : public Matrix<Plant*> {
    public :
        Field(int col, int row);
        void printHarvest();
        void updatePlant();
        vector<pair<Plant*, string>> harvest(int slot_available);
        
};

#endif