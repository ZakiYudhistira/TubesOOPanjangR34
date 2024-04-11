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

GameObject::GameObject(const GameObject& go){
    this->id = go.id;
    this->code_name = go.code_name;
    this->object_name = go.object_name;
    this->price = go.price;
}

GameObject& GameObject::operator=(const GameObject& go){
    this->id = go.id;
    this->code_name = go.code_name;
    this->object_name = go.object_name;
    this->price = go.price;
    return *this;
}

GameObject::~GameObject(){
    cout << "destructor from GameObject\n";
}

int GameObject::getId(){
    return this->id;
}

string GameObject :: getCode(){
    return code_name;
}

string GameObject ::getObjectName(){
    return this->object_name;
}

int GameObject::getPrice(){
    return this->price;
}