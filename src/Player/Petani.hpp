#ifndef __PETANI__
#define __PETANI__
 
#include "Player.hpp"

class Petani : public Player {
    private :
        string type ;
        // Matrix field ;
    public :
        Petani() ;
        Petani(string name, int body_weight, int gulden) ;
        void plant() ;
        void harvest() ;
        void printField() ;
} ;


#endif