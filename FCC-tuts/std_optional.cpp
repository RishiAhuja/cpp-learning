#include <iostream>
#include <optional>

using namespace std;

int main(int argc, char* argv[])
{
    //Declare and initialize std::optional

    std::optional<int> items{3}; //aka a wrapper around a integer
    std::optional<std::string> name {"Rishi Ahuja"};
    std::optional<double> weight {101.4};

    //Declare and empty intialize 

    std::optional<std::string> dog_name {}; //Intiales to std::nullopt
    std::optional<int> age {std::nullopt};

    //Reading from optional variable
    cout << items.value() << endl;
    /*or*/cout << *items << endl;

    // cout << dog_name.value() << endl; //printing an empty value will crash the program

    if(dog_name.has_value()){
        cout << dog_name.value() << endl;
    }

    //writing stuff
    dog_name = "Fluffy";
}
