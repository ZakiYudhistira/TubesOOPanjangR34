#include "Toko.hpp"

Toko::Toko()
{
    this->neff = 0;
}

Toko::Toko(AnimalConfig &ac, PlantConfig &pc, ProductConfig &prod, RecipeConfig &rc)
{

    vector<Animal *> temp_animal = ac.getAnimalList();
    vector<Plant *> temp_plant = pc.getPlantList();
    vector<Product *> temp_product = prod.getProductList();
    vector<Building *> temp_building = rc.getRecipeList();

    int neff_animal = temp_animal.size();
    int neff_plant = temp_plant.size();
    int neff_product = temp_product.size();
    int neff_building = temp_building.size();

    this->neff = neff_animal + neff_plant + neff_building + neff_product;

    // setup item list (vector)
    // -1000 artinya infinite
    for (int i = 0; i < neff_animal; i++)
    {
        this->item_list.push_back(make_pair(temp_animal[i], -1000));
    }

    for (int i = 0; i < neff_plant; i++)
    {
        this->item_list.push_back(make_pair(temp_plant[i], -1000));
    }

    for (int i = 0; i < neff_product; i++)
    {
        this->item_list.push_back(make_pair(temp_product[i], 0));
    }

    for (int i = 0; i < neff_building; i++)
    {
        this->item_list.push_back(make_pair(temp_building[i], 0));
    }
}

Toko::Toko(Toko &t)
{
    this->neff = t.neff;
    this->item_list = t.item_list;
}

Toko &Toko::operator=(Toko &t)
{
    this->neff = t.neff;
    this->item_list = t.item_list;

    return *this;
}

void Toko::addItem(pair<GameObject *, int> pgi)
{
    this->item_list.push_back(pgi);
    this->neff++;
}

void Toko::setItemQuantity(string s, int qty)
{
    for (int i = 0; i < this->neff; i++)
    {
        if (this->item_list[i].first->getObjectName() == s)
        {
            this->item_list[i].second = qty;
            break;
        }
    }
}

int Toko::getNumJenisItem()
{
    return this->neff;
}

pair<GameObject *, int> Toko::getItemI(int i)
{
    return this->item_list[i];
}

void Toko::printToko()
{
    cout << "Selamat datang di Toko Cina!" << endl
         << "Berikut merupakan barang-barang yang dapat Anda beli" << endl;

    for (int i = 0; i < this->neff; i++)
    {
        cout << setw(2) << (i + 1) << ". " << setw(20) << this->item_list[i].first->getObjectName() << setw(15) << this->item_list[i].first->getPrice();
        if (this->item_list[i].second != -1000)
        {
            cout << setw(15) << this->item_list[i].second;
        }
        cout << endl;
    }
}

int Toko::jual(vector<GameObject*> sold)
{
    int gulden_given = 0;
    for (int i = 0; i < (int)sold.size(); i++)
    {
        bool exists = false;
        int j = 0;
        while (!exists && j < this->neff)
        {
            if (this->item_list[j].first->getObjectName() == sold[i]->getObjectName())
            {
                exists = true;
            }
            j++;
        }
        if (exists)
        {
            j--;
            if (this->item_list[j].second != -1000)
            {
                this->item_list[j].second++;
            }
        }
        else
        {
            pair<GameObject *, int> added_item = make_pair(sold[i], 1);
            this->item_list.push_back(added_item);
            this->neff++;
        }
        gulden_given += sold[i]->getPrice();
    }
    return gulden_given;
}

int Toko::getCheapestPrice(){
    return this->cheapest_price;
}

GameObject* Toko::beli(int idx_to_buy, int quantity, int gulden, int inventory_available)
{
    if (quantity > this->item_list[idx_to_buy - 1].second && this->item_list[idx_to_buy - 1].second != -1000)
    {
        throw QuantityNotEnoughException();
    }
    else if (quantity * this->item_list[idx_to_buy - 1].first->getPrice() > gulden)
    {
        throw GuldenNotEnough();
    }
    else if (inventory_available < quantity)
    {
        throw InventoryNotAvailableException();
    }
    else if (idx_to_buy > this->neff)
    {
        throw IndexOutOfRange();
    }
    else
    {
        GameObject* item_bought;
        item_bought = this->item_list[idx_to_buy - 1].first;
        this->item_list[idx_to_buy - 1].second -= quantity;

        int id = item_bought->getId();
        string code = item_bought->getCode();
        string name = item_bought->getObjectName();
        string type = item_bought->getType();
        int price = item_bought->getPrice();
        int weight = item_bought->getWeightToHarvest();
        int duration = item_bought->getDurationToHarvest();
        int added = item_bought->getAddedWeight();
        string origin = item_bought->getOrigin();


        if(type == "CARNIVORE"){
            item_bought = new Carnivore(id, code, name, type, price, weight);
        } else if(type == "OMNIVORE"){
            item_bought = new Omnivore(id, code, name, type, price, weight);
        } else if(type == "HERBIVORE"){
            item_bought = new Herbivore(id, code, name, type, price, weight);
        } else if(type == "MATERIAL_PLANT"){
            item_bought = new MaterialPlant(id, code, name, type, price, duration);
        } else if(type == "FRUIT_PLANT"){
            item_bought = new FruitPlant(id, code, name, type, price, duration);
        } else if(type == "BUILDING"){
            item_bought = new Building(id, code, name, price);
        } else if(type == "MATERIAL_PRODUCT"){
            item_bought = new MaterialProduct(id, code, name, price, added, origin, type);
        } else if(type == "PROCUCT_FRUIT_PLANT" || type == "PRODUCT_ANIMAL"){
            item_bought = new FoodProduct(id, code, name, price, added, origin, type);
        }

        
        return item_bought;
    }
}