#include "Walikota.hpp"

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

void Walikota::addPlayer() {

}   