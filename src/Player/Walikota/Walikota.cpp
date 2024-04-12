#include "Walikota.hpp"

Walikota::Walikota() : Player() {
    this->type = "Walikota" ;
}

Walikota::Walikota(string name, int body_weight, int gulden, int inventory_row, int inventory_col) : Player(name, body_weight, gulden, inventory_row, inventory_col) {
    this->type = "Walikota" ;
}

void Walikota::tax(vector<Player *> player_list) {
    int len = (int)player_list.size() ;
    int indeks = 0 ;
    int i ; 
    int total_tax = 0;
    for (i = 0 ; i < len ; i++) {
        int tax_player = 0 ;
        string type = player_list[i]->getType() ;
        if (type == "WALIKOTA") {
            continue;
        }
        else {
            tax_player += player_list[i]->payTax() ;
            player_list[i]->addGulden(tax_player * -1) ;
            this->addGulden(tax_player) ;
            total_tax += tax_player ;

            indeks++ ;
            cout << indeks << ". " << player_list[i]->getName() << " - " << player_list[i]->getType() << ": " << tax_player << " Gulden" << endl ;
        }
    }
    cout << "Total Tax : " << total_tax << " Gulden" << endl ;
}

Building* Walikota::build(__attribute__((unused)) RecipeConfig&  recipe) {
    // cout << "Resep bangunan yang ada adalah sebagai berikut : " << endl ;
    Building *hasil = new Building();
    return hasil;
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

int Walikota::payTax() {
    return 0 ;
}

vector<pair<GameObject*, string>> Walikota::getAllPosession(){
    vector<pair<GameObject*, string>> v;
    return v;
}

void Walikota::setField(__attribute__((unused)) Matrix<Plant*>* m){

}
void Walikota::setPen(__attribute__((unused)) Matrix<Animal*>* m){

}

void Walikota::currentTurn(){
    // print banner giliran pemain saat ini
    this->printCurrentTurn();

    // nerima perintah
    string command;

    while(command != "NEXT"){
        cout << "> ";
        cin >> command;
    }

    cout << "Giliran dilanjutkan ke pemain berikutnya.\n";
}