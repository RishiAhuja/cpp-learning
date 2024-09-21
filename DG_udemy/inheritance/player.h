#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <iostream>
#include "person.h"
using namespace std;

class Player : public Person {

    public: 
        Player() = default;
        Player(string game_param);
        ~Player(){};
        void print_info();

    //cant access private members of player (base) class from a person object
    private: 
        string m_game{"none"};
};


#endif