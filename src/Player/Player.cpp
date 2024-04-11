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
    this->inventory = new Matrix<GameObject*>(inventory_col, inventory_row);
}

Player::~Player() {}

void Player::eat() {
    string slot ;
    cout << "Choose food from inventory" << endl ;
    this->inventory->printMatrix() ;
    cout << "Slot : " ;
    cin >> slot ;
    Product food = this->inventory->getElement(slot) ;
    string name = food.getType() ;
    if (name == "FOOD_PRODUCT") {
        this->addBodyWeight(food.getAddedWeight()) ;
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

void Player::printInventory() {
    this->inventory->printMatrix();
}

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

void Player::setGulden(int gulden) {
    this->gulden = gulden ;
}

std::ostream& operator<<(std::ostream& os, Player& p){
    p.inventory->printMatrix();
    
    os << p.name << " "
        << p.body_weight << " "
        << p.gulden << "\n";


    return os;
}