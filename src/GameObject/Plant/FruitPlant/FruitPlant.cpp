#include "FruitPlant.hpp"

FruitPlant::FruitPlant(): Plant() {
    this->type = "";
}

FruitPlant::FruitPlant(int id, string code_name, string object_name, string type, int price, int duration_to_harvest): Plant(id, code_name, object_name, price, duration_to_harvest) {
    this->type = type;
}

string FruitPlant::getType(){
    return this->type;
}

void FruitPlant::setType(string s){
    this->type = s;
}