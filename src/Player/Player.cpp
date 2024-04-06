#include "Player.hpp"

Player::Player() {
    this->name = "null" ;
    this->body_weight = 0 ;
    this->gulden = 0 ;
}

Player::Player(string name, int body_weight, int gulden) {
    this->name = name ;
    this->body_weight = body_weight ;
    this->gulden = gulden ;
}

void Player::eat() {} // nunggu implementasi matrix

void Player::printInventory() {} // nunggu implementasi matrix
