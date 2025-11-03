#include "elements.h"
#include "item.h"
#include "enemy.h"
#include <fstream>
#include <memory>
#include <iostream>

int main() {

    std::vector<std::vector<items*>> grid;
    
    std::fstream file("report.txt", std::ios::trunc | std::ios::in | std::ios::out);

    if (!file.is_open()) {
        std::cerr << " Failed to open file! " << "\n" << std::endl;

    }

    std::string fac;

    std::cout << "what faction are you from?"<<"\n"
                 "elf"<<"\n"
                 "human"<<"\n"
                 "viking"<<"\n"
                 "cavalry : ";
    std::cin >> fac;

    weaponrln info = getweaponrlninfo(fac);
    player p("hellzard", info);

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

    tools* axe = new tools("axe");
    consumables* potion = new consumables("Health potion", 6);
    p.bag.showbag();

    p.bag.additems(axe);
    p.bag.additems(potion);
    p.bag.useitem(potion);
    std::cout << "\n";
    p.bag.showbag();

    file << "You're "<< p.name <<" of the "<< fac <<" faction.";
    file.close();

}

