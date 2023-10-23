#include <iostream>
int factorial(int x){
    if(x > 1){
        return x * factorial(x-1);
    }
    else{
        return 1;
    }
}
int main(){
    std::cout << factorial(10);
    return 0;
}