#ifndef __MATERIAL_PLANT__
#define __MATERIAL_PLANT__

#include "Plant.hpp"

class MaterialPlant: public Plant {
    private:
        string type;
    public:
        MaterialPlant();

        MaterialPlant(int id, string code_name, string object_name, string type, int price, int duration_to_harvest);
};

#endif