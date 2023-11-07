#include <iostream>
#include <map>
#include <string>
#include <list>

using namespace std;

int main(){

    map<string, list<string>> pokedex;

    list<string> pikachuAttacks{"Thunderbolt", "Quick Attack", "Iron Tail"};
    list<string> charizardAttacks{"Flamethrower", "Fire Spin", "Slash"};
    list<string> blastoiseAttacks{"Hydro Pump", "Water Gun", "Skull Bash"};

    pokedex.insert(pair<string, list<string>>("Pikachu", pikachuAttacks));
    pokedex.insert(pair<string, list<string>>("Charizard", charizardAttacks));
    pokedex.insert(pair<string, list<string>>("Blastoise", blastoiseAttacks));

    for(auto pair : pokedex){
        cout << pair.first << endl;
        for(auto attack : pair.second){
            cout << "\t" << attack << endl;
        }
    }
}