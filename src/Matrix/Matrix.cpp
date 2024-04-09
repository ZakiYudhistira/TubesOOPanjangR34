#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include "Matrix.hpp"
#include "MatrixException.hpp"
#include "GameObject/GameObject.hpp"

using namespace std;


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
