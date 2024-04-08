#ifndef PRODUCT_CONFIG
#define PRODUCT_CONFIG

#include <vector>

#include "Product/Product.hpp"

class ProductConfig {
    private:
        vector<Product> product_list;
        int neff;
    public:
        ProductConfig();

        vector<Product> getProductList();

        void addProduct(Product&);

        friend std::ostream& operator<<(std::ostream& os, const ProductConfig pc);
};

#endif