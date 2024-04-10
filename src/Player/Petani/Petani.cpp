#include "Petani.hpp"

Petani::Petani() : Player() {
    this->type = "PETANI" ;
}

Petani::Petani(std::string name, int body_weight, int gulden) : Player(name, body_weight, gulden) {
    this->type = "PETANI" ;
}

Petani::~Petani() {}

void Petani::plant() { // this too nunggu zaki

}

void Petani::harvest() { // this too nunggu zaki

}

void Petani::printField() { // nunggu ZAKI

}

std::ostream& operator<<(std::ostream& os, Petani& p){
    p.farm.printMatrix();
    
    os << "ini dari class petani";

    return os;
}