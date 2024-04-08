#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include "Matrix.hpp"
#include "MatrixException.hpp"
#include "../GameObject/GameObject.hpp"
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

void Matrix :: printMatrix(){
    cout << "     ";
    for(int i = 0 ; i < column ; i ++){
        cout << "  " << array_of_character[i] << "   ";
    }
    // Row initiation

    cout << endl << "    ";
    printMatrixLine();

    for(int i = 0 ; i < row ; i++){
        if(i+1 < 10){
            cout << " " << 0 << i+1 << " ";
            cout << "|";
            for(int j = 0; j < column ; j++){
                try{
                    GameObject temp = getElement(array_of_character[j] + to_string(0) +to_string(i+1));
                    cout << " " << temp.getCode() << " |";
                } catch(exception &e) {
                    cout << "     |";
                }
            }
            cout << endl << "    ";
            printMatrixLine();
        } else {
            cout << " " << i+1 << " ";
            cout << "|";
            for(int j = 0; j < column ; j++){
                try{
                    GameObject temp = getElement(array_of_character[j] + to_string(i+1));
                    cout << " " << temp.getCode() << " |";
                } catch(exception &e) {
                    cout << "     |";
                }
            }
            cout << endl << "    ";
            printMatrixLine();
        }
    }
}

void Matrix :: printMatrixLine(){
    bool first = true;
    for(int i = 0 ; i < column + 1 ; i++){
        if(first){
            cout << "+";
            first = false;
        } else {
            cout << "-----+";
        }
    }
    cout << endl;
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
            if(i+1 < 10){
                possible_map.push_back( array_of_character[j] + to_string(0) + to_string(i+1));
            } else {
                possible_map.push_back( array_of_character[j] + to_string(i+1));
            }
        }
    }
}

int main(){
    Matrix tes(10,10);
    tes.addElement(GameObject(10, "XXX", "Gay", 1000), "J09");
    tes.printMatrix();
}