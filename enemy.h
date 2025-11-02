#pragma once
#include <iostream>

class enemy{
public:
    int health = 120, edmg = 11;
    std::string  type;
    enemy( std::string type)
        :type(type){}
    ~enemy(){}

    int dealdamage(){
        return edmg;
    }

    int takedamage(int dmg){
        health -= dmg;
        if(health <= 0){
            std::cout<<"Enemy has been killed!!"<<std::endl;
        }
        return 0;
    }

};

class boss{
public:
    int health;
    std::string type;
    boss(){}
    boss(int health, std::string type)
        :health(health), type(type){}

    ~boss(){}

};
