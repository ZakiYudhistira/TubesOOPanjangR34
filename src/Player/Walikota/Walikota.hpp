#ifndef WALIKOTA
#define WALIKOTA

#include "Player/Player.hpp"
#include "Player/Petani/Petani.hpp"
#include "Player/Peternak/Peternak.hpp"

#include "Config/GameConfig.hpp"
#include "Config/RecipeConfig.hpp"
#include "GameObject/Building/Building.hpp"

class Walikota : public Player {
    private :
        std::string type ;
    public :
        Walikota() ;
        Walikota(std::string name, int body_weight, int gulden, int inventory_row, int inventory_col) ;
        ~Walikota() ;
        void tax(vector<Player *> player_list) ;
        Building build(RecipeConfig& recipe) ;
        Player* addPlayer(GameConfig& gc, vector<Player *> player_list) ;
        string getType() ;
        int payTax() ;

        void setField(Matrix<Plant*>* m);
        void setPen(Matrix<Animal*>* m);
        
        vector<pair<GameObject*, string>> getAllPosession();
} ;


#endif