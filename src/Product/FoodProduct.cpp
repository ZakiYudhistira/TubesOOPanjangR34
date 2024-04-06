#include "FoodProduct.hpp"

FoodProduct::FoodProduct(): Product(){
    this->type = "";
}

FoodProduct::FoodProduct(int id, string code_name, string object_name, int price, int added_weight, string origin, string type): Product(id, code_name, object_name, price, added_weight, origin) {
    this->type = type;
}