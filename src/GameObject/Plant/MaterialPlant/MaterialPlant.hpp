#ifndef MATERIAL_PLANT
#define MATERIAL_PLANT

#include "GameObject/Plant/Plant.hpp"

class MaterialPlant: public Plant {
    private:
        string type;
    public:
        MaterialPlant();

        MaterialPlant(int id, string code_name, string object_name, string type, int price, int duration_to_harvest);

        string getType();

        void setType(string s);
};

#endif