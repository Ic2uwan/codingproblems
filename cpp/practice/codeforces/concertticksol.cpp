#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m, h;
    cin >> m >> n;
    multiset<int> ms; ms.clear();
    multiset<int>::iterator it;
    while(n--){
        cin >> h;
        ms.insert(h);
    }
    while(m--){
        cin >> h;
        it = ms.lower_bound(h);
        if(*it == h){
            cout << h << '\n';
            ms.erase(h);
        }
        else if(it != ms.begin()){
            --it;
            cout << *it << '\n';
            ms.erase(it);
        }
        else{
            cout << -1 << '\n';
        }
    }
}