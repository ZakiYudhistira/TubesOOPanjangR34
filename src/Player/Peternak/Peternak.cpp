#include "Peternak.hpp"

Peternak::Peternak() : Player() {
    this->type = "Peternak" ;
}

Peternak::Peternak(string name, int body_weight, int gulden, int inventory_row, int inventory_col, int pen_row, int pen_col) : Player(name, body_weight, gulden, inventory_row, inventory_col) {
    this->type = "Peternak" ;

    this->pen = new Farm(pen_col, pen_row);
}

Peternak::~Peternak() {
    delete this->pen;
}

void Peternak::ternak() {} // matrikx boi

void Peternak::feed() {} // matrix boi

void Peternak::harvest() { // matrix also

}

void Peternak::printPen() { // matrix also

}

string Peternak::getType() {
    return this->type ;
}

int Peternak::payTax() {
    double gulden = -11 ;
    // hitung total kekayaan dari Inventory
    map<string, GameObject*>::iterator it = this->inventory->getContent().begin();
    while (it != this->inventory->getContent().end()) { 
        gulden += it->second->getPrice() ;
        it++; 
    }

    // hitung total kekayaan dari Field
    map<string, Animal*>::iterator it2 = this->pen->getContent().begin();
    while (it2 != this->pen->getContent().end()) { 
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

vector<pair<GameObject*, string>> Peternak::getAllPosession(){
    vector<pair<Animal*, string>> v = this->pen->getAllElement();

    vector<pair<GameObject*, string>> p;
    for(int i=0; i < (int)v.size(); i++){
        p.push_back(make_pair((GameObject*)v[i].first, v[i].second));
    }
    return p;
}

void Peternak::setField(__attribute__((unused)) Field* m){

}

void Peternak::setPen(Farm* m){
    this->pen = m;
}

void Peternak::currentTurn(){
    string title = this->name + " - " + this->getType();
    cout << "+";
    for(int i=0; i<(int)title.length() + 2; i++){
        cout << "-";
    }
    cout << "+\n";

    cout << "| " << title << " |\n";

    cout << "+";
    for(int i=0; i<(int)title.length() + 2; i++){
        cout << "-";
    }
    cout << "+\n";
}