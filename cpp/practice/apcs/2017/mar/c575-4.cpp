#include <bits/stdc++.h>
using namespace std;


int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int mx = 0, mn = -1;
	int n, k;
	cin >> n >> k;
	int a;
	for(int i = 0; i < n; i++){
		cin >> a;
		if(mn == -1) mn = a;
		mx = max(mx, a);
		mn = min(mn, a);
	}
	cout << mx << '-' << mn << '=' << mx-mn;
	int ans = (mx-mn) / (k * 2);
	cout << ans << '\n';
}
