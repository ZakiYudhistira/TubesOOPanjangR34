#include "Farm.hpp"
#include "Animal/Animal.hpp"
#include "pcolor/pcolor.hpp"

Farm :: Farm(int col, int row) : Matrix<Animal>(col, row){};

void Farm :: printHarvest(){
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
                    Animal temp = getElement(array_of_character[j] + to_string(i+1));
                    cout << " ";
                    if(temp.isHarvest()){

                    } else {

                    }
                    cout << " |";
                } catch(exception &e) {
                    cout << "     |";
                }
            }
            cout << endl << "    ";
            printMatrixLine();
        }
    }
}