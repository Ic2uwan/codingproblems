#include <iostream>
#include <algorithm>
int main(){
    int n;
    std::cin >> n;
    int arr[n];
    int cost = 0;
    for(int i = 0; i < n; i++)std::cin >> arr[i];
    for(int i = 0; i < n; i++){
        if(arr[i] == 0){
            if(i - 1 == -1)cost += arr[i+1];
            else if(i + 1 == n)cost += arr[i-1];
            else cost += std::min(arr[i-1], arr[i+1]);
        }
    }
    std::cout << cost;
}