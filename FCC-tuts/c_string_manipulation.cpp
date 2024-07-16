#include <iostream>
#include <cstring>
using namespace std;

int main()
{

    const char message1[]{"The sky is blue."};

    const char *message2{"The sky is blue."};

    cout << "Message1: " << message1 << endl;

    cout << std::strlen(message1) << endl;

    cout << std::size(message1) << endl; // will also account null character
    cout << sizeof(message1) << endl;    // will also account null terminator

    cout << std::strlen(message2) << endl;
    cout << sizeof(message2) << endl; // will also account null terminator

    // strcmp

    char s1[]{"Alabama"};
    char s2[]{"Alabamb"};

    const char *s3{"Alabama"};
    const char *s4{"Alabama"};

    // const confusion in here::
    /*This means that the contents of the string cannot be modified through
    this pointer, but the pointer can be modified to point to a different string.*/
    // will get an error here: s3[0] = 'a'

    // The std::strcmp() function returns an integer value that indicates the relationship between the two strings:
    // If the return value is less than 0, it means str1 is lexicographically less than str2.
    // If the return value is 0, it means str1 is lexicographically equal to str2.
    // If the return value is greater than 0, it means str1 is lexicographically greater than str2.

    s4 = "Alabamb";

    cout << "std::strcmp(" << s1 << ", " << s2 << "): " << std::strcmp(s1, s2)
         << endl;

    // strncmp

    const char *s5{"aaarishi"};
    const char *s6{"aaabishi"};

    size_t n{3};

    cout << endl;

    // will give 0, because will only compare first 3 characters

    cout << "std::strncmp(" << s5 << ", " << s6 << "): " << std::strncmp(s5, s6, n)
         << endl;



    //strchr 
    //will accept a target and if its finds that target, it will return 
    //a pointer to that target, else will return null pointer
    
    const char *str {"Try not. Do, or do not. There is no Try."};

    char target {'T'};
    const char *result = str;

    // cout << result << endl;
    int iterations{};
// cout << std::strchr(result, target) << endl;
// cout << std::strchr(result + 1, target) << endl;
// cout << std::strchr(result + 2, target) << endl;
// cout << std::strchr(result + 3, target) << endl;
// cout << std::strchr(result, target) << endl;
// cout << std::strchr(result, target) << endl;
    while ((result = std::strchr(result, target)) != nullptr)
    {
        cout << "Found: " << target << " " << result << endl;
        ++result;
        cout << result << endl;
        ++iterations;
    }

    cout << iterations << endl;


    //strrchr

    char adress [] {"/home/rishi/main.cpp"};

    char *output = std::strrchr(adress, '/');

    if(output){
        cout << output << endl;
        cout << output + 1 << endl;
    }else{
        cout << "Can't find" << endl;

    }
       
}