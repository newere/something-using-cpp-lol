#pragma once
#include "item.h"
#include <vector>
#include <memory>
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

public:
int cols = 4;
int rows = 5;
    Bag(){}

    std::vector<std::vector<std::unique_ptr<items>>> grid;

    Bag(int rows, int cols){
        grid.resize(rows);

        for(auto &rows : grid){
            rows.resize(cols);
        }
    }

    std::unique_ptr<items> addItems(int item_choice){

        std::string name;

        switch(item_choice){
            case 1:{
                std::cout << "What Tool do you want to make : ";
                std::cin >> name;
                return std::make_unique<tools>(name);
                break;
            }
            case 2:{
                int quantity;
                std::cout << "What kind of conumable do you want to make : ";
                std::cin >> name;
                std::cout << "\n";
                std::cout << " How many of those :";
                std::cin >> quantity;
                return std::make_unique<consumables>(name, quantity);
                break;
            }
            case 3:{
                std::cout << " What armour do you want to make :";
                std::cin >> name;
                return std::make_unique<armour>(name, 24);
                break;
            }
            default:{
                std::cout<<"Wrong Choice!!, Try Again!"<<std::endl;
                return nullptr;
            }
        }
    }

  // TODO
    //fix this as well <<-- item ko nam linxa and then it searches for that item and if present then it removes it.. 
    // void removeitems(int r, int c){
    //     if(r >= 0 && r < 5 && c >= 0 && c < 4){
    //         grid[r][c] = nullptr; // basically make it empty
    //     }
    //     else{
    //         std::cout <<"[empty]"<< std::endl;
    //     }

    // }

    void showbag(){
        for(int i = 0; i < rows; i++){
            for(int j =0; j < cols; j++){
                if(grid[i][j]){
                    std::cout <<"["<< grid[i][j]->name <<"," <<grid[i][j]->quantity<<","
                         <<grid[i][j]->durability<<"]";
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
    std::string name;
    allfactions faction;
    allweapon weapon;
    Bag bag;
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

