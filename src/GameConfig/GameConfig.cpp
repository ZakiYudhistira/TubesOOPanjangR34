#include "GameConfig.hpp"

GameConfig::GameConfig(){
    
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

