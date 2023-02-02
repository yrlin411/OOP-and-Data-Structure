#ifndef Record_hpp
#define Record_hpp

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "item.hpp"
#include "monster.hpp"
#include "npc.hpp"
#include "player.hpp"

using namespace std;

/* This is the record system. Get the information of the  */
/* player and rooms then save them to (a) file(s). Notice */
/* that using pass by reference can prevent sending the   */
/* whole vector to the function.                          */

class Record
{
private:
    void savePlayer(Player*, ofstream&);
    void saveRooms(vector<Room>&, ofstream&);
    void loadPlayer(Player*, ifstream&);
    void loadRooms(vector<Room>&, ifstream&);
    int roomindex;

public:
    Record();
    void saveToFile(Player*, vector<Room>&);
    void loadFromFile(Player*, vector<Room>&);

};


#endif /* Record_hpp */
