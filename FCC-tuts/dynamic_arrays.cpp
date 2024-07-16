#include <iostream>
using namespace std;

int main (){

    size_t size {10};

    double *p_salaries {new(std::nothrow) double[size]{1, 3, 5, 8, 5, 4, 3, 7, 7, 2}};

    cout << p_salaries << endl;
    cout << *(p_salaries + 1) << endl;
    cout << p_salaries[1] << endl;

    for (size_t i {0}; i < size; i++)
    {
        cout << p_salaries[i] << " : " << *(p_salaries + i) << endl;
    }

    // cout << size(*p_salaries) << endl;

    //releasing array memory

    delete[] p_salaries;
    p_salaries = nullptr;


    //dynamic arrays are diffent form arrays
    //they dont work with std::size 
    //here actually array decays into a pointer


    //cant use range based loops on p_salaries because it is not an array but just a goddamn pointer

}