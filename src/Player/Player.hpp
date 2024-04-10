#ifndef PLAYER
#define PLAYER

#include <string>
#include <vector>
#include <algorithm>

#include "Matrix/Matrix.hpp"
#include "GameObject/GameObject.hpp"
#include "Exception/Exception.hpp"


class Player  {
    protected :
        std::string name ;
        int body_weight ;
        int gulden ;
        Matrix<GameObject*>* inventory;
    
    public:
        Player() ;
        Player(std::string name, int body_weight, int gulden, int inventory_row, int inventory_col) ;
        virtual ~Player() ;
        void eat() ;
        void setInventory(Matrix<GameObject*>* m);
        void printInventory() ;
        std::string getName() ;
        int getBodyWeight() ;
        int getGulden() ;
        void addBodyWeight(int weight) ;
        void setGulden(int gulden) ;

        friend std::ostream& operator<<(std::ostream& os, Player& p);
};

#endif