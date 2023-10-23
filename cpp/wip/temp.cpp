#include <iostream>

int main(){
    int x = 20;
    char y = '\0';
    switch (x) {
        case 10: y = 'a'; break;
        case 20:
        case 30: y = 'b'; break;
        default: y = 'c';
    }
    std::cout << y;
}