#include "Carnivore.hpp"

Carnivore::Carnivore(): Animal() {
    this->type = "";
}

Carnivore::Carnivore(int id, string code_name, string object_name, string type, int price, int weight_to_harvest): Animal(id, code_name, object_name, price, weight_to_harvest) {
    this->type = type;
}

string Carnivore::getType(){
    return this->type;
}

void Carnivore::setType(string s){
    this->type = s;
}