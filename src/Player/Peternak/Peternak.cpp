#include "Peternak.hpp"

Peternak::Peternak() : Player() {
    this->type = "PETERNAK" ;
}

Peternak::Peternak(std::string name, int body_weight, int gulden, int inventory_row, int inventory_col, int pen_row, int pen_col) : Player(name, body_weight, gulden, inventory_row, inventory_col) {
    this->type = "PETERNAK" ;

    this->pen = new Matrix<Animal*>(pen_col, pen_row);
}

Peternak::~Peternak() {}

void Peternak::ternak() {} // matrikx boi

void Peternak::feed() {} // matrix boi

void Peternak::harvest() { // matrix also

}

void Peternak::printPen() { // matrix also

}