#ifndef npc_hpp
#define npc_hpp

#include <iostream>
#include <string>
#include <vector>
#include "gameCharacter.hpp"
#include "player.hpp"
#include "item.hpp"

using namespace std;

class NPC: public GameCharacter
{
private:
    string script;
    vector<Item*> commodity1;
    vector<Item*> commodity2;
    vector<Item*> commodity3;
    bool taken1 ;
    bool taken2 ;
    bool taken3 ;
    
public:
    NPC();
    NPC(string, string, vector<Item*>, vector<Item*>, vector<Item*>, bool, bool, bool);
    void listCommodity(); /*print all the Item in this NPC*/

    /* Virtual function that you need to complete   */
    /* In NPC, this function should deal with the   */
    /* transaction in easy implementation           */
    bool triggerEvent(Object*);

    /* Set & Get function*/
    void setScript(string);
    void setCommodity1(vector<Item*>);
    void setCommodity2(vector<Item*>);
    void setCommodity3(vector<Item*>);
    string getScript();
    vector<Item*> getCommodity1();
    vector<Item*> getCommodity2();
    vector<Item*> getCommodity3();
    bool getTaken1();
    bool getTaken2();
    bool getTaken3();
};

#endif /* npc_hpp */
