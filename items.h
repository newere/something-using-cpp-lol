#pragma once
#include <iostream>

using namespace std;

class items{

public:
    string type, name;
    int quantity,durability;
    items(string type, int quantity){

        this -> type = type;
        this -> quantity = quantity;

    }

    items(){}

    void show() {
        cout << type << " x" << quantity << endl;
    }

    void use(){
        items item;
        if(item.type == "tools" || item.type == "weapon"){
            item.durability -= 2;
        }
        else if(item.type == "consumables"){
            if(item.quantity > 0){
                item.quantity -= 1;
            }
        }
        else{
            cout << "No item present";
        }

    }


};

class tools: public items{

public:
    int quanitty = 1;
    int durability = 100;
    tools(string name){
        this -> name = name;
    }
};

class weapons: public items{
public:
    int quanitty = 1;
    int durability = 100;
    weapons(string name){
        this -> name = name;
    }
};

class consumables : public items{
public:
    int quantity = 0;
    int durability = 0;
    consumables(int quantity, string name){
        this -> quantity = quantity;
        this -> name = name;
    }
};

