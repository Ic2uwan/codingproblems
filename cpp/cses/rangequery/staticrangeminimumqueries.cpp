#include <bits/stdc++.h>
#define IO ios_base::sync_with_stdio(0), cin.tie(0)

using namespace std;
using ll = long long;

int n, q;
int arr[200005], mn[200005][20];
int main(){
    IO;
    cin >> n >> q;
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }
    for(int i = 0; i < n; ++i){
        mn[i][0] = arr[i];
    }
	for(int j = 1; (1<<j) <= n; ++j){
		for(int i = 0; i + (1<<j) <= n; ++i){
			mn[i][j] = min(mn[i][j-1], mn[i+(1<<(j-1))][j-1]);
		}
	}
    int l, r;
    while(q--){
        cin >> l >> r;
        l--; r--;
        int sz = __lg(r-l+1);
        cout << min(mn[l][sz], mn[r-(1<<sz)+1][sz]) << '\n';
    }
}