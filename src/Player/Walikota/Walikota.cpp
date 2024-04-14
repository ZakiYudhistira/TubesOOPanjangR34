#include "Walikota.hpp"

Walikota::Walikota() : Player()
{
    this->type = "Walikota";
}

Walikota::Walikota(string name, int body_weight, int gulden, int inventory_row, int inventory_col) : Player(name, body_weight, gulden, inventory_row, inventory_col)
{
    this->type = "Walikota";
}

void Walikota::tax(vector<Player *> player_list)
{
    int len = (int)player_list.size();
    int indeks = 0;
    int i;
    int total_tax = 0;
    for (i = 0; i < len; i++)
    {
        int tax_player = 0;
        string type = player_list[i]->getType();
        if (type == "Walikota")
        {
            continue;
        }
        else
        {
            tax_player += player_list[i]->payTax();
            if (tax_player > player_list[i]->getGulden()) {
                tax_player = player_list[i]->getGulden() ;
            }
            player_list[i]->addGulden(tax_player * -1);
            this->addGulden(tax_player);
            total_tax += tax_player;

            indeks++;
            cout << indeks << ". " << player_list[i]->getName() << " - " << player_list[i]->getType() << ": " << tax_player << " Gulden" << endl;
        }
    }
    cout << "Total Tax : " << total_tax << " Gulden" << endl;
}

void Walikota::build(RecipeConfig &recipe)
{
    vector<Building *> building_list = recipe.getRecipeList();

    // Show all available recipes
    cout << "Building recipes available : " << endl;
    for (int i = 1; i <= (int)building_list.size(); i++)
    {
        vector<pair<string, int>> material_list = building_list[i]->getMaterialList();
        cout << "\t" << i << ". " << building_list[i - 1]->getCode() << " (";
        cout << building_list[i]->getPrice() << " gulden, ";
        for (int j = 0; j < (int)material_list.size(); j++)
        {
            if (j == (int)material_list.size())
            {
                cout << material_list[j].first << " " << material_list[j].second << ")" << endl;
            }
            else
            {
                cout << material_list[j].first << " " << material_list[j].second << ", ";
            }
        }
    }

    // input which recipe from user
    string make = "null";
    Building *building;
    cout << "Which building do you want to make : ";
    cin >> make;
    for (int i = 0; i < (int)building_list.size(); i++)
    {
        if (make == building_list[i]->getCode())
        {
            make = building_list[i]->getCode();
            building = building_list[i];
        }
    }
    if (make == "null")
    {
        throw RecipeNotFound();
    }

    // validate materials and gulden
    vector<pair<string, int>> material = building->getMaterialList();
    vector<pair<GameObject *, string>> all_possession = this->inventory->getAllElement();
    vector<pair<string, int>> slot = {};
    if (this->getGulden() < building->getPrice())
    {
        pair<string, int> in;
        in.first = "Gulden";
        in.second = building->getPrice() - this->getGulden();
        slot.push_back(in);
    }
    for (int i = 0; i < (int)material.size(); i++)
    {
        int count_material = this->inventory->getElementCount(material[i].first);
        if (material[i].second > count_material)
        {
            pair<string, int> in;
            in.first = material[i].first;
            in.second = material[i].second - count_material;
            slot.push_back(in);
        }
    }
    if ((int)slot.size() == 0)
    {
        Building *hasil = new Building(*building);
        // remove materials from inventory
        for (int i = 0; i < (int)material.size(); i++)
        {
            int times = material[i].second;
            int j = 0;
            while (times != 0)
            {
                if (all_possession[j].first->getObjectName() == material[i].first)
                {
                    this->inventory->removeElement(all_possession[j].second);
                    times--;
                }
                j++;
            }
        }
        this->inventory->addElement(hasil);
    }
    else
    {
        cout << "Insufficient resources! You still need ";
        for (int i = 0; i < (int)slot.size(); i++)
        {
            if (i == (int)slot.size() - 1)
            {
                cout << slot[i].second << " " << slot[i].first << "." << endl;
            }
            cout << slot[i].second << " " << slot[i].first << ", ";
        }
    }
}

Player *Walikota::addPlayer(GameConfig &gc, vector<Player *> player_list)
{
    int inventory_row = gc.getInventoryRow();
    int inventory_col = gc.getInventoryCol();
    int field_row = gc.getFieldRow();
    int field_col = gc.getFieldCol();
    int pen_row = gc.getPenRow();
    int pen_col = gc.getPenCol();

    if (this->gulden < 50)
    {
        GuldenNotEnough e;
        throw e;
    }
    string name, type;
    cout << "Enter player's type : ";
    cin >> type;
    transform(name.begin(), name.end(), name.begin(), ::tolower);
    if (type != "petani" || type != "peternak")
    {
        throw TypeNotFound();
    }
    std::cout << "Enter player's name : ";
    std::cin >> name;
    int len = (int)player_list.size();
    for (int i = 0; i < len; i++)
    {
        string test = player_list[i]->getName();
        if (name == test)
        {
            throw InvalidName();
        }
    }

    this->gulden -= 50;
    if (type == "petani")
    {
        Petani *baru = new Petani(name, 40, 50, inventory_row, inventory_col, field_row, field_col);
        return baru;
    }
    else
    {
        Peternak *baru = new Peternak(name, 40, 50, inventory_row, inventory_col, pen_row, pen_col);
        return baru;
    }
}

string Walikota::getType()
{
    return this->type;
}

int Walikota::payTax()
{
    return 0;
}

vector<pair<GameObject *, string>> Walikota::getAllPosession()
{
    vector<pair<GameObject *, string>> v;
    return v;
}

void Walikota::setField(__attribute__((unused)) Field *m)
{
}
void Walikota::setPen(__attribute__((unused)) Farm *m)
{
}

void Walikota::currentTurn(string command, vector<Player *> player_list)
{
    if (command == "PUNGUT_PAJAK")
    {
        // Pajak
        for (int i = 0; i < (int)player_list.size(); i++)
        {
            cout << player_list[i]->getGulden() << endl;
        }
        this->tax(player_list);
        cout << command << " succeed\n"; // debug purposes
    }
    else if (command == "BANGUN")
    {
        // Build
        cout << command << " succeed\n";
    }
    else if (command == "MAKAN")
    {
        // Makan
        cout << command << " succeed\n";
    }
    else if (command == "BELI")
    {
        // Beli
        cout << command << " succeed\n";
    }
    else if (command == "JUAL")
    {
        // Jual
        cout << command << " succeed\n";
    }
    else if (command == "TAMBAH_PEMAIN")
    {
        cout << command << " succeed\n";
    }
    else if (command == "NEXT")
    {
    }
    else
    {
        invalidCommand e;
        throw e;
    }
}