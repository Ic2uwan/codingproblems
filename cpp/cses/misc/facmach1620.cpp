#include <bits/stdc++.h>
#define IO ios_base::sync_with_stdio(0), cin.tie(0)
#define int long long

using namespace std;


int n, t;
int a[200000];

int bs(int l, int r){
	if(l >= r) return l;
	int m = (l + r) / 2;
	int sum = 0;
	for(int i = 0; i < n; ++i){
		sum += m / a[i];
	}
	if(sum >= t){
		return bs(l, m);
	}else{
		return bs(m+1, r);
	}
}

signed main(){
	IO;
	cin >> n >> t;
	for(int i = 0; i < n; ++i){
		cin >> a[i];
	}
	sort(a, a+n);
	int mx = a[0] * t;

	int ans = bs(1, mx);
	cout << ans << '\n';

}