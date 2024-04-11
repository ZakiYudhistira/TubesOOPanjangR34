#ifndef PRODUCT
#define PRODUCT

#include "GameObject/GameObject.hpp"

class Product : public GameObject {
    private:
        int added_weight;
        string origin;
    public:
        Product();

        Product(int id, string code_name, string object_name, int price, int added_weight, string origin);

        Product(const Product&);
        
        Product& operator=(Product&);

        virtual ~Product();

        // Returns the added_weight of a product; 
        int getAddedWeight();

        string getOrigin();

        virtual string getType() = 0;

        virtual void setType(string s) = 0;
        
        friend std::ostream& operator<<(std::ostream& os, const Product& p);
};

#endif