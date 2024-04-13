#include "Farm.hpp"
#include "GameObject/Animal/Animal.hpp"
#include "pcolor/pcolor.hpp"
#include "FieldException.hpp"
#include "Matrix.hpp"
#include <vector>
#include <iostream>
#include <map>
#include <string>
using namespace std;

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

vector<Animal*> Farm :: harvest(){
    printHarvest();
    
    vector<pair<Animal*, int>> type_count;

    vector<Animal*> ret;

    for(auto i = content.begin() ; i != content.end() ; i++){
        int j;
        for(j = 0; j < (int)type_count.size() ; j++){
            if(i->second->isHarvest()){
                if(i->second->getCode() == type_count[j].first->getCode()){
                    type_count[j].second++;
                    break;
                }
            }
        }
        if(j == (int)type_count.size()){
            if(i->second->isHarvest()){
                type_count.push_back({i->second, 1});
            } else {
                type_count.push_back({i->second, 0});
            }
        }
    }

    int count = 0;

    cout << endl << endl;
    for(int i = 0 ; i < (int)type_count.size() ; i++){
        count += type_count[i].second;
        cout << " - "  << type_count[i].first->getCode() << ": " << type_count[i].first->getObjectName() << endl;
    }

    if(!count){
        throw NoHarvestObject();
    }
    cout << endl;

    cout << "Pilih tanaman siap panen yang kamu miliki" << endl;
    int index = 1;
    for(int i = 0 ; i < (int)type_count.size() ; i++){
        if(type_count[i].second > 0){
            cout << "   " << index << ". " << type_count[i].first->getCode() << " (" << type_count[i].second << " Petak siap panen)" << endl;
            index++;
        } else {
            type_count.erase(type_count.begin() + i);
            i--;
        }
    }
    cout << endl;

    int index_harvest;
    cout << "Nomor tanaman yang ingin di panen: ";
    cin >> index_harvest;
    cout << endl;

    if(index_harvest < 1 || index_harvest > (int)type_count.size()){
        throw HarvestOutOfBounds();
    }

    cout << "Berapa petak yang ingin dipanen: ";
    cin >> count;

    if(count < 1 || count > type_count[index_harvest - 1].second){
        throw HarvestCountInvalid();
    }

    cout << endl;

    cout << "Pilih petak yang akan dipanen:" << endl;
    for(int i = 0 ; i < count ; i++){
    while(true){
        string coordinate;
        cout << "Petak ke-" << i+1 << ": ";
        cin >> coordinate;
            try{
                Animal* temp = getElement(coordinate);
                if(temp->getCode() != type_count[index_harvest - 1].first->getCode()){
                    throw InvalidObject();
                }
                ret.push_back(temp);
                removeElement(coordinate);
                break;
            } catch (InvalidObject &e){
                cout << "Invalid plant to harvest, please try again" << endl;
            } catch (MatrixException &e) {
                cout << "Invalid index, please try again" << endl;
            }
        }
    }

    return ret;
}

// int main(){
//     Farm pp(5,5);
//     pp.printMatrix();
//     return 0;
// }