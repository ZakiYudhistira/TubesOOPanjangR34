#include "Player.hpp"

Player::Player(){
    this->name = "null";
    this->body_weight = 0;
    this->gulden = 0;
}

Player::Player(string name, int body_weight, int gulden, int inventory_row, int inventory_col){
    this->name = name;
    this->body_weight = body_weight;
    this->gulden = gulden;

    // initiate inventory
    this->inventory = new Matrix<GameObject*>(inventory_col, inventory_row, "Penyimpanan");
}

Player::~Player() {
    delete this->inventory;
}

void Player::eat() {
    string slot ;
    cout << "Choose food from inventory" << endl ;
    this->inventory->printMatrix() ;
    cout << "Slot : " ;
    cin >> slot ;
    GameObject* item = this->inventory->getElement(slot) ;
    string type = item->getType() ;
    if (type == "FOOD_PRODUCT") {
        this->addBodyWeight(item->getAddedWeight()) ;
        this->inventory->removeElement(slot) ;
    }
    else {
        IsNotFood e ;
        throw e ;
    }
} 

void Player::setInventory(Matrix<GameObject*>* m){
    this->inventory = m;
}

vector<pair<GameObject*, string>> Player::getAllItem(){
    return this->inventory->getAllElement();
}

void Player::printInventory() {
    this->inventory->printMatrix();
} 

void Player::printCurrentTurn(){
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

string Player::getName() {
    return this->name ;
}

int Player::getBodyWeight() {
    return this->body_weight ;
}

int Player::getGulden() {
    return this->gulden ;
}

void Player::addBodyWeight(int weight) {
    this->body_weight += weight ;
}

void Player::addGulden(int gulden) {
    this->gulden += gulden ;
}

ostream& operator<<(ostream& os, Player& p){
    p.inventory->printMatrix();
    
    os << p.name << " "
        << p.body_weight << " "
        << p.gulden << "\n";


    return os;
}