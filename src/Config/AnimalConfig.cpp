#include "AnimalConfig.hpp"

AnimalConfig::AnimalConfig(){
    this->neff = 0;
}

vector<Animal*> AnimalConfig::getAnimalList(){
    return this->animal_list;
}

void AnimalConfig::addAnimal(Animal* animal){
    this->animal_list.push_back(animal);
    this->neff++;
}

pair<Animal*, bool> AnimalConfig::isInstanceOf(std::string s){
    Animal* new_animal;
    for(int i=0; i<this->neff; i++){
        if(this->animal_list[i]->getObjectName() == s){
            new_animal = this->animal_list[i];
            return make_pair(new_animal, true);
        }
    }
    return make_pair(new_animal, false);
}

std::ostream& operator<<(std::ostream& os, AnimalConfig ac){
    ac.showConfig(os);

    for(int i=0; i<ac.neff; i++){
        os << ac.animal_list[i];
    }

    return os;
}