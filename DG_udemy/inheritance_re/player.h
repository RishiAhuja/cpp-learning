#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <iostream>
#include <string_view>
#include "person.h"

// class Person; //forward declaration

class Player : public Person
{
    friend std::ostream& operator<<(std::ostream& out, Player& player);
public:
    Player() = default;
    Player(std::string_view game_param, std::string_view m_fn, std::string_view m_ls, int age);
    
private : 
    std::string m_game{"None"};
};

#endif // PLAYER_H