#ifndef PETERNAK
#define PETERNAK

#include "Player/Player.hpp"
#include "GameObject/Animal/Animal.hpp"

class Peternak : public Player {
    private:
        string type;
        Farm* pen;
    public:
        Peternak();
        Peternak(string name, int body_weight, int gulden, int inventory_row, int inventory_col, int pen_row, int pen_col);
        ~Peternak();
        void ternak();
        void feed();
        void harvest();
        void printPen();
        string getType() ;
        int payTax() ;

        void currentTurn();
        
        vector<pair<GameObject*, string>> getAllPosession();

        void setField(Field* m);
        void setPen(Farm* m);
};

#endif