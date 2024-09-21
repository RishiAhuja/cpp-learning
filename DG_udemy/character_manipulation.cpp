#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{

    // cout << std::isblank(' ') << endl;

    char message []{"Hello, My name is Rishi. I am learning c++ and my age is 16"};

    int blank_char{};

    for (size_t i{0}; i < std::size(message); i++)
    {
        if(std::isblank(message[i])){
            cout << "Found an blank character at index: " << i << endl;
            blank_char++;
        }
        else{
            cout << "Not a blank character, index: " << i << endl;
        }
    }
    
    cout << "Total blank characters found: " << blank_char << endl;

    cout << endl;
    cout << "==========================================" << endl;
    cout << endl;

    //for uppercase and lowercase

    int lower_case_char{};
    int upper_case_char{};
    int is_digit{};
    blank_char = 0;

    for (size_t i{0}; i < std::size(message); i++)
    {
        if(std::islower(message[i])){
            cout << "Lower case character found at index: " << setw (5) << i << endl;
            lower_case_char++;
        }else if(std::isupper(message[i])){
            cout << "Upper case character found at index: " << setw (5) << i << endl;
            upper_case_char++;
        }else if(std::isdigit(message[i])){
            cout << "A digit found at index: " << setw (5) << i << endl;
            is_digit++;
        }
        else{
            cout << "Blank character found at index: " << setw (5) << i << endl;
            blank_char++;
        }
    }

    cout << endl;
    cout << "==========================================" << endl;
    cout << endl;

    cout << setw(10) << "Total Upper case characters: " << setw(5) << upper_case_char << endl;
    cout << setw(10) << "Total Lower case characters: " << setw(5) << lower_case_char << endl;
    cout << setw(10) << "Total digit characters: " << setw(5) << is_digit << endl;
    cout << setw(10) << "Total Blank characters: " << setw(5) << blank_char << endl;

    cout << endl;
    cout << "==========================================" << endl;
    cout << endl;

    char original_str [] {"Rishi is learning Character Manipulations in C++"};
    char destination_str [std::size(original_str)];

    for (size_t i{0}; i < std::size(original_str); i++)
    {
        destination_str[i] = std::toupper(original_str[i]);
    }
    
    
    cout << "Original string: " << original_str << endl;
    cout << "Altered string 1: " << destination_str << endl;

    for (size_t i{0}; i < std::size(original_str); i++)
    {
        destination_str[i] = std::tolower(original_str[i]);
    }

    cout << "Altered string 2: " << destination_str << endl;


    //std::isalnum

    cout << std::isalnum('C') << endl;
    cout << std::isalnum('^') << endl;


    // const char message2[]{"Hello, this is an char array"};
    // cout << std::strlen(message2) << endl;
    // cout << std::size(message2) << endl;
    // cout << sizeof(message2) << endl;

}