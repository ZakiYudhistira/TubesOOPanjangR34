#include "Player.hpp"

Player::Player(){
    this->name = "null";
    this->body_weight = 0;
    this->gulden = 0;
}

Player::Player(std::string name, int body_weight, int gulden){
    this->name = name;
    this->body_weight = body_weight;
    this->gulden = gulden;
}

Player::~Player() {}

void Player::eat() {} // nunggu implementasi matrix

void Player::printInventory() {} // nunggu implementasi matrix

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
