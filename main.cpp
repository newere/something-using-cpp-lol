#include "playableElements.h"
#include "items.h"
#include "enemyandsuch.h"
#include <iostream>

using namespace std;

int main() {
    int row, col;

    player pl("arthur", "knight");

    cout << "Your name is " << pl.name << endl;

    pl.bag = Bag(5,5);

    items* shovel = new tools( "shovel");   
    pl.bag.additems(shovel);

    cout << "This is your inventory: " << endl;
    pl.bag.showbag(); 

    return 0;
}

