#include <bits/stdc++.h>
#define IO ios_base::sync_with_stdio(0), cin.tie(nullptr)
#define int long long

using namespace std;

int findmx(int a){
	int mx = -1;
	while(a){
		int dig = a % 10;
		a /= 10;
		mx = max(mx, dig);
	}
	return mx;
}

signed main(){
	int in, ans = 0;
	cin >> in;
	while(in>0){
		in -= findmx(in);
		++ans;
	}
	cout << ans << '\n';
}