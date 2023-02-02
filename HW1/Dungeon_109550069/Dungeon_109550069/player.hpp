#ifndef player_hpp
#define player_hpp

#include <iostream>
#include <string>
#include <vector>
#include "gameCharacter.hpp"
#include "room.hpp"
#include "item.hpp"

using namespace std;

class Item;

class Player: public GameCharacter
{
private:
    Room* currentRoom;
    Room* previousRoom;
    vector<Item> inventory;
    int savings;
public:
    Player();
    Player(string,int,int,int,int);
    void addItem(Item);
    void increaseStates(int,int,int);
    bool pay(int);
    void changeRoom(Room*);

    /* Virtual function that you need to complete   */
    /* In Player, this function should show the     */
    /* status of player.                            */
    bool triggerEvent(Object*);

    /* Set & Get function*/
    void setCurrentRoom(Room*);
    void setPreviousRoom(Room*);
    void setInventory(vector<Item>);
    void setSavings(int);
    Room* getCurrentRoom();
    Room* getPreviousRoom();
    vector<Item> getInventory();
    int getSavings();
};


#endif /* player_hpp */
