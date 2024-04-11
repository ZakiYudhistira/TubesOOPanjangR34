#include "Petani.hpp"

Petani::Petani() : Player() {
    this->type = "PETANI" ;
}

Petani::Petani(std::string name, int body_weight, int gulden, int inventory_row, int inventory_col, int field_row, int field_col) : Player(name, body_weight, gulden, inventory_row, inventory_col) {
    this->type = "PETANI" ;

    // initiate field;
    this->field = new Field(field_col, field_row);
}

Petani::~Petani() {}

void Petani::plant() { // this too nunggu zaki

}

void Petani::harvest() { // this too nunggu zaki

}

void Petani::printField() { 

}

string Petani::getType() {
    return this->type ;
}

int Petani::payTax() {
    double gulden = -13 ;
    // hitung total kekayaan dari Inventory
    std::map<std::string, GameObject*>::iterator it = this->inventory->getContent().begin();
    while (it != this->inventory->getContent().end()) { 
        gulden += it->second->getPrice() ;
        it++; 
    }

    // hitung total kekayaan dari Field
    std::map<std::string, Plant*>::iterator it2 = this->field->getContent().begin();
    while (it2 != this->field->getContent().end()) { 
        gulden += it2->second->getPrice() ;
        it++; 
    }

    // hitung pajak total
    if(gulden <= 0) {
        gulden = 0 ;
    }
    else if (gulden <= 6) {
        gulden = round(gulden * 0.05) ;
    }
    else if (gulden <= 25) {
        gulden = round(gulden * 0.15) ;
    }
    else if (gulden <= 50) {
        gulden = round(gulden * 0.25) ;
    }
    else if (gulden <= 500) {
        gulden = round(gulden * 0.30) ;
    }
    else {
        gulden = round(gulden * 0.35) ;
    }
    return (int)gulden ;
}

std::ostream& operator<<(std::ostream& os, Petani& p){
    p.field->printMatrix();
    
    os << "ini dari class petani";

    return os;
}