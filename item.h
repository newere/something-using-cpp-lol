#pragma once
#include "elements.h"
#include <iostream>

class items {
public:
    std::string type, name;
    int quantity, durability;

    items(std::string type, std::string name, int quantity = 1, int durability = 100)
        :type(type), name(name), quantity(quantity), durability(durability){}

    ~items(){}

    items()
        :type("unknown"), name("unknown"), quantity(0), durability(0){}

    void show() {
        std::cout << "[" << type << "] " << name
             << " (x" << quantity << ", dura " << durability << ")\n";
    }
};

class tools : public items{
public:
    tools(){}
    tools(std::string&)
        :items("tool", name, 1, 100){}
};

class consumables : public items{
public:
    consumables(){}
    consumables(std::string&, int quantity)
        :items("consumable",name, quantity, 0){}
};

class armour : public items{
public:
    int defence;

    armour(){}
    armour(std::string&, int defence)
        :items("armour", name, 1, 150), defence(defence){}
};
