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

//flexibility
// enum class Month{
//     Jan = 1, January = Jan, Feb, Mar, 
//     Apr, May, Jun,
//     Jul = 20, Aug, Sep, 
//     Oct, Nov, Dec
// };

//both jan and january can be used now


//datatype can also be changed via abstraction
// enum class Month : unsigned char{
//     Jan = 1, January = Jan, Feb, Mar, 
//     Apr, May, Jun,
//     Jul = 20, Aug, Sep, 
//     Oct, Nov, Dec
// };

//using enum

// std::string_view month_to_string(Month month){
    // switch (month)
    // {
        
        // case Month::Jan : return "January";
        // case Month::Feb : return "February";
        // case Month::Mar : return "March";
        // case Month::Apr : return "April";
        // case Month::May : return "May";
        // case Month::Jun : return "June";
        // case Month::Jul : return "July";
        // case Month::Aug : return "August";
        // case Month::Sep : return "September";
        // case Month::Oct : return "October";
        // case Month::Nov : return "November";
        // case Month::Dec : return "December";
        // default : return "None";
        
    //    using enum Month;
    //     case Jan : return "January";
    //     case Feb : return "February";
    //     case Mar : return "March";
    //     case Apr : return "April";
    //     case May : return "May";
    //     case Jun : return "June";
    //     case Jul : return "July";
    //     case Aug : return "August";
    //     case Sep : return "September";
    //     case Oct : return "October";
    //     case Nov : return "November";
    //     case Dec : return "December";
    //     default : return "None";
    // }

// }


//legacy enums

enum Tool {
    Marker, Pen, Pencil
};

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

    //intializing legacy enums
    Tool tool{Tool::Pen};

    //type aliases

    unsigned long long int huge_number {230'766'777'899'222ull};

    //a type alias can be made

    using HugeInt = unsigned long long int;

    HugeInt huge_int {230'766'777'899'222ull};

    //legacy method using typedef

    typedef unsigned long long int HugeInt2;

    HugeInt2 huge_int2 {230'766'777'899'222ull};

}