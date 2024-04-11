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
            int id = this->animal_list[i]->getId();
            std::string type = this->animal_list[i]->getType();
            std::string code = this->animal_list[i]->getCode();
            std::string name = this->animal_list[i]->getObjectName();
            int price = this->animal_list[i]->getPrice();
            int weight = this->animal_list[i]->getWeightToHarvest();

            if(type == "HERBIVORE"){
                new_animal = new Herbivore(id, code, name, "HERBIVORE", price, weight);
            } else if(type == "CARNIVORE"){
                new_animal = new Carnivore(id, code, name, "CARNIVORE", price, weight);
            } else if(type == "OMNIVORE"){
                new_animal = new Omnivore(id, code, name, "OMNIVORE", price, weight);
            }
            
            return make_pair(new_animal, true);
        }
    }
    return make_pair(new_animal, false);
}

std::ostream& operator<<(std::ostream& os, AnimalConfig ac){
    ac.showConfig(os);

    for(int i=0; i<ac.neff; i++){
        os << *ac.animal_list[i];
    }

    return os;
}