#ifndef MATRIX
#define MATRIX

#include <iostream>
#include <vector>
#include <map>
#include "../GameObject/GameObject.hpp"
using namespace std;

vector<char> array_of_character = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

class Matrix{
    private:
        int row;
        int column;
        int capacity;
        map<string, GameObject> content;
        vector<string> possible_map;
    public:
        Matrix();

        Matrix(int, int);
        
        int getRow();
        
        int getCol();
        
        GameObject getElement(string);
        
        /*
        * Fungsi menghapus elemen matrix
        * @param coordinate koordinat e.g : `A01, ...` 
        */
        void removeElement(string);

        void addElement(GameObject, string);
        void addElement(GameObject);
        
        void generatePossibleMap();
        
        void printMatrix(); 
        void printMatrixLine();
        
        // virtual void printHarvest();
};
#endif