#include <iostream>
#include <optional>

using namespace std;


int& max_return_by_reference(int& a, int& b)
{
    return (a > b) ? a : b;
}

// auto checking_auto_returns(int value){
//     if(value > 10){
//         return 10;
//     }
//     else{
//         return 20.5;
//     }
// }

std::optional<std::string> name = name.value_or("Hello");

int main()
{
    int x{10};
    int y{15};

    int& result = max_return_by_reference(x, y);
    // int result2 = max_return_by_reference(x, y);

    cout << result << endl;

    cout << x << endl;

    cout << name.value() << endl;
};