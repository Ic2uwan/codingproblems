#include <bits/stdc++.h>
#define ass ios_base::sync_with_stdio(false); cin.tie(0);
using namespace std;
typedef long long ll;

vector<bool> vs((int)5e5 + 5, 0);
vector<vector<int>> node;
stack<int> ns;
vector<int> route;

int main(){
    ass
    int n, tmp, tmp2;
    int now;
    cin >> n;
    node.resize(n+5);
    int dist = 1;
    while(--n){
        cin >> tmp >> tmp2;
        node[tmp].emplace_back(tmp2);
    }
    ns.emplace(1);
    
    while(true){
        now = ns.top();
        bool noedge = true;
        for(auto i : node[now]){
            if(!vs[i]){ //if not visited
                noedge = false;
                vs[i] = true;
                ns.emplace(i);
                break;
            }
        }
        if(noedge) ns.pop();
        route.emplace_back(now);
        if(ns.empty()) break;
        dist++;
    }
    cout << dist << '\n';
    for(auto i : route){
        cout << i << ' ';
    }
}