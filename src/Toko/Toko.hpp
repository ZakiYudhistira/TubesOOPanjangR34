#ifndef TOKO_HPP
#define TOKO_HPP

#include <vector>
#include <string>

#include "Config/AnimalConfig.hpp"
#include "Config/PlantConfig.hpp"
#include "Config/ProductConfig.hpp"
#include "Config/RecipeConfig.hpp"

#include "GameObject/GameObject.hpp"

using namespace std;

class Toko {
    private:
        vector<pair<GameObject*, int>> item_list;
        int neff;

    public:
        // Default Constructor
        Toko();

        // Constructor dengan item-item yang telah ditentukan
        Toko(AnimalConfig& ac, PlantConfig& pc, ProductConfig& prod, RecipeConfig& rc);

        Toko(Toko& t);

        Toko& operator=(Toko&);

        // Getter banyak jenis Item yang tersedia di toko
        int getNumJenisItem();

        // Operator overload untuk output item pada toko
        friend ostream& operator<<(ostream& os, Toko t);

        // Melakukan pembelian dari seorang player pada toko
        void beli();

        // Melakukan penjualan untuk seorang player dari toko
        void jual();
};

#endif