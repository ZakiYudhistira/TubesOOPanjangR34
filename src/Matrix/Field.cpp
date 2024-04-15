#include "Field.hpp"
#include "GameObject/Plant/Plant.hpp"
#include "pcolor/pcolor.hpp"
#include "FFException.hpp"
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

    /* PRINT LEGENDA DARI LADANG */
    vector<pair<Plant*, int>> type_count;

    for(auto i = content.begin() ; i != content.end() ; i++){
        int j;
        for(j = 0; j < (int)type_count.size() ; j++){
            if(i->second->getCode() == type_count[j].first->getCode()){
                if(i->second->isHarvest()){
                    type_count[j].second++;
                }
                break;
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
}

void Field :: updatePlant(){
    for(auto i = content.begin() ; i != content.end() ; i++){
        i->second->incrementCurrentDays();
    }
};

vector<pair<Plant*, string>> Field :: harvest(__attribute__((unused)) int slot_available){
    printHarvest();
    
    vector<pair<Plant*, int>> type_count;

    vector<pair<Plant*, string>> ret;

    for(auto i = content.begin() ; i != content.end() ; i++){
        int j;
        for(j = 0; j < (int)type_count.size() ; j++){
            if(i->second->getCode() == type_count[j].first->getCode()){
                if(i->second->isHarvest()){
                    type_count[j].second++;
                }
                break;
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

    if(count > slot_available){
        throw InsufficientSpace();
    }

    cout << endl;

    cout << "Pilih petak yang akan dipanen:" << endl;
    for(int i = 0 ; i < count ; i++){
    while(true){
        string coordinate;
        cout << "Petak ke-" << i+1 << ": ";
        cin >> coordinate;
            try{
                Plant* temp = getElement(coordinate);
                if(temp->getCode() != type_count[index_harvest - 1].first->getCode()){
                    throw InvalidObject();
                }
                if(!temp->isHarvest()){
                    throw NotHarvestAble();
                }
                ret.push_back(make_pair(temp, coordinate));
                break;
            } catch (InvalidObject &e){
                cout << "Invalid plant to harvest, please try again" << endl;
            } catch (NotHarvestAble &e){
                cout << "Plant " << e.what() << ", please try again" << endl;
            } catch (MatrixException &e) {
                cout << "Invalid index, please try again" << endl;
            }
        }
    }
 
    cout << endl << count << " petak tanaman " << type_count[index_harvest - 1].first->getCode() << " ";
    bool first = true;
    for(int k = 0 ; k < (int)ret.size() ; k++){
        if(first){
            cout << ret[k].second;
            first = false;
        } else {
            cout << ", " << ret[k].second;
        }
    }
    cout << " telah dipanen!" << endl; 

    return ret;
}