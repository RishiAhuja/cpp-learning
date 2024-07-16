#include <iostream>
#include <string>
#include <cstring>

using namespace std;


void max_str(const char* input1, const char* input2, std::string& output);

int main()
{
    char input1 []{};
    char input2 []{};

    cout << "Enter string literal 1" << endl;
    cin >> input1;

    cout << "Enter string literal 2" << endl;
    cin >> input2;
    // char input12 [] = "Rishi";

    string my_output{};

    max_str(input1, input2, my_output);
    
    cout << my_output << endl;

}

void max_str(const char input1[], const char input2[], string& output){
    
    if (strlen(input1) > strlen(input2))
    {
        output = input1;
    }else{
        output = input2;
    }
    

}
