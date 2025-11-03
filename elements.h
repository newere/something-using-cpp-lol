#pragma once
#include "item.h"
#include <vector>
#include <iostream>

enum class allfactions{
    elf,
    viking,
    human,
    cavalry
};

enum class allweapon{
    sword,
    bow,
    spear,
    axe,
};

struct weaponrln{
    allfactions faction;
    allweapon weapon;
};

constexpr weaponrln elffaction = {allfactions::elf, allweapon::bow};
constexpr weaponrln vikingfaction = {allfactions::viking, allweapon::axe};
constexpr weaponrln humanfaction = {allfactions::human, allweapon::sword};
constexpr weaponrln cavalryfaction = {allfactions::cavalry, allweapon::spear};

weaponrln getweaponrlninfo(const std::string& fac){
    if(fac == "elf"){
        return elffaction;
    }
    if(fac == "viking"){
        return vikingfaction;
    }
    if(fac == "human"){
        return humanfaction;
    }
    if(fac == "cavalry"){
        return cavalryfaction;
    }

    std::cout<<"unknown faction | defaulting to human!"<<std::endl;
    return humanfaction;

}

class Bag{
private:
    std::vector<std::vector<items*>> grid;

public:

    Bag(){
        grid.resize(5, std::vector<items*>(4, nullptr));
    }

    ~Bag(){}

    bool additems(items* item){
        for(int i = 0; i < 5; i++){
            for(int j = 0; j < 4; j++){
                if (grid[i][j] == nullptr){
                    grid[i][j] = item;
                    return true;
                }

            }
        }
        std::cout <<"bag is full" << std::endl;
        return false;

    }

    void removeitems(int r, int c){
        if(r >= 0 && r < 5 && c >= 0 && c < 4){
            grid[r][c] = nullptr; // basically make it empty
        }
        else{
            std::cout <<"[empty]"<< std::endl;
        }

    }

    void showbag(){
        for(int i = 0; i < 5; i++){
            for(int j =0; j < 4; j++){
                if(grid[i][j]){
                    std::cout <<"["<< grid[i][j] -> name <<"," <<grid[i][j] ->quantity<<","
                         <<grid[i][j] ->durability<<"]";
                }
                else{
                    std::cout << "[ empty ]" ;
                }
            }
            std::cout << std::endl;
        }

    }

    int useitem(items* item){

        if(item->durability > 0){
            item->durability -= 2;
        }
        else if(item->durability == 0){
            if(item->quantity > 0){
                item->quantity = item->quantity - 1;
            }
            else{
                std::cout <<"You don't even have the item";
            }
        }

        return 0;
    }

};

class player{
public:
    allfactions faction;
    allweapon weapon;
    Bag bag;
    std::string name;
    int health = 100, damage = 13;

    player(std::string name, weaponrln& info)
        :name(name), faction(info.faction), weapon(info.weapon){}

    ~player(){}

    int dealdamage() const {
        return damage;
    }

    int takedamage(int edmg){
        health -= edmg;
        if(health <= 0 ){
            std::cout <<"player has died!!" <<std::endl;

        }
        return 0;
    }

};

