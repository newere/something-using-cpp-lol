#pragma once
#include <iostream>

using namespace std;

class enemy{
public:
    string  type;
    enemy( string type){
        this -> type = type;

    }

};

class Boss: public enemy{
public:
    int health, damage;
    Boss(int health, int damage){
       this -> health = health;
       this -> damage = damage;

}


};
