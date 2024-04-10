#ifndef MATRIX
#define MATRIX

#include <iostream>
#include <vector>
#include <map>

#include "MatrixException.hpp"
#include "GameObject/GameObject.hpp"

using namespace std;


template<class T>
class Matrix{
    private:
        int row;
        int column;
        int capacity;
        int add_point;
        map<string, T> content;
        vector<string> possible_map;
    public:
        vector<char> array_of_character = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
        Matrix(){
            this->row = 0;
            this->column = 0;
            this->capacity = 0;
            this->add_point = 0;
        }

        Matrix(int col, int row){
            if(col <= 0 || row <= 0){
                MatrixInvalid e;
                throw e;
            }
            this->column = col;
            this->row = row;
            this->capacity = row * col;
            this->add_point = 0;

            this->generatePossibleMap();
        }

        Matrix(Matrix<T>& m){
            this->row = m.row;
            this->column = m.column;
            this->capacity = m.capacity;
            this->add_point = m.add_point;
            this->content = m.content;
            this->possible_map = m.possible_map;
        }

        Matrix& operator=(Matrix<T>& m){
            this->row = m.row;
            this->column = m.column;
            this->capacity = m.capacity;
            this->add_point = m.add_point;
            this->content = m.content;
            this->possible_map = m.possible_map;

            return *this;
        }
        
        int getRow(){
            return row;
        }

        int getCol(){
            return column;
        }

        T getElement(string map){
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

        void printMatrix(){
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
                            cout << " " << temp->getCode() << " |";
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
                            cout << " " << temp->getCode() << " |";
                        } catch(exception &e) {
                            cout << "     |";
                        }
                    }
                    cout << endl << "    ";
                    printMatrixLine();
                }
            }
        }

        void printMatrixLine(){
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
        
        void removeElement(string map){
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

        void addElement(T element, string map){
            int cnt = count(possible_map.begin(), possible_map.end(), map);
            if(cnt == 0){
                throw IndexOutOfRange();
            } else {
                if(content.count(map)){
                    throw FilledSpace();
                } else {
                    if((int)map.size() == capacity){
                        throw MatrixFull();
                    }
                    content.insert({map, element});
                    resetPoint();
                }
            }
        }

        void addElement(T element){
            if(add_point == -1){
                throw MatrixFull();
            } else {
                content.insert({possible_map[add_point], element});
                resetPoint();
            }
        }

        void generatePossibleMap(){
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

        void resetPoint(){
            int i=0;
            for(i=0 ; i < (int)possible_map.size() ; i++){
                if(!content.count(possible_map[i])){
                    add_point = i;
                    break;
                }
            }
            if(i == (int)possible_map.size()){
                add_point = -1;
            }
        }
};
#endif