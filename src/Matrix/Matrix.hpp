#ifndef MATRIX
#define MATRIX

#include <iostream>
#include <vector>
#include <map>
#include "GameObject/GameObject.hpp"
using namespace std;

vector<char> array_of_character = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

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
        Matrix();

        Matrix(int, int);
        
        int getRow();
        int getCol();

        T getElement(string);

        void printMatrix(); 
        void printMatrixLine();
        void removeElement(string);
        void addElement(T, string);
        void addElement(T);
        void generatePossibleMap();
        void resetPoint();
};
#endif