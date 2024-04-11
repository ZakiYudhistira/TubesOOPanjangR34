#include "Player.hpp"

Player::Player(){
    this->name = "null";
    this->body_weight = 0;
    this->gulden = 0;
}

Player::Player(std::string name, int body_weight, int gulden, int inventory_row, int inventory_col){
    this->name = name;
    this->body_weight = body_weight;
    this->gulden = gulden;

    // initiate inventory
    this->inventory = new Matrix<GameObject*>(inventory_col, inventory_row, "Penyimpanan");
}

Player::~Player() {}

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
} // nunggu implementasi matrix

std::string Player::getName() {
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

std::ostream& operator<<(std::ostream& os, Player& p){
    p.inventory->printMatrix();
    
    os << p.name << " "
        << p.body_weight << " "
        << p.gulden << "\n";


    return os;
}

vector<pair<GameObject*, string>> Player::getAllPosession(){
    vector<pair<GameObject*, string>> v;
    return v;
}

void Player::setField(__attribute__((unused)) Matrix<Plant*>* m){}
void Player::setPen(__attribute__((unused)) Matrix<Animal*>* m){}