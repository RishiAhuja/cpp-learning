#include <iostream>

using namespace std;
int main()
{
    //2D array
    int d1 = 3;
    int d2 = 3;
    // int packages [d1][d2]{
    //     {1, 2, 3},
    //     {4, 5, 6},
    //     {7, 8, 9}

    // }; //12 locations where can store an integer (intialized)

    int packages [][d2]{
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}

    }; //compiler can also omit the first dimention automatically, but not further than that


    //can also autofill values with 0, if they are not up to the mark as provided
    // int packages [][d2]{
    //     {1, 2, 3},
    //     {4, 5, 6},
    //     {7}

    // };
    //will become {
    // ..
    // {7,0,0}
    // }

    //data manipulation;
    //forming a matrix
    for (size_t i{0}; i < d1; i++)
    {
        for (size_t j{}; j < d2; j++)
        {
            // cout << "(" << i << ", " << j << ") : "<<  packages[i][j] << "   ";
            cout <<  packages[i][j] << "   ";
        }
        cout << endl;
    }
    
}