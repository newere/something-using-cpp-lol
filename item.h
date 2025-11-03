#pragma once
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
    tools(std::string name)
        :items("tool", name, 1, 100){}
};

class consumables : public items{
public:
    consumables(std::string name, int quantity)
        :items("consumable",name, quantity, 0){}
};

class armour : public items{
public:
    int defence;

    armour(std::string name, int defence)
        :items("armour", name, 1, 150), defence(defence){}
};
