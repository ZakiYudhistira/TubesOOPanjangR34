#include "Plant.hpp"

Plant::Plant(): GameObject() {
    this->duration_to_harvest = 0;
    this->current_days = 0 ;
}

Plant::Plant(int id, string code_name, string object_name, int price, int duration_to_harvest): GameObject(id, code_name, object_name, price){
    this->duration_to_harvest = duration_to_harvest;
    this->current_days = 0 ;
}

Plant::Plant(const Plant& p): GameObject(p) {
    this->duration_to_harvest = p.duration_to_harvest;
    this->current_days = p.current_days;
}

Plant& Plant::operator=(Plant& p){
    this->code_name = p.code_name;
    this->current_days = p.current_days;
    this->duration_to_harvest = p.duration_to_harvest;
    this->id = p.id;
    this->object_name = p.object_name;
    this->price = p.price;

    return *this;
}

void Plant::setCurrentDays(int x){
    this->current_days = x;
}

bool Plant::isHarvest() {
    return this->current_days >= this->duration_to_harvest ;
}

std::ostream& operator<<(std::ostream& os, const Plant& a){
    os << std::setw(2) << a.id << ' '
        << std::setw(10) << a.code_name << ' '
        << std::setw(15) << a.object_name << ' '
        << std::setw(5) << a.price << ' '
        << std::setw(15) << a.duration_to_harvest << '\n';

    return os;
}

void Plant::justToMakeVirtual(){}