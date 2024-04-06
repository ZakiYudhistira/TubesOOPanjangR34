#ifndef __FRUIT_PLANT__
#define __FRUIT_PLANT__

#include "Plant.hpp"

class FruitPlant: public Plant {
    private:
        string type;
    public:
        FruitPlant();

        FruitPlant(int id, string code_name, string object_name, string type, int price, int duration_to_harvest);
};

#endif