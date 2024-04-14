#ifndef TOKO_HPP
#define TOKO_HPP

#include <vector>
#include <string>

#include "Config/AnimalConfig.hpp"
#include "Config/PlantConfig.hpp"
#include "Config/ProductConfig.hpp"
#include "Config/RecipeConfig.hpp"

#include "GameObject/GameObject.hpp"
#include "Player/Player.hpp"

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

    // getter untuk item ke i
    pair<GameObject *, int> getItemI(int i);

    // Operator overload untuk output item pada toko
    void printToko();

    // Melakukan pembelian dari seorang player pada toko
    void beli(Player *current_player);

    // Melakukan penjualan untuk seorang player dari toko
    void jual(Player *current_player);

    // Menerima input petak saat pembelian hingga masukan valid
    vector<string> inputPetakBeli(int quantity);
};

#endif