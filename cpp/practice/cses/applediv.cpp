#include <bits/stdc++.h>
typedef long long ll;
using namespace std;


array<ll, 20 + 5> p;
ll n;
ll ans;
ll total = 0, sum = 0;



void f(int i){

    if(i == n){
        ans = min(abs(total - sum - sum), ans);
        return;
    }

    sum += p[i];
    f(i + 1);
    sum -= p[i];
    f(i + 1);
    return;
}



int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> p[i];
        total += p[i];
    }
    ans = total;
    f(0);
    cout << ans;

}