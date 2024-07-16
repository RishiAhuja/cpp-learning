#include "player.h"
#include "person.h"
using namespace std;

Player::Player(string game_param){
    m_game = game_param;
}

void Player::print_info()
{
    cout << "First name: " << this->get_first_name() << endl;
    cout << "Last name: " << this->get_last_name() << endl;
    cout << "Game: " << m_game << endl;
}
