#ifndef TOKO_HPP
#define TOKO_HPP

#include <vector>
#include <string>
#include "GameObject/GameObject.hpp"

using namespace std;

class Toko {
    private:
        int num_jenis_item;
        vector<vector<GameObject, int>> items;
    public:
        // Default Constructor
        Toko();

        // Constructor dengan item-item yang telah ditentukan
        Toko(int num_jenis_item, vector<vector<GameObject, int>> items);

        // Getter banyak jenis Item yang tersedia di toko
        int getNumJenisItem();

        // Operator overload untuk output item pada toko
        friend ostream operator<<(ostream& os, Toko t);

        // Melakukan pembelian dari seorang player pada toko
        void beli();

        // Melakukan penjualan untuk seorang player dari toko
        void jual();
};

#endif