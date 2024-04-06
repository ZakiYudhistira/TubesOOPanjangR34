#ifndef __PLANT_CONFIG__
#define __PLANT_CONFIG__

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