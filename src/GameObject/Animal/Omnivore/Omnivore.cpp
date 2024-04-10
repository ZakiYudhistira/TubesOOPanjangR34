#include "Omnivore.hpp"

Omnivore::Omnivore(): Animal() {
    this->type = "";
}

Omnivore::Omnivore(int id, string code_name, string object_name, string type, int price, int weight_to_harvest): Animal(id, code_name, object_name, price, weight_to_harvest) {
    this->type = type;
}

string Omnivore::getType(){
    return this->type;
}

void Omnivore::setType(string s){
    this->type = s;
}