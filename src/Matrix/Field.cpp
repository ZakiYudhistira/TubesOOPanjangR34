#include "Field.hpp"
#include "GameObject/Plant/Plant.hpp"
#include "pcolor/pcolor.hpp"
#include "FieldException.hpp"
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

vector<Plant*> Field :: harvest(){
    printHarvest();
    
    vector<pair<Plant*, int>> type_count;

    vector<Plant*> ret;

    for(auto i = content.begin() ; i != content.end() ; i++){
        // int count = 0;
        int j;
        for(j = 0; j < (int)type_count.size() ; j++){
            if(i->second->isHarvest()){
                if(i->second->getCode() == type_count[j].first->getCode()){
                    type_count[j].second++;
                }
            }
        }
        if(j == (int)type_count.size()){
            type_count.push_back({i->second, 1});
        }
    }
    if(type_count.size() == 0){
        throw NoHarvestObject();
    }

    cout << endl << endl;
    for(int i = 0 ; i < (int)type_count.size() ; i++){
        cout << " - "  << type_count[i].first->getCode() << ": " << type_count[i].first->getObjectName() << endl;
    }
    return ret;
}