#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> ass;
    ass.reserve(60000);
    for(size_t i = 0; i < 60000; i++){
        ass[i] = i;
        cout << ass[i];
    }
}