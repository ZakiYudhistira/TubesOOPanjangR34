#ifndef __PRODUCT__
#define __PRODUCT__

#include "GameObject/GameObject.hpp"

class Product : public GameObject {
    private:
        int added_weight;
        string origin;
    public:
        Product();

        Product(int id, string code_name, string object_name, int price, int added_weight, string origin);

        // Returns the added_weight of a product; 
        int getAddedWeight();

        friend std::ostream& operator<<(std::ostream& os, Product p);
};

#endif