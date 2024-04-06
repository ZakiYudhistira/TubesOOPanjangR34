#include "AnimalConfig.hpp"

AnimalConfig::AnimalConfig(){
    this->neff = 0;
}

vector<Animal> AnimalConfig::getAnimalList(){
    return this->animal_list;
}

void AnimalConfig::addAnimal(Animal& animal){
    this->animal_list.push_back(animal);
    this->neff++;
}

std::ostream& operator<<(std::ostream& os, AnimalConfig ac){
    ac.showConfig(os);

    for(int i=0; i<ac.neff; i++){
        os << ac.animal_list[i];
    }

    return os;
}