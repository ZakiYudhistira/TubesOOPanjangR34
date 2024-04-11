#ifndef GAME_CONFIG
#define GAME_CONFIG


#include <iostream>
#include <iomanip>

/*
* Game Configuration class.
*/
class GameConfig {
    private:
        /*weight to win. from config file*/
        int weight_to_win;
        /*amount of gulden to win. from config file*/
        int gulden_to_win;
        /*inventory row from config file*/
        int inventory_row;
        /*inventory column from config file*/
        int inventory_col;
        /*pen row from config file*/
        int pen_row;
        /*pen column from config file*/
        int pen_col;
        /*field row from config file*/
        int field_row;
        /*field column from config file*/
        int field_col;

    public:
        /*
        * Default Constructor. initialize all variable to 0.
        */
        GameConfig();
        
        /*
        * User Defined Constructor. Initiate properties
        * @param ww weight to win
        * @param gw golden to win
        * @param ir inventory row
        * @param ic inventory col
        * @param pr pen row
        * @param pc pen col
        * @param fr field row
        * @param fc field col
        */
        GameConfig(int ww, int gw, int ir, int ic, int pr, int pc, int fr, int fc);

        /*
        * Copy Constructor.
        * @param gc game config to copy
        */
        GameConfig(const GameConfig&);

        GameConfig& operator=(const GameConfig&);

        ~GameConfig();

        int getInventoryRow();

        int getInventoryCol();

        int getPenRow();

        int getPenCol();

        int getFieldRow();

        int getFieldCol();

        friend std::ostream& operator<<(std::ostream& os, GameConfig& gc);
};

#endif