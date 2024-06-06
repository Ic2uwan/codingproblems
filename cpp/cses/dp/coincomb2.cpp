#include <bits/stdc++.h>
#define IO ios_base::sync_with_stdio(0), cin.tie(nullptr)
#define int long long


const int MOD = 1e9+7;

using namespace std;
int c[100];
int dp[1000005];
// dp[n] += dp[n-c[i]]
signed main(){
	IO;
	int n, x;
	cin >> n >> x;
	fill(dp, dp+1000005, 0);
	for(int i = 0; i < n; ++i){
		cin >> c[i];
	}
	sort(c, c+n);
	reverse(c, c+n);
	for(int j = 0; j < n; ++j){
		dp[c[j]] = 1;
		for(int i = 1; i <= x; ++i){
			if(i - c[j] > 0){
				dp[i] += dp[i - c[j]];
				dp[i] %= MOD;
			}
		}
	}
	cout << dp[x] << '\n';
	// for(int i = 0; i <= x; ++i){
	// 	cout << dp[i] << ' ';
	// }
}