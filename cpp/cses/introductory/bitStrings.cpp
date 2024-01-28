#include <bits/stdc++.h>
#define ioopti ios_base::sync_with_stdio(false), cin.tie(nullptr);
using namespace std;
using ll = long long;
#define mod (ll)1e9+7

int main(){
	ioopti
	int n;
	cin >> n;
	ll ans = 2;
	for(int i = 1; i < n; i++){
		ans *= 2;
		ans %= mod;
	}
	cout << ans;
}
