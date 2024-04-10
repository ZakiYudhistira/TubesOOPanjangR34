#include "MaterialPlant.hpp"

MaterialPlant::MaterialPlant(): Plant() {
    this->type = "";
}

MaterialPlant::MaterialPlant(int id, string code_name, string object_name, string type, int price, int duration_to_harvest): Plant(id, code_name, object_name, price, duration_to_harvest) {
    this->type = type;
}