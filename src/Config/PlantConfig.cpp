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
            int id = this->plant_list[i]->getId();
            std::string type = this->plant_list[i]->getType();
            std::string code = this->plant_list[i]->getCode();
            std::string name = this->plant_list[i]->getObjectName();
            int price = this->plant_list[i]->getPrice();
            int days = this->plant_list[i]->getDurationToHarvest();

            if(type == "MATERIAL_PLANT"){
                new_plant = new MaterialPlant(id, code, name, "MATERIAL_PLANT", price, days);
            } else if(type == "FRUIT_PLANT"){
                new_plant = new MaterialPlant(id, code, name, "FRUIT_PLANT", price, days);
            }
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