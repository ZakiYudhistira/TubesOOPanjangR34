#include "Product.hpp"

Product::Product(): GameObject() {
    this->added_weight = 0;
    this->origin = "";
}

Product::Product(int id, string code_name, string object_name, int price, int added_weight, string origin): GameObject(id, code_name, object_name, price){
    this->added_weight = added_weight;
    this->origin = origin;
}

Product::Product(const Product& p): GameObject(p) {
    this->added_weight = p.added_weight;
    this->origin = p.origin;
}

Product& Product::operator=(Product& p){
    this->id = p.id;
    this->code_name = p.code_name;
    this->object_name = p.object_name;
    this->price = p.price;
    this->added_weight = p.added_weight;
    this->origin = p.origin;

    return *this;
}

int Product::getAddedWeight(){
    return this->added_weight;
}

std::ostream& operator<<(std::ostream& os, Product p){
    os << std::setw(2) << p.id << ' '
        << std::setw(10) << p.code_name << ' '
        << std::setw(15) << p.object_name << ' '
        << std::setw(5) << p.price << ' '
        << std::setw(20) << p.origin
        << std::setw(15) << p.added_weight << '\n';

    return os;
}