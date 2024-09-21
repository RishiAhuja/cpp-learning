#include <iostream>
#include <ctime>
using namespace std;

int main()
{
    //using srand will randomize the answers based on time 0

    std::srand(std::time(0));

    // int ran_num = std::rand(); //will provide a number between 0 ~ RAND_MAX

    // cout << ran_num << endl;
    // cout << RAND_MAX << endl; //provides maximum value out off which

    //std::rand works on a seed, hence it will generate same number again and again.

    // int ran_num;

    // for (size_t i{}; i < 10; i++)
    // {
    //     ran_num = std::rand();

    //     cout << ran_num << endl;
    // }

    // int rand_num = std::rand() % 11; //want to be in [0 to 10]
    int rand_num = (std::rand() % 10) + 1; //want to be in [1 to 10]

    cout << rand_num << endl;    
}