#ifndef PETANI
#define PETANI
 
#include "Player.hpp"

class Petani : public Player {
    private :
        std::string type ;
        // Matrix field ;
    public :
        Petani() ;
        Petani(std::string name, int body_weight, int gulden) ;
        ~Petani() ;
        void plant() ;
        void harvest() ;
        void printField() ;
} ;


#endif