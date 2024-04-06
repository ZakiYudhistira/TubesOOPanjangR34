#include "Animal.hpp"

Animal::Animal(): GameObject() {
    this->weight_to_harvest = 0;
}

Animal::Animal(int id, string code_name, string object_name, int price, int weight_to_harvest): GameObject(id, code_name, object_name, price){
    this->weight_to_harvest = weight_to_harvest;
}

std::ostream& operator<<(std::ostream& os, Animal a){
    os << std::setw(2) << a.id << ' '
        << std::setw(10) << a.code_name << ' '
        << std::setw(15) << a.object_name << ' '
        << std::setw(5) << a.price << ' '
        << std::setw(15) << a.weight_to_harvest << '\n';

    return os;
}