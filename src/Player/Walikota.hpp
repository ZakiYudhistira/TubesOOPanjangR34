#ifndef __WALIKOTA__
#define __WALIKOTA__

#include "Player.hpp"
#include "Building/Building.hpp"
#include "Exception/Exception.hpp"
#include <iostream>
using namespace std ;

class Walikota : public Player {
    private :
        string type ;
    public :
        Walikota() ;
        Walikota(string name, int body_weight, int gulden) ;
        ~Walikota() ;
        void tax() ; // ternyata harus nunggu matrix juga
        Building build() ;
        Player addPlayer() ;
} ;


#endif