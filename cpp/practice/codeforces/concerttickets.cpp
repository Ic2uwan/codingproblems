//#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>

using ll = long long;
using namespace std;

multiset<int> p;
//queue<ll> aff;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    int a;

    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> a;
        p.emplace(a);
    }
    //sort(p.begin(), p.end());
    for(int i = 0; i < m; i++){
        cin >> a;
        //aff.emplace(a);
        auto itr = p.lower_bound(a);
        if(*itr == a){
            cout << a << '\n';
            p.erase(itr);
        }
        else if(itr != p.begin()){
            --itr;
            cout << *itr << '\n';
            p.erase(itr);
        }
        else{
            cout << -1 << '\n';
        }
    }
}