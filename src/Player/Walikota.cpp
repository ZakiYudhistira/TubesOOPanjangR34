#include "Walikota.hpp"

Walikota::Walikota() : Player() {
    this->type = "WALIKOTA" ;
}

Walikota::Walikota(string name, int body_weight, int gulden) : Player(name, body_weight, gulden) {
    this->type = "WALIKOTA" ;
}

void Walikota::tax() {

}

Building Walikota::build() {

}

void Walikota::addPlayer() {

}   