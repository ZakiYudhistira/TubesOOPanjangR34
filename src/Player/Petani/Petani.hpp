#ifndef PETANI
#define PETANI
 
#include "Player/Player.hpp"
#include "GameObject/Plant/Plant.hpp"

class Petani : public Player {
    private :
        string type ;
        Field* field;
    public :
        Petani() ;
        Petani(string name, int body_weight, int gulden, int inventory_row, int inventory_col, int farm_row, int farm_col) ;
        ~Petani() ;
        void plant() ;
        void harvest() ;
        void printField() ;
        string getType() ;
        int payTax() ;

        void currentTurn();

        friend ostream& operator<<(ostream& os, Petani& p);
        
        vector<pair<GameObject*, string>> getAllPosession();

        void setField(Field* m);
        void setPen(Farm* m);
} ;


#endif