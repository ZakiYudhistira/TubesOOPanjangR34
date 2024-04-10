#include "Walikota.hpp"

Walikota::Walikota() : Player() {
    this->type = "WALIKOTA" ;
}

Walikota::Walikota(std::string name, int body_weight, int gulden) : Player(name, body_weight, gulden) {
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
        GuldenNotEnough e;
        throw e ;
    }
    std::string name, type ;
    std::cout << "Enter player's type : " ;
    std::cin >> type ;
    transform(name.begin(), name.end(), name.begin(), ::tolower); 
    if (type != "petani" || type != "peternak") {
        throw TypeNotFound() ;
    }
    std::cout << "Enter player's name : " ;
    std::cin >> name ;

    this->gulden -= 50 ;
    if (type == "petani") {
        Petani *baru = new Petani(name, 40, 50) ;
        return *baru ;
    } else {
        Peternak *baru = new Peternak(name, 40, 50) ;
        return *baru ;
    }
}   