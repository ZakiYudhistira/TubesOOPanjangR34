#include "Walikota.hpp"

Walikota::Walikota() : Player() {
    this->type = "WALIKOTA" ;
}

Walikota::Walikota(std::string name, int body_weight, int gulden, int inventory_row, int inventory_col) : Player(name, body_weight, gulden, inventory_row, inventory_col) {
    this->type = "WALIKOTA" ;
}

Walikota::~Walikota(){}

void Walikota::tax() {

}

Building Walikota::build(__attribute__((unused)) RecipeConfig&  recipe) {
    // cout << "Resep bangunan yang ada adalah sebagai berikut : " << endl ;
    Building hasil ;
    return hasil ; 
}

Player* Walikota::addPlayer(GameConfig& gc) {
    int inventory_row = gc.getInventoryRow();
    int inventory_col = gc.getInventoryCol();
    int field_row = gc.getFieldRow();
    int field_col = gc.getFieldCol();
    int pen_row = gc.getPenRow();
    int pen_col = gc.getPenCol();

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
        Petani *baru = new Petani(name, 40, 50, inventory_row, inventory_col, field_row, field_col) ;
        return baru ;
    } else {
        Peternak *baru = new Peternak(name, 40, 50, inventory_row, inventory_col, pen_row, pen_col) ;
        return baru ;
    }
}   

string Walikota::getType() {
    return this->type ;
}