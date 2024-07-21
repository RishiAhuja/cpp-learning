#include <iostream>
#include <bitset>

using namespace std;

int main()
{
    unsigned short int data {15};

    // cout << "data(dec): " << dec << data << endl;
    // cout << "data(hex): " << hex << data << endl;
    // cout << "data(bin): " << bitset<16>(data) << data << endl;

    unsigned short int value {0xff0u};

    // cout << "Size of short int: " << sizeof(short int) << endl; //2

    cout << "Value: " << bitset<16>(value) << ", dec: " << value << endl;
 
    // auto val = (value >> 1);
    
    // cout << "Val size: " << sizeof(val) << ", after shifting :" << val << endl; //4

    // //can't perform this operation for typenames less than 4bytes of size
    // //hence val is auto converted to int from short int via compiler

    auto val = static_cast<unsigned short int>(value << 1);
    cout << "Value: " << bitset<16>(val) << ", dec: " << val << endl;

    /*
    Value: 0000111111110000, dec: 4080
    Value: 0001111111100000, dec: 8160
    */

   /*
   rule for conversion: 

   while left shifting: multiply by 2^n (n = number of shifts)
   while right shifting: divide by 2^n (n = number of shifts)
   
   will only work until you pop off a 1
   */

    val = static_cast<unsigned int>(val << 1);
    cout << "Value: " << bitset<16>(val) << ", dec: " << val << endl;
    val = static_cast<unsigned short int>(val << 1);
    cout << "Value: " << bitset<16>(val) << ", dec: " << val << endl;
    val = static_cast<unsigned short int>(val << 1);
    cout << "Value: " << bitset<16>(val) << ", dec: " << val << endl;
    //achived max value, and no left padded 0s left now.
    //If we move this again, we will pop off an one.

    //Hence we will losse one bit from the following.

    val = static_cast<unsigned short int>(val << 1);
    cout << "Value: " << bitset<16>(val) << ", dec: " << val << endl;
    /*
    Value: 0000111111110000, dec: 4080
    Value: 0001111111100000, dec: 8160
    Value: 0011111111000000, dec: 16320
    Value: 0111111110000000, dec: 32640
    Value: 1111111100000000, dec: 65280
    Value: 1111111000000000, dec: 65024
    */

    //if we again move to right, after poping that 1. we can't restore that. we will get a 0

    //we can also shift directly by value << 4, etc..

    val = static_cast<unsigned short int>(val >> 4);
    cout << "Value: " << bitset<16>(val) << ", dec: " << val << endl;

}