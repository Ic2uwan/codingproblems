#include <bits/stdc++.h>
#define IO ios_base::sync_with_stdio(0), cin.tie(nullptr)
#define int long long
#define rep(a, b) for(int i = a; i < b; ++i)
#define rep2(a, b) for(int j = a; j < b; ++j)
using namespace std;
const int MOD = 1e9+7;

int arr[100005];
int dp[100005][105];

signed main(){
	int n, m;
	cin >> n >> m;
	rep(0, n)
		cin >> arr[i];
	
	if(arr[0]==0){
		rep(1, m+1){
			dp[0][i] = 1;
		}
	}
	else{
		dp[0][arr[0]] = 1;
	}
	
	rep(1, n){
		if(arr[i] == 0){
			rep2(1, m+1){
				dp[i][j] = dp[i][j] + dp[i-1][j];
				dp[i][j] = dp[i][j] + dp[i-1][j-1];
				dp[i][j] = dp[i][j] + dp[i-1][j+1];
				dp[i][j] %= MOD;
			}
		}
		else{
			dp[i][arr[i]] += dp[i-1][arr[i]];
			if(arr[i] - 1 >= 1)
				dp[i][arr[i]] += dp[i-1][arr[i]-1];
			if(arr[i] + 1 <= m)
				dp[i][arr[i]] += dp[i-1][arr[i]+1];
			dp[i][arr[i]] %= MOD;
		}
	}
	int ans = 0;
	rep(1, m+1){
		ans = (ans + dp[n - 1][i]) % MOD;
	}
	cout << ans << '\n';
}