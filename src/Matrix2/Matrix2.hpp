#ifndef MATRIX2
#define MATRIX2

#include <iostream>
#include <vector>
#include <map>
#include <iomanip>

#include "GameObject/GameObject.hpp"

class Matrix2 {
    private:
        int row;
        int col;
        int capacity;
        map<std::string, GameObject*> content;
        
        vector<std::string> key_col;
        vector<std::string> key_row;

        int max_row_digit;
        int max_col_digit;
    public:
        Matrix2();

        Matrix2(int row, int col);

        GameObject getElement(string coord);

        void addElement(GameObject*, std::string);
        void addElement(GameObject*);

        friend std::ostream& operator<<(ostream&s, Matrix2&);

        // utilities
        void generateKeyCol();
        void generateKeyRow();

        std::string convertInputToChar(int x);
};

#endif