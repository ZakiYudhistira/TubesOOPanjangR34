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

ostream& operator<<(ostream& os, __attribute__((unused)) Toko t) {
    os  << "Selamat datang di Toko Cina!" << endl
        << "Berikut merupakan barang-barang yang dapat Anda beli" << endl;

    for (int i=0; i<t.neff; i++) {
        if (t.item_list[i].first->getType() == "MATERIAL_PLANT"
            || t.item_list[i].first->getType() == "FRUIT_PLANT"
            || t.item_list[i].first->getType() == "HERBIVORE"
            || t.item_list[i].first->getType() == "CARNIVORE"
            || t.item_list[i].first->getType() == "OMNIVORE") {
            os << (i+1) << ". " << std::setw(10) << t.item_list[i].first->getObjectName() << std::setw(15) << t.item_list[i].first->getPrice() << endl;
        } else {
            os << (i+1) << ". " << std::setw(10) << t.item_list[i].first->getObjectName() << std::setw(15) << t.item_list[i].first->getPrice() << std::setw(15) << t.item_list[i].second << endl;
        }
    }
    return os;
}

void Toko::beli(vector<GameObject*> sold) {
    for (int i=0; i < (int)sold.size(); i++) {
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
            this->item_list[j].second++;
        } else {
            pair<GameObject*, int> added_item = make_pair(sold[i], 1);
            this->item_list.push_back(added_item);
            this->neff++;
        }
    }
}

pair<GameObject*, int> Toko::jual(Player* current_player) {
    pair<GameObject*, int> item_bought;
    int idx_to_buy;
    int quantity;

    cout << "Barang yang ingin dibeli : ";
    cin >> idx_to_buy;
    cout << "Kuantitas : ";
    cin >> quantity;

    if (quantity > this->item_list[idx_to_buy-1].second) {
        // throw QuantityNotEnoughException();
    } else if (quantity*this->item_list[idx_to_buy-1].first->getPrice() > current_player->getGulden()) {
        throw GuldenNotEnough();
    } else {
        item_bought = make_pair(this->item_list[idx_to_buy-1].first, quantity);
        this->item_list[idx_to_buy-1].second -= quantity;
        return item_bought;
    }
    return item_bought ; // direturn supaya ga error
}