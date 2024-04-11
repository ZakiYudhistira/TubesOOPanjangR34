#include "Petani.hpp"

Petani::Petani() : Player() {
    this->type = "Petani" ;
}

Petani::Petani(std::string name, int body_weight, int gulden, int inventory_row, int inventory_col, int field_row, int field_col) : Player(name, body_weight, gulden, inventory_row, inventory_col) {
    this->type = "Petani" ;

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

string Petani::getType() {
    return this->type ;
}

std::ostream& operator<<(std::ostream& os, Petani& p){
    p.field->printMatrix();
    
    os << "ini dari class petani";

    return os;
}

vector<pair<GameObject*, std::string>> Petani::getAllPosession(){
    vector<pair<Plant*, string>> v = this->field->getAllElement();

    vector<pair<GameObject*, string>> p;
    for(int i=0; i < (int)v.size(); i++){
        p.push_back(make_pair((GameObject*)v[i].first, v[i].second));
    }
    return p;
}

void Petani::setField(Matrix<Plant*>* m){
    this->field = m;
}
void Petani::setPen(__attribute__((unused)) Matrix<Animal*>* m){}