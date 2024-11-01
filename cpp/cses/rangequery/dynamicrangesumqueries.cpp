#include <bits/stdc++.h>
#define IO ios_base::sync_with_stdio(0), cin.tie(0)
#define int ll

using namespace std;
using ll = long long;

int lowbit(int x){
    return x & -x;
}
int n, q;
int arr[200005], bit[200005];

void update(int x, int val){
    for(; x <= n; x += lowbit(x)){
        bit[x] += val;
    }
}
int query(int x){
    int sum = 0;
    for(; x > 0; x -= lowbit(x)){
        sum += bit[x];
    }
    return sum;
}

signed main(){
    IO;
    cin >> n >> q;
    for(int i = 1; i <= n; ++i){
        cin >> arr[i];
        update(i, arr[i]);
    }
    int a, b, c;
    while(q--){
        cin >> a >> b >> c;
        if(a == 1){
            int diff = c - arr[b]; // update value
            arr[b] = c;
            update(b, diff);
        }else{
            cout << query(c) - query(b-1) << '\n';
        }
    }
}