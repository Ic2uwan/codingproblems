#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define f first 
#define s second

vector<pair<ll, ll>> nums;
ll g; //goal
ll n;

auto find(ll id){
    for(int i = 0; i < n; i++){
        
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> g >> n;
    ll in;
    for(int i = 0; i < n; i++){
        cin >> in;
        nums.push_back({in, (ll)i + 1});
    }
    sort(nums.begin(), nums.end());

}