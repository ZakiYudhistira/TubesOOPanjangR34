#include "Animal.hpp"

Animal::Animal(): GameObject() {
    this->weight_to_harvest = 0;
    this->current_weight = 0 ;
}
 
Animal::Animal(int id, string code_name, string object_name, int price, int weight_to_harvest): GameObject(id, code_name, object_name, price){
    this->weight_to_harvest = weight_to_harvest;
    this->current_weight = 0 ;
}

Animal::Animal(const Animal& p): GameObject(p) {
    this->weight_to_harvest = p.weight_to_harvest;
    this->current_weight = p.current_weight;
}

Animal& Animal::operator=(Animal& p){
    this->code_name = p.code_name;
    this->current_weight = p.current_weight;
    this->id = p.id;
    this->object_name = p.object_name;
    this->price = p.price;
    this->weight_to_harvest = p.weight_to_harvest;

    return *this;
}

Animal::~Animal(){
    cout << "destructor from Animal class\n";
}

void Animal::setCurrentWeight(int x){
    this->current_weight = x;
}

bool Animal::isHarvest() {
    return this->current_weight >= this->weight_to_harvest ;
}

std::ostream& operator<<(std::ostream& os, const Animal& a){
    os << std::setw(2) << a.id << ' '
        << std::setw(10) << a.code_name << ' '
        << std::setw(15) << a.object_name << ' '
        << std::setw(5) << a.price << ' '
        << std::setw(15) << a.weight_to_harvest << '\n';

    return os;
}

