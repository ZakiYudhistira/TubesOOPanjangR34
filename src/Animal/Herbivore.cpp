#include "Herbivore.hpp"

Herbivore::Herbivore(): Animal() {
    this->type = "";
}

Herbivore::Herbivore(int id, string code_name, string object_name, string type, int price, int weight_to_harvest): Animal(id, code_name, object_name, price, weight_to_harvest) {
    this->type = type;
}