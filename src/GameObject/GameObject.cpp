#include "GameObject.hpp"

GameObject::GameObject(){
    this->id = 0;
    this->code_name = "";
    this->object_name = "";
    this->price = 0;
}

GameObject::GameObject(int id, string code_name, string object_name, int price){
    this->id = id;
    this->code_name = code_name;
    this->object_name = object_name;
    this->price = price;
}