#include "Plant.hpp"

Plant::Plant(): GameObject() {
    this->duration_to_harvest = 0;
}

Plant::Plant(int id, string code_name, string object_name, int price, int duration_to_harvest): GameObject(id, code_name, object_name, price){
    this->duration_to_harvest = duration_to_harvest;
}

std::ostream& operator<<(std::ostream& os, Plant a){
    os << std::setw(2) << a.id << ' '
        << std::setw(10) << a.code_name << ' '
        << std::setw(15) << a.object_name << ' '
        << std::setw(5) << a.price << ' '
        << std::setw(15) << a.duration_to_harvest << '\n';

    return os;
}