#include "Petani.hpp"

Petani::Petani() : Player() {
    this->type = "PETANI" ;
}

Petani::Petani(std::string name, int body_weight, int gulden, int inventory_row, int inventory_col, int field_row, int field_col) : Player(name, body_weight, gulden, inventory_row, inventory_col) {
    this->type = "PETANI" ;

    // initiate field;
    this->field = new Matrix<Plant*>(field_col, field_row, "Ladang");
}

Petani::~Petani() {}

void Petani::plant() { // this too nunggu zaki

}

void Petani::harvest() { // this too nunggu zaki

}

void Petani::printField() { 

}

std::ostream& operator<<(std::ostream& os, Petani& p){
    p.field->printMatrix();
    
    os << "ini dari class petani";

    return os;
}