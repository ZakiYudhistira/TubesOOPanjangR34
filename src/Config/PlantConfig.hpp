#ifndef PLANT_CONFIG
#define PLANT_CONFIG

#include <vector>

#include "Config.hpp"
#include "Plant/Plant.hpp"

class PlantConfig: public Config {
    private:
        vector<Plant> plant_list;
        int neff;
    public:
        PlantConfig();

        vector<Plant> getPlantList();

        void addPlant(Plant&);

        friend std::ostream& operator<<(std::ostream& os, const PlantConfig pc);
};

#endif