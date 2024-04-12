#include "Farm.hpp"
#include "GameObject/Animal/Animal.hpp"
#include "pcolor/pcolor.hpp"
#include "Matrix.hpp"

Farm::Farm(int col, int row) : Matrix<Animal*>(col, row, "Farm"){};

void Farm :: printHarvest(){
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
                    Animal* temp = getElement(array_of_character[j] + to_string(0) +to_string(i+1));
                    cout << " ";
                    if(temp->isHarvest()){
                        printStringGreen(temp->getCode());
                    } else {
                        printStringRed(temp->getCode());
                    }
                    cout << " |";
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
                    Animal* temp = getElement(array_of_character[j] + to_string(i+1));
                    cout << " ";
                    if(temp->isHarvest()){
                        printStringGreen(temp->getCode());
                    } else {
                        printStringRed(temp->getCode());
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

// int main(){
//     Farm pp(5,5);
//     pp.printMatrix();
//     return 0;
// }