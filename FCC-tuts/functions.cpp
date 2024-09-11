#include <iostream>

using namespace std;

void enter_bar(unsigned int age)
{

    (age >= 18) ? cout << "Allowed, Age: " << age << endl : cout << "Not allowed" <<  endl;
}

int max(int a, int b){
    if(a>b){return a;}else{return b;}

    //the variables a, b which are inputted are just copies, doing operations or incrementing this inside 
    //the function doesnot changes the original variables, they get get killed when the scope of the function 
    //is ended.
}


double accepting_array(double (&scores)[10])
{

}

//seperating function headers

int max2_func (int a, int b);
// function deleration or prototype or signature
//initialized here;

//declaration doesnot cares about, input variables
//so this is also valid

//int max(int, int);


int main()
{
    // for (size_t i{1}; i < 30; i++)
    // {
    //     enter_bar(i);
    // }

    int max_number {max(10, 20)};
    int max2 {max(90, 4)};
    cout << max_number << max2 <<endl;

    return 0;
}

//wrote the logic here;
//function defination

int max2_func(int a, int b){
    if(a>b){return a;} else{return b;}
}