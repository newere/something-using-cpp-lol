#include "elements.h"
#include "item.h"
#include "enemy.h"
#include <iostream>

int main() {

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
        break;
    case allweapon::axe:
        std::cout << "Assigned weapon: Axe\n";
        break;
    case allweapon::sword:
        std::cout << "Assigned weapon: Sword\n";
        break;
    case allweapon::spear:
        std::cout << "Assigned weapon: Spear\n";
        break;

    }


}

