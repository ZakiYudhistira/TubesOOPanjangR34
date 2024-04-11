#ifndef PLANT_CONFIG
#define PLANT_CONFIG

#include <iostream>
#include <iomanip>
#include <vector>

#include "GameObject/Plant/Plant.hpp"
#include "GameObject/Plant/FruitPlant/FruitPlant.hpp"
#include "GameObject/Plant/MaterialPlant/MaterialPlant.hpp"

class PlantConfig {
    private:
        vector<Plant*> plant_list;
        int neff;
    public:
        PlantConfig();

        ~PlantConfig();

        vector<Plant*> getPlantList();

        void addPlant(Plant*);

        pair<Plant*, bool> isInstanceOf(std::string);

        friend std::ostream& operator<<(std::ostream& os, PlantConfig& pc);
};

#endif