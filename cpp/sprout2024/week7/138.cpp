#include <bits/stdc++.h>
#define IO ios_base::sync_with_stdio(0), cin.tie(nullptr)
#define int long long
#define mod 1000007
using namespace std;

int dp[100000+5];

signed main(){
	IO;
	int T;
	cin >> T;
	memset(dp, 0, sizeof(dp));
	int N;
	dp[2] = 3;
	dp[4] = (dp[2] * 4) - 1;
	for(int i = 6; i <= 100000; i+=2){
		dp[i] = ((dp[i-2] * 4)%mod  - (dp[i-4]) + mod) % mod;
	}
	while(T--){
		cin >> N;
		cout << dp[N] << '\n';
	}		
}