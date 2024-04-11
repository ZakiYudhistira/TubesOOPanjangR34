#ifndef PLAYER
#define PLAYER

#include <string>
#include <vector>
#include <algorithm>

#include "GameObject/Product/Product.hpp"
#include "Matrix/Matrix.hpp"
#include "Matrix/Farm.hpp"
#include "Matrix/Field.hpp"
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
        virtual void setField(Matrix<Plant*>* m);
        virtual void setPen(Matrix<Animal*>* m);
        // get all item in inventory
        vector<pair<GameObject*, std::string>> getAllItem();
        void printInventory() ;
        std::string getName() ;
        int getBodyWeight() ;
        int getGulden() ;
        void addBodyWeight(int weight) ;
        void setGulden(int gulden) ;
        virtual string getType() = 0;
        // get all item in ladang or peternakan
        virtual std::vector<pair<GameObject*, string>> getAllPosession();
        friend std::ostream& operator<<(std::ostream& os, Player& p);
};

#endif