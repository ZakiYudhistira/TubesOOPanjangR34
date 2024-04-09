#include "Matrix2.hpp"

Matrix2::Matrix2(){
    this->row = 0;
    this->col = 0;
    this->capacity = 0;
    this->max_col_digit = 0;
    this->max_row_digit = 0;
}

Matrix2::Matrix2(int row, int col){
    this->row = row;
    this->col = col;
    this->capacity = row * col;
    this->max_col_digit = 0;
    this->max_row_digit = 0;

    // creating row and col keys
    this->generateKeyCol();

    this->generateKeyRow();

    // initiate map
    for(int i=0; i < (int)this->key_row.size(); i++){
        for(int j=0; j< (int)this->key_col.size(); j++){
            this->content[key_col[i] + key_row[j]] = NULL;
        }
    }
}

void Matrix2::generateKeyCol(){
    for(int i=0; i<this->col; i++){
        string temp = convertInputToChar(i); 
        if((int)temp.length() > this->max_col_digit){
            this->max_col_digit = temp.length();
        }
        this->key_col.push_back(temp);
    }
}

string Matrix2::convertInputToChar(int x){
    std::string ans = "";
    
    if(x == 0){
        return "A";
    }

    while(x > 0){
        int temp = x % 26 + 'A';
        std::string s{(char)temp};
        ans.insert(0, s);
        x = x / 26;
    }

    return ans;
}

void Matrix2::generateKeyRow(){
    std::string s_temp = std::to_string(this->col);
    this->max_row_digit = s_temp.length();

    for(int i=0; i<this->row; i++){
        string temp = std::to_string(i+1);
        for(int j=temp.length(); j<this->max_row_digit; j++){
            temp.insert(0, "0");
        }
        this->key_row.push_back(temp);
    }
}

std::ostream& operator<<(std::ostream& os, Matrix2& m){
    os << std::setw(2 + m.max_row_digit) << " ";

    for(int i=0; i<m.col; i++){
        os << std::setw(7) << m.key_col[i];
    }
    os << "\n";

    // print the map
    for(int j=0; j<m.row; j++){
        // line
        os << setw(5 + m.max_row_digit);
        for(int i=0; i<=m.col; i++){
            os << "+";
            if(i < m.col){
                os << "-----";
            }
        }
        os << "\n";

        // left key
        os << std::setw(2 + m.max_row_digit) << m.key_row[j];
        // for(int i=0; i<=m.col; i++)

        os << "\n";

    }
    // line
    os << setw(7);
    for(int i=0; i<=m.col; i++){
        os << "+";
        if(i < m.col){
            os << "-----";
        }
    }
    os << "\n";

    return os;
}

void Matrix2::addElement(GameObject* g, std::string location){
    // check location
    map<std::string, GameObject*>::iterator it = this->content.find(location);
    if(it == this->content.end()){
        // location not found
        // throw exception or somting;

        return;
    }

    if(it->second != NULL){
        // location already used
        // throw exception

        return;
    }

    // kalau mulus
    it->second = g;

}