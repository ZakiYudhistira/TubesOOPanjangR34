#include "Building.hpp"

Building::Building(): GameObject(), neff(0) {

};

Building::Building(int id, string code, string name, int price): GameObject(id, code, name, price) {

}

Building::~Building(){
    this->material_list.clear();
    this->code_name = "";
    this->neff = 0;
}

Building::Building(const Building& b): GameObject(b){
    this->neff = b.neff;

    // copy material list;
    for(int i=0; i<b.neff; i++){
        this->material_list.push_back(b.material_list[i]);
    }
}

Building& Building::operator=(Building& b){
    this->code_name = b.code_name;
    this->id = b.id;
    this->neff = b.neff;
    this->object_name = b.object_name;
    this->price = b.price;

    // copy material list;
    for(int i=0; i<b.neff; i++){
        this->material_list.push_back(b.material_list[i]);
    }

    return *this;
}

void Building::addMaterial(pair<string, int> psi){
    this->material_list.push_back(psi);
    this->neff++;
}

std::ostream& operator<<(std::ostream& os, Building& b){
    os << std::setw(2) << b.id << ' '
        << std::setw(10) << b.code_name << ' '
        << std::setw(15) << b.object_name << ' '
        << std::setw(5) << b.price << ' ';
    
    for(int i=0; i<b.neff; i++){
        os << b.material_list[i].first << ' ' << b.material_list[i].second << ' ';
    }

    return os;
}