#include <iostream>
using namespace std;

int main(){
    
    int input1 {0};
    int result {0};
    std::cin >> input1;
    
    cout << input1 << endl;
    
    
    for(size_t i{}; i <= input1; ++i){
        
        cout << i << endl;
        result = result + i;
    }
    
    cout << "Final result: " << result << endl;
}