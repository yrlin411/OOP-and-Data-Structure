#include <stdio.h>
#include <iostream>
#include <vector>
#include <fstream>
#include "item.hpp"
#include "Dungeon.hpp"
#include "player.hpp"
#include "monster.hpp"
#include "npc.hpp"
#include "room.hpp"
#include "Record.hpp"

int main(){
    Dungeon dungeon = Dungeon();
    dungeon.runDungeon();
    return 0;
}
