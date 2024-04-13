#include "Petani.hpp"

Petani::Petani() : Player()
{
    this->type = "Petani";
}

Petani::Petani(string name, int body_weight, int gulden, int inventory_row, int inventory_col, int field_row, int field_col) : Player(name, body_weight, gulden, inventory_row, inventory_col)
{
    this->type = "Petani";

    // initiate field;
    this->field = new Field(field_col, field_row);
}

Petani::~Petani()
{
    delete this->field;
}

void Petani::plant()
{ // this too nunggu zaki
}
 
void Petani::harvest(ProductConfig &product_list){
    int slot_available = this->inventory->getSlotAvailableCount() ;
    vector<Plant*> harvest_list = this->field->harvest(slot_available) ;
    vector<Product*> config_list = product_list.getProductList() ;
    int len_harvest = (int)harvest_list.size() ;

    for (int i = 0 ; i < len_harvest ; i++) {
        Product* product_to_make ;
        int j = 0 ;
        while(true) {
            if (config_list[j]->getOrigin() == harvest_list[i]->getObjectName()) {
                product_to_make = config_list[j] ;
                break ;
            }
            else {
                j++ ;
            }
        }
        if (product_to_make->getType() == "MATERIAL_PRODUCT") {
            MaterialProduct *hasil = new MaterialProduct(product_to_make->getId(), product_to_make->getCode(), product_to_make->getObjectName(), product_to_make->getPrice(), product_to_make->getAddedWeight(), product_to_make->getOrigin(), product_to_make->getType()) ;
            this->inventory->addElement(hasil) ;
        }
        else {
            FoodProduct *hasil = new FoodProduct(product_to_make->getId(), product_to_make->getCode(), product_to_make->getObjectName(), product_to_make->getPrice(), product_to_make->getAddedWeight(), product_to_make->getOrigin(), product_to_make->getType()) ;
            this->inventory->addElement(hasil) ;
        }
    }
}

void Petani::printField()
{
}

string Petani::getType()
{
    return this->type;
}

int Petani::payTax()
{
    double gulden = -13;
    // hitung total kekayaan dari Inventory
    map<string, GameObject *>::iterator it = this->inventory->getContent().begin();
    while (it != this->inventory->getContent().end())
    {
        gulden += it->second->getPrice();
        it++;
    }

    // hitung total kekayaan dari Field
    map<string, Plant *>::iterator it2 = this->field->getContent().begin();
    while (it2 != this->field->getContent().end())
    {
        gulden += it2->second->getPrice();
        it++;
    }

    // hitung pajak total
    if (gulden <= 0)
    {
        gulden = 0;
    }
    else if (gulden <= 6)
    {
        gulden = round(gulden * 0.05);
    }
    else if (gulden <= 25)
    {
        gulden = round(gulden * 0.15);
    }
    else if (gulden <= 50)
    {
        gulden = round(gulden * 0.25);
    }
    else if (gulden <= 500)
    {
        gulden = round(gulden * 0.30);
    }
    else
    {
        gulden = round(gulden * 0.35);
    }
    return (int)gulden;
}

ostream &operator<<(ostream &os, Petani &p)
{
    p.field->printMatrix();

    os << "ini dari class petani";

    return os;
}

vector<pair<GameObject *, string>> Petani::getAllPosession()
{
    vector<pair<Plant *, string>> v = this->field->getAllElement();

    vector<pair<GameObject *, string>> p;
    for (int i = 0; i < (int)v.size(); i++)
    {
        p.push_back(make_pair((GameObject *)v[i].first, v[i].second));
    }
    return p;
}

void Petani::setField(Field *m)
{
    this->field = m;
}
void Petani::setPen(__attribute__((unused)) Farm *m) {}

void Petani::currentTurn(string command)
{
    if (command == "CETAK_LADANG")
    {
        cout << command << "succeed"; // debug purposes
    }
    else if (command == "TANAM")
    {
        cout << command << "succeed";
    }
    else if (command == "MAKAN")
    {
        cout << command << "succeed";
    }
    else if (command == "BELI")
    {
        cout << command << "succeed";
    }
    else if (command == "JUAL")
    {
        cout << command << "succeed";
    }
    else if (command == "PANEN")
    {
        cout << command << "succeed";
    }
    else
    {
        invalidCommand e;
        throw e;
    }
}