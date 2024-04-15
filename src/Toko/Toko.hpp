#ifndef TOKO_HPP
#define TOKO_HPP

#include <vector>
#include <string>

#include "Exception/Exception.hpp"

#include "Config/AnimalConfig.hpp"
#include "Config/PlantConfig.hpp"
#include "Config/ProductConfig.hpp"
#include "Config/RecipeConfig.hpp"

#include "GameObject/GameObject.hpp"
#include "Matrix/MatrixException.hpp"

using namespace std;

/* Class. Toko */
class Toko
{
private:
    /* daftar item yang dijual besert kuantitasnya */
    vector<pair<GameObject *, int>> item_list;
    /* banyak jenis item pada toko */
    int neff;
    /* Harga terendah barang pada toko */
    int cheapest_price;

public:
    // Default Constructor
    Toko();

    // Constructor dengan item-item yang telah ditentukan dari config
    Toko(AnimalConfig &ac, PlantConfig &pc, ProductConfig &prod, RecipeConfig &rc);

    Toko(Toko &t);

    Toko &operator=(Toko &);

    void addItem(pair<GameObject *, int>);

    void setItemQuantity(std::string, int qty);

    // Getter banyak jenis Item yang tersedia di toko
    int getNumJenisItem();

    int getCheapestPrice();

    // getter untuk item ke i
    pair<GameObject *, int> getItemI(int i);

    // Operator overload untuk output item pada toko
    void printToko();

    // Melakukan pembelian dari seorang player pada toko
    GameObject* beli(int idx, int quantity, int gulden, int inventory_available);

    // Melakukan penjualan untuk seorang player dari toko
    int jual(vector<GameObject*> sold);

    
};

#endif