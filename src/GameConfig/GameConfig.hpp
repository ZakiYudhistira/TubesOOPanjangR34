#ifndef __GAME_CONFIG__
#define __GAME_CONFIG__

class GameConfig {
    public:
        int weight_to_win;
        int gulden_to_win;
        int inventory_row;
        int inventory_col;
        int pen_row;
        int pen_col;
        int field_row;
        int field_col;
    
    public:
        GameConfig();
        
        GameConfig(int, int, int, int, int, int, int, int);
};

#endif