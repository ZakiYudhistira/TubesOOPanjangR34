#ifndef FRUIT_PLANT
#define FRUIT_PLANT

#include "GameObject/Plant/Plant.hpp"

class FruitPlant: public Plant {
    private:
        string type;
    public:
        FruitPlant();

        FruitPlant(int id, string code_name, string object_name, string type, int price, int duration_to_harvest);

        string getType();

        void setType(string s);
};

#endif