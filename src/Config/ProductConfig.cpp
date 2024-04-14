#include "ProductConfig.hpp"

ProductConfig::ProductConfig(){
    this->neff = 0;
}

ProductConfig::~ProductConfig(){
    for(int i=0; i<this->neff; i++){
        delete this->product_list[i];
    }
}

vector<Product*> ProductConfig::getProductList(){
    return this->product_list;
}

void ProductConfig::addProduct(Product* plant){
    this->product_list.push_back(plant);
    this->neff++;
}

pair<Product*, bool> ProductConfig::isInstanceOf(std::string s){
    Product* new_product;
    for(int i=0; i<this->neff; i++){
        if(this->product_list[i]->getObjectName() == s){
            int id = this->product_list[i]->getId();
            std::string type = this->product_list[i]->getType();
            std::string code = this->product_list[i]->getCode();
            std::string name = this->product_list[i]->getObjectName();
            std::string origin = this->product_list[i]->getOrigin();
            int price = this->product_list[i]->getPrice();
            int added = this->product_list[i]->getAddedWeight();
            
            if(type == "MATERIAL_PRODUCT"){
                new_product = new MaterialProduct(id, code, name, price, added, origin, "PRODUCT_MATERIAL_PLANT");
            } else if(type == "PRODUCT_FRUIT_PLANT" || type == "PRODUCT_ANIMAL"){
                new_product = new FoodProduct(id, code, name, price, added, origin, type);
            }

            return make_pair(new_product, true);
        }
    }
    return make_pair(new_product, false);
}

std::ostream& operator<<(std::ostream& os, ProductConfig& pc){
    os << std::setw(2) << "id" << ' '
        << std::setw(10) << "code name" << ' '
        << std::setw(15) << "object name" << ' '
        << std::setw(5) << "price" << ' '
        << std::setw(20) << "origin" << ' '
        << std::setw(15) << "added weight" << '\n';

    for(int i=0; i<pc.neff; i++){
        os << *pc.product_list[i];
    }

    return os;
}