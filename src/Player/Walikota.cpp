#include "Walikota.hpp"
#include "Petani.hpp"
#include "Peternak.hpp"
#include <vector>
#include <algorithm>

Walikota::Walikota() : Player() {
    this->type = "WALIKOTA" ;
}

Walikota::Walikota(string name, int body_weight, int gulden) : Player(name, body_weight, gulden) {
    this->type = "WALIKOTA" ;
}

Walikota::~Walikota(){}

void Walikota::tax() {

}

Building Walikota::build() {
    Building hasil ;
    return hasil ;
}

Player Walikota::addPlayer() {
    if (this->gulden < 50) {
        throw GuldenNotEnough() ;
    }
    string name, type ;
    cout << "Enter player's type : " ;
    cin >> type ;
    transform(name.begin(), name.end(), name.begin(), ::tolower); 
    if (type != "petani" || type != "peternak") {
        throw TypeNotFound() ;
    }
    cout << "Enter player's name : " ;
    cin >> name ;

    this->gulden -= 50 ;
    if (type == "petani") {
        Petani *baru = new Petani(name, 40, 50) ;
        return *baru ;
    }
    else {
        Peternak *baru = new Peternak(name, 40, 50) ;
        return *baru ;
    }
}   