#ifndef item_hpp
#define item_hpp

#include <iostream>
#include <string>
#include <vector>
#include "object.hpp"
#include "player.hpp"
using namespace std;

class Player;

class Item: public Object
{
private:
    int health,attack,defense,price,index,taken;
public:
    Item();
    Item(string, int, int, int, int, int, bool);

    /* Virtual function that you need to complete    */
    /* In Item, this function should deal with the   */
    /* pick up action. You should add status to the  */
    /* player.                                       */
    bool triggerEvent(Object*);

    /* Set & Get function*/
    int getHealth();
    int getAttack();
    int getDefense();
    int getPrice();
    int getIndex();
    bool getTaken();
    void setHealth(int);
    void setAttack(int);
    void setDefense(int);
    void setPrice(int);
    void setIndex(int);
};

#endif /* item_hpp */
