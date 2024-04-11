#ifndef PETANI
#define PETANI
 
#include "Player/Player.hpp"
#include "GameObject/Plant/Plant.hpp"

class Petani : public Player {
    private :
        std::string type ;
        Field* field;
    public :
        Petani() ;
        Petani(std::string name, int body_weight, int gulden, int inventory_row, int inventory_col, int farm_row, int farm_col) ;
        ~Petani() ;
        void plant() ;
        void harvest() ;
        void printField() ;
        string getType() ;
        int payTax() ;

        friend std::ostream& operator<<(std::ostream& os, Petani& p);
        
        vector<pair<GameObject*, std::string>> getAllPosession();

        void setField(Matrix<Plant*>* m);
        void setPen(Matrix<Animal*>* m);
} ;


#endif