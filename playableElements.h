#pragma once
#include "items.h"
#include <vector>
#include <iostream>

using namespace std;

class Bag{
private:
    int rows, cols;
    vector<vector<items*>> grid;

public:

    Bag(int r, int c): rows(r), cols(c){
        grid.resize(rows, vector<items*>(cols, nullptr));

    }
    Bag (){}

    bool additems(items* item){
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if (grid[i][j] == nullptr){
                    grid[i][j] = item;
                    return true;
                }

            }
        }
        cout <<"bag is full" << endl;
        return false;

    }

    void removeitems(int r, int c){
        if(r >= 0 && r < rows && c >= 0 && c < cols){
            grid[r][c] = nullptr; // basically make it empty
        }
        else{
            cout <<"[empty]"<< endl;
        }

    }

    void showbag(){
        for(int i = 0; i < rows; i++){
            for(int j =0; j < cols; j++){
                if(grid[i][j]){
                    cout <<"["<< grid[i][j] -> name <<"]";
                }
                else{
                    cout << "[ empty ]" ;
                }
            }
            cout << endl;
        }

    }

};

int useitem(items& item){

    if(item.type == "tools" || item.type == "weapons"){
        item.durability -= 2;
    }
    else if(item.type == "consumables"){
        if(item.quantity > 0){
            item.quantity -= 1;
        }
    }

    return 0;
}

class player{
public:
    Bag bag;
    string name, faction;

    player(string name, string faction){

        this ->name = name;
        this ->faction = faction;

    }
};

