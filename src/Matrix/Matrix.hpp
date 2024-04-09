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
        Matrix(){}

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
        
        int getRow(){
            return row;
        }

        int getCol(){
            return column;
        }

        T getElement(string);

        void printMatrix(); 
        void printMatrixLine();
        
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
                    if(map.size() == capacity){
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