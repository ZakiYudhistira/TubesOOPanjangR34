#include "Toko.hpp"

Toko::Toko() {
    this->num_jenis_item = 0;
}

Toko::Toko(int num_jenis_item, vector<vector<GameObject, int>> items) {
    this->num_jenis_item = num_jenis_item;
    this->items = items;
}

int Toko::getNumJenisItem() {
    return this->num_jenis_item;
}

ostream operator<<(ostream& os, Toko t) {
    os  << "Selamat datang di Toko!" << endl
        << "Berikut merupakan barang-barang yang dapat Anda beli" << endl;
    for (int i=0; i<t.num_jenis_item; i++) {
        os << (i+1) << ". " << t.items.at(i).at(0).getObjectName() << " - " << t.items.at(i).at(0).getPrice() << endl;
    }
}

void Toko::beli() {
    
}