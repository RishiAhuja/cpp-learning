#include <iostream>

using namespace std;

int main()
{
    int entry {};
    bool if_prime = true;

    cout << "Enter number: " << endl;
    cin >> entry;

    for (size_t i{2}; i < entry; i++)
    {
        if(entry%i == 0){
            if_prime = false;
        }
    }

    if(if_prime){
        cout << "Prime number" << endl;
    }else{
        cout << "Not a prime number" << endl;
    }
}

// #include <iostream>
// using namespace std;

// int main()
// {

//     int a;
//     cout << "enter : \n";
//     cin >> a;
//     int i{2};
//     while (i < a)
//     {
//         if (a % i == 0)
//         {
//             cout << "Not a prime number" << endl;
//             break;
//         }
//         else
//         {
//             i++;
//         }
//     }
//     if (i == a)
//     {
//         cout << "Is Prime" << endl;
//     }
//     return 0;
// }

/*maza aaeya thakur bhai*/