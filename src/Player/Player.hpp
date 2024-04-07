#ifndef __PLAYER__
#define __PLAYER__

#include <string>
using namespace std;
#include <iostream>

<<<<<<< HEAD
class Player
{
protected:
    string name;
    int body_weight;
    int gulden;
    // Matrix inventory ; nunggu spek zaki
    // strint type ; gatau ini apaan

public:
    Player();
    Player(string name, int body_weight, int gulden);
    virtual ~Player();
    void eat();
    void printInventory();
    string getName();
=======
class Player  {
    protected :
        string name ;
        int body_weight ;
        int gulden ;
        // Matrix inventory ; nunggu spek zaki
        // strint type ; gatau ini apaan
    
    public:
        Player() ;
        Player(string name, int body_weight, int gulden) ;
        virtual ~Player() ;
        void eat() ;
        void printInventory() ;
        string getName() ;
        int getBodyWeight() ;
        int getGulden() ;
        void addBodyWeight(int weight) ;
        void setGulden(int gulden) ;
>>>>>>> origin/main
};

#endif