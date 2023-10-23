#include <bits/stdc++.h>
#define ass ios_base::sync_with_stdio(false); cin.tie(0);
using namespace std;
typedef long long ll;

vector<bool> vs((int)5e5, 0);
vector<vector<int>> node;
stack<int> ns;
vector<int> route;

int main(){
    int n, tmp, tmp2;
    int now;
    cin >> n;
    node.resize(n+1);
    int dist = 0;
    while(--n){
        cin >> tmp >> tmp2;
        node[tmp].emplace_back(tmp2);
    }
    ns.emplace(1);
    while(true){
        dist++;
        bool noedge = 1;
        now = ns.top();
        //if(!vs[now])
        for(auto i : node[now]){
            if(!vs[i]){
                noedge = 0;
                ns.emplace(i);
                break;
            }
        }
        vs[now] = true;
        if(noedge) ns.pop();
        route.emplace_back(now);
        if(ns.empty()){
            cout << dist << '\n';
            for(auto i : route){
                cout << i << ' ';
            }
            break;
        }
    }
}