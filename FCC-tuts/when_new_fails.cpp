#include <iostream>

int main ()
{

    // int *data = new int [10000000000000000];
    //here new failed
    //ran out of heap memory

    // for (size_t i{0}; i < 1000000000; ++i)
    // {
    //     int *data = new int[1000000000];
    // }


    //exception mechanism

    // try{
    // //potentially going to fail
    //     int *data = new int [10000000000000000];
    // }catch(std::exception& ex){
    //     std::cout << "Lol crashed: " << ex.what() << std::endl;
    // }

    
    //std::nothrow

    //if new fails, we will recieve nullptr in data;
    int *data = new(std::nothrow) int[1000000000000];

    if(data!=nullptr){
        std::cout << "pointer adressed successfully" << std::endl;
    }else{
        std::cout << "can't allocate memory" << std::endl;
    }

    std::cout << "Program ending well" << std::endl;
    
}