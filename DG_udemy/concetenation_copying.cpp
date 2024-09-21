#include <iostream>
#include <cstring>

using namespace std;

int main ()
{  
    char desc [50] = "Hello ";
    char src [50] = "World";

    cout << desc << endl;
    cout << src << endl;
    
    std::strcat(desc, src);

    cout << desc << endl;
    cout << src << endl;

    char *dest1 = new char [30]{'F', 'i', 'r', 'e', 'l', 'o', 'r', 'd', '\0'};
    char *source1 = new char[30]{',',' ','T','h','e',' ','P','h','e','n','i','x',' ','K','i','n','g','!','\0'};

    std::strcat(dest1, source1);

    cout << dest1 << endl;

    delete [] dest1, source1;
    dest1, source1 = nullptr;
    //strncat

    char dest3 [50] {"Hello"};
    char source3[50] {" There is a bird in my window"};

    std::strncat(dest3, source3, 6);

    cout << dest3 << endl;


    //strcpy

    const char *src4 {"Hello"};
    char *dest4 = new char[std::strlen(src4) + 1]{};

    std::strcpy(dest4, src4);


    cout << dest4 << endl;

}   

