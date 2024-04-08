#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include "Matrix.hpp"
#include "MatrixException.hpp"
// #include "../GameObject/GameObject.hpp-"
// #include "../Animal/Animal.hpp"
// #include "../Plant/Plant.hpp"
using namespace std;

Matrix :: Matrix(int col, int row){
    this->column = col;
    this->row = row;
    generatePossibleMap();
}

int Matrix :: getCol(){
    return column;
}

int Matrix :: getRow(){
    return row;
}

void Matrix :: removeElement(string map){
    int cnt = count(possible_map.begin(), possible_map.end(), map);
    if(cnt == 0){
        throw IndexOutOfRange();
    } else {
        content.erase(map);
    }
}

void Matrix :: addElement(GameObject element, string map){
    int cnt = count(possible_map.begin(), possible_map.end(), map);
    if(cnt == 0){
        throw IndexOutOfRange();
    } else {
        content.insert({map, element});
    }
}

GameObject Matrix :: getElement(string map){
    int cnt = count(possible_map.begin(), possible_map.end(), map);
    if(cnt == 0){
        throw IndexOutOfRange();
    } else {
        auto it = content.find(map);
        if(it == content.end()){
            throw ElementNotFound();
        } else {
            return it->second;
        }
    }
}

void Matrix :: generatePossibleMap(){
    for(int i = 0 ; i < row ; i++){
        for(int j = 0 ; j < column ; j++){
            if(i < 10){
                possible_map.push_back("0" + to_string(i+1) + array_of_character[j]);
            } else {
                possible_map.push_back(to_string(i) + array_of_character[j]);
            }
        }
    }
}