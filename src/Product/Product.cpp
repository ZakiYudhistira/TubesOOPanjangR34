#include "Product.hpp"

Product::Product(): GameObject() {
    this->added_weight = 0;
    this->origin = "";
}

Product::Product(int id, string code_name, string object_name, int price, int added_weight, string origin): GameObject(id, code_name, object_name, price){
    this->added_weight = added_weight;
    this->origin = origin;
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