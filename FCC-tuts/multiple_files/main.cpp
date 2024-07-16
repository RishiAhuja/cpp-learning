#include <iostream>
#include "compare.h" //Preproceesor adding compare.h's declaration to the main file before pushing this to the compiler

using namespace std;

int main ()
{
    int maximum = max(100, 10);
    int minimum = min(100, 10);

    cout << maximum << " " << minimum << endl;

    return 0;
}