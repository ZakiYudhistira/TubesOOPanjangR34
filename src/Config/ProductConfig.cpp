#include "ProductConfig.hpp"

ProductConfig::ProductConfig(){
    this->neff = 0;
}

vector<Product> ProductConfig::getProductList(){
    return this->product_list;
}

void ProductConfig::addProduct(Product& plant){
    this->product_list.push_back(plant);
    this->neff++;
}

pair<Product*, bool> ProductConfig::isInstanceOf(std::string s){
    Product* new_product = new Product();
    for(int i=0; i<this->neff; i++){
        if(this->product_list[i].getObjectName() == s){
            *new_product = this->product_list[i];
            return make_pair(new_product, true);
        }
    }
    return make_pair(new_product, false);
}

std::ostream& operator<<(std::ostream& os, ProductConfig pc){
    os << std::setw(2) << "id" << ' '
        << std::setw(10) << "code name" << ' '
        << std::setw(15) << "object name" << ' '
        << std::setw(5) << "price" << ' '
        << std::setw(20) << "origin" << ' '
        << std::setw(15) << "added weight" << '\n';

    for(int i=0; i<pc.neff; i++){
        os << pc.product_list[i];
    }

    return os;
}