#ifndef PRODUCT_CONFIG
#define PRODUCT_CONFIG

#include <vector>

#include "GameObject/Product/Product.hpp"
#include "GameObject/Product/FoodProduct/FoodProduct.hpp"
#include "GameObject/Product/MaterialProduct/MaterialProduct.hpp"

class ProductConfig {
    private:
        vector<Product*> product_list;
        int neff;
    public:
        ProductConfig();

        ~ProductConfig();

        vector<Product*> getProductList();

        void addProduct(Product*);

        pair<Product*, bool> isInstanceOf(std::string);

        friend std::ostream& operator<<(std::ostream& os, ProductConfig& pc);
};

#endif