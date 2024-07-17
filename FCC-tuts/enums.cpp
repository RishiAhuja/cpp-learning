#include <iostream>

using namespace std;

//intializing enum class
// enum class Month{
//     Jan, Feb, Mar, 
//     Apr, May, Jun,
//     Jul, Aug, Sep, 
//     Oct, Nov, Dec
// };

//Jan = 0, and will be incremented to 1 by default


// enum class Month{
//     Jan = 1, Feb, Mar, 
//     Apr, May, Jun,
//     Jul, Aug, Sep, 
//     Oct, Nov, Dec
// };

//Jan = 1(we specified), and will be incremented to 1 by default


//can't specify a bigger value than the range of int
//hence Jul = 3'000'000'000 will throw an compiler error
enum class Month{
    Jan = 1, Feb, Mar, 
    Apr, May, Jun,
    Jul = 20, Aug, Sep, 
    Oct, Nov, Dec
};

//Jan = 1(we specified), and will be incremented to 1 by default
//Jul = 20(we specified), and will be incremented to 1 for next ones
//hence, Aug = 21, and so on


int main()
{
    Month month {Month::Feb};


    //CAN'T be printed directly
    // cout << month << endl;

    //CAN be printed after casting to an integer
    cout << static_cast<int>(month) << endl;
    
    //size of month will be 4, because the default type associated with month is int,
    //however this can be changed

    cout << "Size(month): " << sizeof(month) << endl; //4
}