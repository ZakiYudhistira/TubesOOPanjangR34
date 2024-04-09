#ifndef MATRIX2
#define MATRIX2

#include <iostream>
#include <vector>
#include <map>
#include <iomanip>

#include "Matrix/MatrixException.hpp"

template <class T>
class Matrix2{
    private:
        int row;
        int col;
        int capacity;
        std::map<std::string, T*> content;

        std::vector<std::string> key_col;
        std::vector<std::string> key_row;

        int max_row_digit;
        int max_col_digit;
    public:
        /*
        * Default Constructor. Set all attribute to 0.
        * tidak initiate map.
        */
        Matrix2(){
            this->row = 0;
            this->col = 0;
            this->capacity = 0;
            this->max_col_digit = 0;
            this->max_row_digit = 0;
        }
        /*
        * User Defined Constructor. set all attribute.
        * initiate map values
        * 
        * @param row ukuran baris matrix
        * @param col ukuran kolom matrix
        */
        Matrix2(int row, int col){
            this->col = col;
            this->row = row;
            this->capacity = row * col;

            // creating row and col keys
            this->generateKeyCol();

            this->generateKeyRow();

            // initiate map
            for(int i=0; i < (int)this->key_row.size(); i++){
                for(int j=0; j< (int)this->key_col.size(); j++){
                    this->content[key_col[i] + key_row[j]] = NULL;
                }
            }
        }
        /*
        * Fungsi mengembalikan baris
        * @return row baris
        */
        int getRow(){
            return this->col;
        }
        /*
        * Fungsi mengembalikan kolom
        * @return col kolom
        */
        int getCol(){
            return this->row;
        }
        /*
        * Fungsi mengembalikan objek pada suatu coordinate.
        * @param coordinate koordinat e.g : `A01, ...` 
        * @return elemen
        */
        T getElement(std::string coordinate){
            // check location
            typename std::map<std::string, T*>::iterator it = this->content.find(coordinate);
            if(it == this->content.end()){
                // coordinate not found
                // throw exception or somting;
                IndexOutOfRange e;
                throw e;
            }

            if(it->second == NULL){
                // Empty space
                // throw exception
                EmptySpace e;
                throw e;
            }

            return it->second;
        }
        /*
        * Fungsi menghapus elemen matrix
        * @param coordinate koordinat e.g : `A01, ...` 
        */
        void removeElement(std::string coordinate){
            // check location
            typename std::map<std::string, T*>::iterator it = this->content.find(coordinate);
            if(it == this->content.end()){
                // coordinate not found
                // throw exception or somting;
                IndexOutOfRange e;
                throw e;
            }

            if(it->second == NULL){
                // Empty space
                // throw exception
                EmptySpace e;
                throw e;
            }

            // clear to delete 
            delete it->second;

            it->second = NULL;
        }
        /*
        * Fungsi menambah elemen game object pada lokasi X.
        * Tidak melakukan operasi jika lokasi invalid
        * 
        * @param T& alamat 
        */
        void addElement(T& g, std::string coordinate){
            // check location
            typename std::map<std::string, T*>::iterator it = this->content.find(coordinate);
            if(it == this->content.end()){
                // location not found
                // throw exception or somting;
                IndexOutOfRange e;
                throw e;
            }

            if(it->second != NULL){
                // location already used
                // throw exception
                FilledSpace e;
                throw e;
            }

            // clear to add
            it->second = g;
        }
        /*
        * Fungsi menambah elemen game object pada lokasi pertama kosong.
        * Tidak melakukan operasi jika kapasitas penuh.
        * 
        * @param T& alamat 
        */
        void addElement(T& object){
            // start from index 0 of map
            typename std::map<std::string, T*>::iterator it = this->content.begin();

            while(it != this->content.end()){
                if(it->second == NULL){
                    it->second = object;
                    return;
                }
            }
        }
        
        
        void printMatrix(); 
        void printMatrixLine();

        template<class S>
        friend std::ostream& operator<<(std::ostream& os, Matrix2<S>& m){
            os << std::setw(2 + m.max_row_digit) << " ";

            for(int i=0; i<m.col; i++){
                os << std::setw(7) << m.key_col[i];
            }
            os << "\n";

            // print the map
            for(int j=0; j<m.row; j++){
                // line
                os << setw(5 + m.max_row_digit);
                for(int i=0; i<=m.col; i++){
                    os << "+";
                    if(i < m.col){
                        os << "-----";
                    }
                }
                os << "\n";

                // left key
                os << std::setw(2 + m.max_row_digit) << m.key_row[j];
                // for(int i=0; i<=m.col; i++)

                os << "\n";

            }
            // line
            os << std::setw(7);
            for(int i=0; i<=m.col; i++){
                os << "+";
                if(i < m.col){
                    os << "-----";
                }
            }
            os << "\n";

            return os;
        }
        
        // virtual void printHarvest();

        /* bagian - utilities */
        void generateKeyCol(){
            for(int i=0; i<this->col; i++){
                std::string temp = convertInputToChar(i); 
                if((int)temp.length() > this->max_col_digit){
                    this->max_col_digit = temp.length();
                }
                this->key_col.push_back(temp);
            }
        }

        void generateKeyRow(){
            std::string s_temp = std::to_string(this->col);
            this->max_row_digit = s_temp.length();

            for(int i=0; i<this->row; i++){
                std::string temp = std::to_string(i+1);
                for(int j=temp.length(); j<this->max_row_digit; j++){
                    temp.insert(0, "0");
                }
                this->key_row.push_back(temp);
            }
        }

        std::string convertInputToChar(int x){
            std::string ans = "";
            
            if(x == 0){
                return "A";
            }

            while(x > 0){
                int temp = x % 26 + 'A';
                std::string s{(char)temp};
                ans.insert(0, s);
                x = x / 26;
            }

            return ans;
        }
};

#endif