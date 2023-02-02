#ifndef monster_hpp
#define monster_hpp

#include <iostream>
#include <string>
#include <vector>
#include "gameCharacter.hpp"
#include "player.hpp"

using namespace std;

class Monster: public GameCharacter
{
private:
public:
    Monster();
    Monster(string,int,int,int);

    /* Virtual function that you need to complete   */
    /* In Monster, this function should deal with   */
    /* the combat system.                           */
    bool triggerEvent(Object*);
};


#endif /* monster_hpp */

