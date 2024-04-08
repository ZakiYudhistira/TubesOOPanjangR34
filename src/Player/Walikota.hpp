#ifndef WALIKOTA
#define WALIKOTA

#include "Player.hpp"
#include "Petani.hpp"
#include "Peternak.hpp"

#include "Building/Building.hpp"

class Walikota : public Player {
    private :
        std::string type ;
    public :
        Walikota() ;
        Walikota(std::string name, int body_weight, int gulden) ;
        ~Walikota() ;
        void tax() ; // ternyata harus nunggu matrix juga
        Building build() ;
        Player addPlayer() ;
} ;


#endif