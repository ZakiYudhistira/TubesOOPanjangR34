#ifndef WALIKOTA
#define WALIKOTA

#include "Player/Player.hpp"
#include "Player/Petani/Petani.hpp"
#include "Player/Peternak/Peternak.hpp"

#include "Config/GameConfig.hpp"
#include "GameObject/Building/Building.hpp"

class Walikota : public Player {
    private :
        std::string type ;
    public :
        Walikota() ;
        Walikota(std::string name, int body_weight, int gulden, int inventory_row, int inventory_col) ;
        ~Walikota() ;
        void tax() ; // ternyata harus nunggu matrix juga
        Building build() ;
        Player* addPlayer(GameConfig& gc) ;
} ;


#endif