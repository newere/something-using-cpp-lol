#pragma once
#include <iostream>

using namespace std;

class enemy{
public:

    int health, stamina;
    string  type;
    enemy( string type){
        this -> type = type;

    }

};

class boss{
public:
    int health, stamina;
    string type;
    boss(int health, int stamina, string type){
        this -> health = health;
        this -> stamina = stamina;
        this -> type = type;

    }


};

void placeholder(){
    cout<< " ";
}
