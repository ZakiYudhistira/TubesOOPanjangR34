#include "Field.hpp"
#include "GameObject/Plant/Plant.hpp"
#include "pcolor/pcolor.hpp"
#include "Matrix.hpp"
#include <vector>
#include <iostream>
#include <map>
#include <string>
using namespace std;

Field::Field(int col, int row) : Matrix<Plant*>(col, row, "Field"){};

void Field :: printHarvest(){
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
                    Plant* temp = getElement(array_of_character[j] + to_string(0) +to_string(i+1));
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
                    Plant* temp = getElement(array_of_character[j] + to_string(i+1));
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
    };
}

void Field :: updatePlant(){
    for(auto i = content.begin() ; i != content.end() ; i++){
        i->second->incrementCurrentDays();
    }
};

// vector<Plant*> Field :: harvest(){
//     int index = -1;
//     map<string, int> index_map;
//     vector<string> harvest_able;
//     vector<int> object_count;
//     printHarvest();
//     for(auto i = content.begin() ; i != content.end() ; i++){
//         if(i->second->isHarvest()){
//             string code = i->second->getCode();
//             harvest_able.push_back(code);
//         }
//     }
// }