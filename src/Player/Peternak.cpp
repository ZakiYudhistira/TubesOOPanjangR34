#include "Peternak.hpp"

Peternak::Peternak() : Player() {
    this->type = "PETERNAK" ;
}

Peternak::Peternak(string name, int body_weight, int gulden) : Player(name, body_weight, gulden) {
    this->type = "PETERNAK" ;
}

void Peternak::ternak() {} // matrikx boi

void Peternak::feed() {} // matrix boi

void Peternak::harvest() { // matrix also

}

void Peternak::printPen() { // matrix also

}