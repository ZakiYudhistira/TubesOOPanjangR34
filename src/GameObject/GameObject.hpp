#ifndef __GAME_OBJECT__
#define __GAME_OBJECT__

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class GameObject {
    protected:
        int id;
        string code_name;
        string object_name;
        int price;

    public:
        GameObject();

        GameObject(int id, string code_name, string object_name, int price);

        // Returns the code_name from a GameObject
        string getCode();
        // Returns the object_name from a GameObject
        string getObjectName();
        // Returns the price or value from a GameObject
        int getPrice();
};

#endif