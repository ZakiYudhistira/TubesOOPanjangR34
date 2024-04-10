#include "Toko.hpp"

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

ostream& operator<<(ostream& os, __attribute__((unused)) Toko t) {
    os  << "Selamat datang di Toko Cina!" << endl
        << "Berikut merupakan barang-barang yang dapat Anda beli" << endl;

    for (int i=0; i<t.neff; i++) {
        /* TODO: Pakein setw dari library iomapi biar rapi kek tabel! 
            cek file gameconfig buat cara pakenya or tutorial internet */
        os << (i+1) << ". " << t.item_list[i].first->getObjectName() << " " << t.item_list[i].first->getPrice() << " " << t.item_list[i].second << endl;
    }
    return os;
}

void Toko::beli() {
    
}