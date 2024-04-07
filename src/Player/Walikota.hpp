#ifndef __WALIKOTA__
#define __WALIKOTA__

#include "Player.hpp"
#include "Building/Building.hpp"

class Walikota : public Player {
    private :
        string type ;
    public :
        Walikota() ;
        Walikota(string name, int body_weight, int gulden) ;
        ~Walikota() ;
        void tax() ;
        Building build() ;
        void addPlayer() ;
} ;


#endif