#include <bits/stdc++.h>
using namespace std;
#define IO ios_base::sync_with_stdio(0), cin.tie(nullptr)
#define int long long
int c[100];
int dp[1000005];
signed main(){
	int n, x;
	cin >> n >> x;
	for(int i = 0; i < n; ++i){
		cin >> c[i];
	}
	sort(c, c+n);
	fill(dp, dp+1000005, INT_MAX);
	dp[0] = 0;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j <= x; ++j){
			if(j >= c[i])
				dp[j] = min(dp[j], dp[j-c[i]] + 1);
		}
	}
	cout << (dp[x] == INT_MAX ? -1 : dp[x]) << '\n';
}
