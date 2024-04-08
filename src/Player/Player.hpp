#ifndef PLAYER
#define PLAYER

#include <string>
#include <vector>
#include <algorithm>

#include "Exception/Exception.hpp"


class Player  {
    protected :
        std::string name ;
        int body_weight ;
        int gulden ;
        // Matrix inventory ; nunggu spek zaki
        // strint type ; gatau ini apaan
    
    public:
        Player() ;
        Player(std::string name, int body_weight, int gulden) ;
        virtual ~Player() ;
        void eat() ;
        void printInventory() ;
        std::string getName() ;
        int getBodyWeight() ;
        int getGulden() ;
        void addBodyWeight(int weight) ;
        void setGulden(int gulden) ;
};

#endif