#include "MaterialProduct.hpp"

MaterialProduct::MaterialProduct(): Product(){
    this->type = "";
}

MaterialProduct::MaterialProduct(int id, string code_name, string object_name, int price, int added_weight, string origin, string type): Product(id, code_name, object_name, price, added_weight, origin) {
    this->type = type;
}

string MaterialProduct::getType(){
    return this->type;
}

void MaterialProduct::setType(string s){
    this->type = s;
}