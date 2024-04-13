#ifndef MATRIX
#define MATRIX

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

#include "MatrixException.hpp"

using namespace std;


template<class T>
class Matrix{
    protected:
        int row;
        int column;
        int capacity;
        int add_point;
        string matrix_name;
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

        Matrix(int col, int row, string name){
            if(col <= 0 || row <= 0){
                MatrixInvalid e;
                throw e;
            }
            this->column = col;
            this->row = row;
            this->capacity = row * col;
            this->add_point = 0;
            this->matrix_name = name;

            this->generatePossibleMap();
        }

        Matrix(Matrix<T>& m){
            this->row = m.row;
            this->column = m.column;
            this->matrix_name = m.matrix_name;
            this->capacity = m.capacity;
            this->add_point = m.add_point;
            this->content = m.content;
            this->possible_map = m.possible_map;
        }

        ~Matrix(){
            for(auto const& [key,val] : content){
                try {
                    delete val;
                } catch (exception &e){

                }
            }
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

        map<string, T> getContent() {
            return content ;
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

        vector<pair<T, string>> getAllElement(){
            vector<pair<T, string>> v;
            auto it = this->content.begin();
            while(it != this->content.end()){
                if(it->second != NULL){
                    v.push_back(make_pair(it->second, it->first));
                }
                it++;
            }
            return v;
        }
 
        void printMatrix(){
            printTitle();
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

        void printTitle(){
            cout << "    ";
            int line_length = 6*column + 1 - matrix_name.size() - 4;
            if(4 + (int) matrix_name.size() > line_length){
                cout << "[ " << matrix_name << " ]";
            } else {
                int count_temp = line_length - line_length/2;
                for(int i = 0 ; i < count_temp ; i++){
                    cout << "=";
                }
                cout << "[ " << matrix_name << " ]";
                for(int i = 0 ; i < line_length/2 ; i++){
                    cout << "=";
                }
                cout << endl;

            }
            

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

        int countItem(__attribute__((unused)) string name) { // needs implementation, help zaki
            return 0 ;
        }
};
#endif