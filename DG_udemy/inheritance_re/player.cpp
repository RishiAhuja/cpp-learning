#include "person.h"
#include "player.h"

// Player::Player(std::string_view game_param, std::string_view m_fn, std::string_view m_ls, int age);

//     : m_game(game_param), m_first_name(m_fn), m_last_name(m_ls), m_age(new int(age))
// {}

Player::Player(std::string_view game_param, std::string_view m_fn, std::string_view m_ls, int age)
    : Person(std::string(m_fn), std::string(m_ls), age), m_game(game_param)
{}

std::ostream& operator<<(std::ostream& out, Player& player) {
 
    out << "Player : [game : "  << player.m_game
         << ", name : " << player.getFirstName()
             << " " << player.getLastName() << "]";
    return out;
}