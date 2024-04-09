#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include "Matrix.hpp"
#include "MatrixException.hpp"
#include "../GameObject/GameObject.hpp"

using namespace std;

template<class T>
Matrix<T> :: Matrix(int col, int row){  
    if(col <= 0 || row <= 0){
        throw MatrixInvalid();
    }
    this->column = col;
    this->row = row;
    this->capacity = row * col;
    this->add_point = 0;

    this->generatePossibleMap();
}


template<class T>
int Matrix<T> :: getCol(){
    return column;
}


template<class T>
int Matrix<T> :: getRow(){
    return row;
}


template<class T>
void Matrix<T> :: removeElement(string map){
    int cnt = count(possible_map.begin(), possible_map.end(), map);
    if(cnt == 0){
        throw IndexOutOfRange();
    } else {
        if(!content.count(map)){
            throw EmptySpace();
        }
        content.erase(map);
        resetPoint();
    }
}


template<class T>
void Matrix<T> :: addElement(T element, string map){
    int cnt = count(possible_map.begin(), possible_map.end(), map);
    if(cnt == 0){
        throw IndexOutOfRange();
    } else {
        if(content.count(map)){
            throw FilledSpace();
        } else {
            if(map.size() == capacity){
                throw MatrixFull();
            }
            content.insert({map, element});
            resetPoint();
        }
    }
}

template<class T>
void Matrix<T> :: addElement(T element){
    if(add_point == -1){
        throw MatrixFull();
    } else {
        content.insert({possible_map[add_point], element});
        resetPoint();
    }
}

template<class T>
void Matrix<T> :: printMatrix(){
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
                    T temp = getElement(array_of_character[j] + to_string(0) +to_string(i+1));
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
                    T temp = getElement(array_of_character[j] + to_string(i+1));
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


template<class T>
void Matrix<T> :: printMatrixLine(){
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


template<class T>
T Matrix<T> :: getElement(string map){
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

template<class T>
void Matrix<T> ::generatePossibleMap(){
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

template<class T>
void Matrix<T> :: resetPoint(){
    int i = 0;
    for(i ; i < possible_map.size() ; i++){
        if(!content.count(possible_map[i])){
            add_point = i;
            break;
        }
    }
    if(i == possible_map.size()){
        add_point = -1;
    }
}

// int main(){
//     Matrix<GameObject> tes(3,1);
//     tes.addElement(GameObject(10, "XXX", "Gay", 1000));
//     tes.addElement(GameObject(10, "HOH", "Gay", 1000));

//     // tes.removeElement("A01");

//     tes.removeElement("A01");
//     tes.printMatrix();

//     tes.addElement(GameObject(10, "CRT", "Gay", 1000));
//     tes.addElement(GameObject(10, "VAN", "Gay", 1000));
//     tes.addElement(GameObject(10, "IKR", "Gay", 1000));
//     tes.printMatrix();

// }
