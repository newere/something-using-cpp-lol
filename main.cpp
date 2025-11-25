#include "elements.h"
#include "item.h"
#include <fstream>
#include<string>
#include <vector>
#include <iostream>
#include <memory>

int main() {
    
    int item_choice;
    std::string fac;
    
    std::fstream file("report.txt", std::ios::trunc | std::ios::in | std::ios::out);

    if (!file.is_open()) {
        std::cerr << " Failed to open file! " << "\n" << std::endl;

    }

    std::cout << "what faction are you from?"<<"\n"
                 "elf"<<"\n"
                 "human"<<"\n"
                 "viking"<<"\n"
                 "cavalry : ";
    std::cin >> fac;

    weaponrln info = getweaponrlninfo(fac);
    player p("hellzard", info);

    file << "You're " << p.name << " of the " << fac << " faction.";

    std::cout << "Faction selected: " << fac << "\n";
    switch (p.weapon) {
    case allweapon::bow:
        std::cout << "Assigned weapon: Bow\n";
        file << "Assigned weapon: Bow\n";
        break;
    case allweapon::axe:
        std::cout << "Assigned weapon: Axe\n";
        file << "Assigned weapon: Axe\n";
        break;
    case allweapon::sword:
        std::cout << "Assigned weapon: Sword\n";
        file << "Assigned weapon: Sword\n";
        break;
    case allweapon::spear:
        std::cout << "Assigned weapon: Spear\n";
        file << "Assigned weapon: Spear\n";
        break;

    }
    /*
    <--------------------------------------------------------------------------------------------------->
    TODO
     >> what do you want to create? <<--- menu for this  <<<---- COMPLETED ---->>>
     >> additionally when the player types "showbag" or something like that then the inventory should be printed out <<<----COMPLETED---->>>
     >>rather than taking the items pointer, it should take the refrence or just the name of the item..
        also try to apply move semantics, const when possible 
    <--------------------------------------------------------------------------------------------------->
    */

    //tools* shovel = new tools("shovel");
    //consumables* potion = new consumables("Health potion", 6);

     bool is_selecting = true;
     std::string name;
     while (is_selecting) {
        char action;
        std::cout << "What do you want to do? (Add->a/View->v/Use->u/Remove->r/Exit->e) : ";
        std::cin >> action;

        switch(action){
            case 'a':{
                std::cout << "What do you want to add (Tools - 1/Consuambles - 2/Armor - 3) : ";
                std::cin >> item_choice;
                p.bag.addItems(item_choice);
                break;
           }
            case 'v':{
                p.bag.showbag();
                break;
            }
            case 'u':{
                //p.bag.useitem();
                break;
            }
            case 'r':{
                //p.bag.removeitem();
                break;
            }
            case 'e':{
                is_selecting = false;
                break;
            }
            default:{
                std::cout<<"ENTER A VALID OPTION AND IT SHOULD BE IN LOWERCASE"<<std::endl;
                is_selecting = false;
            }
        }

     }

    file.close();
}

