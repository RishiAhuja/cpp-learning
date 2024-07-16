#include <iostream> 
#include <string>
#include <cstring>

using namespace std;


//to print star pattern 
/*

*
**
***
****
*****


*/
int main()
{

// for (size_t i {}; i < 10; i++)
// {
//     for (size_t j{}; j <= i; j++)
//     {
//         cout << "*";
//     }
//     cout << endl;
// }

for (int i{1}; i < 10; i++)
{
    std::string message (i, '*');
    cout << message << endl;
}

}