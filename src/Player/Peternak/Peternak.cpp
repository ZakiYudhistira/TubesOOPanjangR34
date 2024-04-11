#include "Peternak.hpp"

Peternak::Peternak() : Player() {
    this->type = "Peternak" ;
}

Peternak::Peternak(std::string name, int body_weight, int gulden, int inventory_row, int inventory_col, int pen_row, int pen_col) : Player(name, body_weight, gulden, inventory_row, inventory_col) {
    this->type = "Peternak" ;

    this->pen = new Matrix<Animal*>(pen_col, pen_row, "Peternakan");
}

Peternak::~Peternak() {}

void Peternak::ternak() {} // matrikx boi

void Peternak::feed() {} // matrix boi

void Peternak::harvest() { // matrix also

}

void Peternak::printPen() { // matrix also

}

string Peternak::getType() {
    return this->type ;
}

vector<pair<GameObject*, string>> Peternak::getAllPosession(){
    vector<pair<Animal*, string>> v = this->pen->getAllElement();

    vector<pair<GameObject*, string>> p;
    for(int i=0; i < (int)v.size(); i++){
        p.push_back(make_pair((GameObject*)v[i].first, v[i].second));
    }
    return p;
}

void Peternak::setField(__attribute__((unused)) Matrix<Plant*>* m){

}

void Peternak::setPen(Matrix<Animal*>* m){
    this->pen = m;
}