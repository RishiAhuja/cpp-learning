#include <iostream>
#include <cstring>

using namespace std;

  
int main(int argc, char* argv[])
{
    if(argc != 4){
        cerr << "| Invalid input |" << endl;
        cerr << "Input format: program_name a + b (with spaces)" << endl;
        cerr << "You called with: " << endl;

        for (size_t i{}; i < argc; i++)
        {
            cout << " " << argv[i];
        }
        cout << endl;
        return 0;
    }

    //correct numbers of parameters

    double first_number {atof(argv[1])}; //converts character pointer into a floating point value
    double second_number {atof(argv[3])};

    if ((first_number == 0.0) || (second_number == 0.0)){
        cout <<  "Please use valid numbers. (zeros are not allowed)" << endl;
        return 0;
    }


    //Grabbing th operation

    const char* operation {argv[2]};
    char c;

    if(
        (strlen(operation) == 1) &&
        (
            (operation[0] == '+') || 
            (operation[0] == '-') || 
            (operation[0] == 'x') || 
            (operation[0] == '/')
        )

    ){
        c = operation[0];
    }else{
        cerr << "Invalid operation provided: Valid operations are, [+][-][x][/]" << endl;
        return 0;
    }

    switch (c)
    {
    case '+':
        cout << first_number << " + " << second_number << " = "<<
        first_number + second_number << endl;
        break;
    case '-':
        cout << first_number << " - " << second_number << " = "<<
        first_number - second_number << endl;
        break;
    case 'x':
        cout << first_number << " x " << second_number << " = "<<
        first_number * second_number << endl;
        break;
    case '/':
        cout << first_number << " / " << second_number << " = "<<
        first_number / second_number << endl;
        break;
    
    default:
        cerr << "Invalid character" << endl;
        break;
    }
    
    return 0;
}