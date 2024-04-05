#include "GameConfig.hpp"

GameConfig::GameConfig(){
    this->weight_to_win = 0;
    this->gulden_to_win = 0;
    this->inventory_row = 0;
    this->inventory_col = 0;
    this->pen_row = 0;
    this->pen_col = 0;
    this->field_row = 0;
    this->field_col = 0;
}

GameConfig::GameConfig(int weight_to_win, int gulden_to_win, int inventory_row, int inventory_col,
                        int pen_row, int pen_col, int field_row, int field_col){
    this->weight_to_win = weight_to_win;
    this->gulden_to_win = gulden_to_win;
    this->inventory_row = inventory_row;
    this->inventory_col = inventory_col;
    this->pen_row = pen_row;
    this->pen_col = pen_col;
    this->field_row = field_row;
    this->field_col = field_col;
}

GameConfig::GameConfig(const GameConfig& gc){
    this->weight_to_win = gc.weight_to_win;
    this->gulden_to_win = gc.gulden_to_win;
    this->inventory_row = gc.inventory_row;
    this->inventory_col = gc.inventory_col;
    this->pen_row = gc.pen_row;
    this->pen_col = gc.pen_col;
    this->field_row = gc.field_row;
    this->field_col = gc.field_col;
}

GameConfig& GameConfig::operator=(const GameConfig& gc){
    this->weight_to_win = gc.weight_to_win;
    this->gulden_to_win = gc.gulden_to_win;
    this->inventory_row = gc.inventory_row;
    this->inventory_col = gc.inventory_col;
    this->pen_row = gc.pen_row;
    this->pen_col = gc.pen_col;
    this->field_row = gc.field_row;
    this->field_col = gc.field_col;

    return *this;
}

GameConfig::~GameConfig(){
    
}

std::ostream& operator<<(std::ostream& os, GameConfig gc){
    os << std::setw(15) << "weight_to_win:"  << std::setw(20) << gc.weight_to_win << "\n"
        << std::setw(15) << "gulden_to_win:" << std::setw(20) << gc.gulden_to_win << "\n"
        << std::setw(15) << "inventory_row:" << std::setw(20) << gc.inventory_row << "\n"
        << std::setw(15) << "inventory_col:" << std::setw(20) << gc.inventory_col << "\n"
        << std::setw(15) << "pen_row:" << std::setw(20) << gc.pen_row << "\n"
        << std::setw(15) << "pen_col:" << std::setw(20) << gc.pen_col << "\n"
        << std::setw(15) << "field_row:" << std::setw(20) << gc.field_row << "\n"
        << std::setw(15) << "field_col:" << std::setw(20) << gc.field_col << "\n";

    return os;
}