#ifndef PETANI
#define PETANI
 
#include "Player/Player.hpp"
#include "GameObject/Plant/Plant.hpp"

class Petani : public Player {
    private :
        std::string type ;
        Matrix<Plant*> farm;
    public :
        Petani() ;
        Petani(std::string name, int body_weight, int gulden) ;
        ~Petani() ;
        void plant() ;
        void harvest() ;
        void printField() ;

        friend std::ostream& operator<<(std::ostream& os, Petani& p);
} ;


#endif