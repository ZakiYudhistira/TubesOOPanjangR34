#include "PlantConfig.hpp"

PlantConfig::PlantConfig(){
    this->neff = 0;
}

vector<Plant*> PlantConfig::getPlantList(){
    return this->plant_list;
}

void PlantConfig::addPlant(Plant* plant){
    this->plant_list.push_back(plant);
    this->neff++;
}

pair<Plant*, bool> PlantConfig::isInstanceOf(std::string s){
    Plant* new_plant;
    for(int i=0; i<this->neff; i++){
        if(this->plant_list[i]->getObjectName() == s){
            new_plant = this->plant_list[i];
            return make_pair(new_plant, true);
        }
    }
    return make_pair(new_plant, false);
}

std::ostream& operator<<(std::ostream& os, PlantConfig pc){
    pc.showConfig(os);

    for(int i=0; i<pc.neff; i++){
        os << *pc.plant_list[i];
    }

    return os;
}