#ifndef PLANT_CONFIG
#define PLANT_CONFIG

#include <vector>

#include "Config.hpp"
#include "GameObject/Plant/Plant.hpp"
#include "GameObject/Plant/FruitPlant/FruitPlant.hpp"
#include "GameObject/Plant/MaterialPlant/MaterialPlant.hpp"

class PlantConfig: public Config {
    private:
        vector<Plant*> plant_list;
        int neff;
    public:
        PlantConfig();

        vector<Plant*> getPlantList();

        void addPlant(Plant*);

        pair<Plant*, bool> isInstanceOf(std::string);

        friend std::ostream& operator<<(std::ostream& os, PlantConfig pc);
};

#endif