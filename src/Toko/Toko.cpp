#include "Toko.hpp"
#include "Exception/Exception.hpp"
#include "Player/Player.hpp"

Toko::Toko() {
    this->neff = 0;
}

Toko::Toko(AnimalConfig& ac, PlantConfig& pc, ProductConfig& prod, RecipeConfig& rc) {

    vector<Animal*> temp_animal = ac.getAnimalList();
    vector<Plant*> temp_plant = pc.getPlantList();
    vector<Product*> temp_product = prod.getProductList();
    vector<Building*> temp_building = rc.getRecipeList();

    int neff_animal = temp_animal.size();
    int neff_plant = temp_plant.size();
    int neff_product = temp_product.size();
    int neff_building = temp_building.size();

    this->neff = neff_animal + neff_plant + neff_building + neff_product;

    // setup item list (vector)
    // -1000 artinya infinite
    for(int i=0; i<neff_animal; i++){
        this->item_list.push_back(make_pair(temp_animal[i], -1000));
    }

    for(int i=0; i<neff_plant; i++){
        this->item_list.push_back(make_pair(temp_plant[i], -1000));
    }

    for(int i=0; i<neff_product; i++){
        this->item_list.push_back(make_pair(temp_product[i], 0));
    }

    for(int i=0; i<neff_building; i++){
        this->item_list.push_back(make_pair(temp_building[i], 0));
    }
}

Toko::Toko(Toko& t){
    this->neff = t.neff;
    this->item_list = t.item_list;
}

Toko& Toko::operator=(Toko& t){
    this->neff = t.neff;
    this->item_list = t.item_list;

    return *this;
}

void Toko::addItem(pair<GameObject*, int> pgi){
    this->item_list.push_back(pgi);
    this->neff++;
}

void Toko::setItemQuantity(std::string s, int qty){
    for(int i=0; i<this->neff; i++){
        if(this->item_list[i].first->getObjectName() == s){
            this->item_list[i].second = qty;
            break;
        }
    }
}

int Toko::getNumJenisItem() {
    return this->neff;
}

pair<GameObject*, int> Toko::getItemI(int i){
    return this->item_list[i];
}

void Toko::printToko() {
    cout  << "Selamat datang di Toko Cina!" << endl
        << "Berikut merupakan barang-barang yang dapat Anda beli" << endl;

    for (int i=0; i<this->neff; i++) {
        cout << (i+1) << ". " << std::setw(10) << this->item_list[i].first->getObjectName() << std::setw(15) << this->item_list[i].first->getPrice();
        if (this->item_list[i].second != -1000) {
            cout << std::setw(15) << this->item_list[i].second;
        }
        cout << endl;
    }
}

void Toko::beli(Player* current_player) {
    cout << "Berikut merupakan penyimpanan Anda" << endl;
    current_player->printInventory();
    cout << "Silahkan pilih petak yang ingin Anda jual" << endl;
    vector<string> petak_jual;
    string input_petak;
    cout << "Petak : ";
    getline(cin, input_petak);
    stringstream ssinput(input_petak);
    string s;
    while (ssinput >> s) {
        petak_jual.push_back(s);
    }

    int gulden_given=0;
    vector<GameObject*> sold;
    // try {
        for (int i=0; i<(int) petak_jual.size(); i++) {
            sold.push_back(current_player->getInventory(petak_jual[i]));
        }
        for (int i=0; i<(int) sold.size(); i++) {
            bool exists = false;
            int j=0;
            while (!exists && j < this->neff) {
                if (this->item_list[j].first->getObjectName() == sold[i]->getObjectName()) {
                    exists = true;
                }
                j++;
            }
            if (exists) {
                j--;
                if (this->item_list[j].second != -1000) {
                    this->item_list[j].second++;
                }
            } else {
                pair<GameObject*, int> added_item = make_pair(sold[i], 1);
                this->item_list.push_back(added_item);
                this->neff++;
            }
            gulden_given += sold[i]->getPrice();
        }
        current_player->addGulden(gulden_given);
        cout << "Barang Anda berhasil dijual! Uang Anda bertambah " << gulden_given << "gulden!\n";
    // } catch (Exception e) {
    //     cout << "";
    // }
}

void Toko::jual(Player* current_player) {
    if (this->cheapest_price > current_player->getGulden()) {
        throw GuldenNotEnough();
    } else if (current_player->getInventoryAvailableCount() == 0) {
        // throw InventoryFullException();
    } else {
        GameObject* item_bought;
        this->printToko();
        cout << "Uang Anda : " << current_player->getGulden() << endl;
        cout << "Slot penyimpanan tersedia : " << current_player->getInventoryAvailableCount() << endl;
        int idx_to_buy;
        int quantity;

        cout << "Barang yang ingin dibeli : ";
        cin >> idx_to_buy;
        cout << "Kuantitas : ";
        cin >> quantity;

        
        if (quantity > this->item_list[idx_to_buy-1].second && this->item_list[idx_to_buy-1].second != -1000) {
            // throw QuantityNotEnoughException();
            cout << "quantity error";
        } else if (quantity*this->item_list[idx_to_buy-1].first->getPrice() > current_player->getGulden()) {
            throw GuldenNotEnough();
        } else if (current_player->getInventoryAvailableCount() < quantity) {
            // throw InventoryNotAvailableException();
            cout << "inventory error";
        } else if (idx_to_buy > this->neff) {
            // throw IndexOutOfRangeException();
            cout << "index error";
        } else {
            item_bought = this->item_list[idx_to_buy-1].first;
            this->item_list[idx_to_buy-1].second -= quantity;
            current_player->addGulden(quantity*item_bought->getPrice()*(-1));
            cout << "Selamat, Anda berhasil membeli " << quantity << " " << item_bought->getObjectName()
                << ". Uang Anda tersisa " << current_player->getGulden() << " gulden." << endl;
            cout << "Pilih slot untuk menyimpan barang yang Anda beli!" << endl;
            current_player->printInventory();
            vector<string> petak_beli = this->inputPetakBeli(quantity);
            current_player->addInventory(item_bought, petak_beli);
            cout << item_bought->getObjectName() << " berhasil disimpan dalam penyimpanan!" << endl;
        }
    }
}

vector<string> Toko::inputPetakBeli(int quantity) {
    vector<string> petak_beli;
    string input_petak;
    string s;
    while ((int) petak_beli.size() != quantity) {
        cout << quantity << endl;
        cout << petak_beli.size() << endl;
        petak_beli.clear();
        cout << "Petak : ";
        getline(cin, input_petak);
        stringstream ssinput(input_petak);
        while (getline(ssinput, s, ',')) {
            petak_beli.push_back(s);
            cout << s << endl;
        }
        if ((int) petak_beli.size() != quantity) {
            cout << "Masukkan sesuai kuantitas yang Anda beli!" << endl;
        }
    }
    return petak_beli;
}