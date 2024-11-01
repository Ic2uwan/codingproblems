#include <bits/stdc++.h>
#define IO ios_base::sync_with_stdio(0), cin.tie(0)
#define int ll
using namespace std;
using ll = long long;

int n, q;
int arr[200005], pf[200005];
signed main(){
    IO;
    cin >> n >> q;
	cin >> arr[0];
	pf[0] = arr[0];
    for(int i = 1; i < n; ++i){
        cin >> arr[i];
		pf[i] = arr[i] + pf[i-1];
    }
	int l, r;
	while(q--){
		cin >> l >> r;
		cout << pf[r-1] - pf[l-2] << '\n';
	}
}