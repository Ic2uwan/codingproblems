#include <bits/stdc++.h>
#define IO ios_base::sync_with_stdio(0), cin.tie(nullptr)
#define int long long
#define mod 1000007
using namespace std;

int dp[100000+5][3][3];

main(){
	IO;
	dp[1][0][0] = dp[1][1][1] = dp[1][2][2] =
    dp[2][0][0] = dp[2][0][1] = dp[2][0][2] =
    dp[2][1][0] = dp[2][1][1] = dp[2][2][0] = dp[2][2][2] = 1;
	dp[2][1][2] = dp[2][2][1] = 0; // illegal
	for(int i = 3; i <= 100000; ++i){
		dp[i][0][0] = (dp[i-1][0][0] + dp[i-1][0][1] + dp[i-1][0][2])%mod;
        dp[i][0][1] = (dp[i-1][0][0] + dp[i-1][0][1])%mod;
        dp[i][0][2] = (dp[i-1][0][0] + dp[i-1][0][2])%mod;
        
        dp[i][1][0] = (dp[i-1][1][0] + dp[i-1][1][1] + dp[i-1][1][2])%mod;
        dp[i][1][1] = (dp[i-1][1][0] + dp[i-1][1][1])%mod;
		dp[i][1][2] = (dp[i-1][1][0] + dp[i-1][1][2])%mod;
        
        dp[i][2][0] = (dp[i-1][2][0] + dp[i-1][2][1] + dp[i-1][2][2])%mod;
        dp[i][2][1] = (dp[i-1][2][0] + dp[i-1][2][1])%mod;
		dp[i][2][2] = (dp[i-1][2][0] + dp[i-1][2][2])%mod;
	}
	int T;
	cin >> T;
	while(T--){
		int n;
		cin >> n;
		cout << (dp[n][0][0] + dp[n][0][1] + dp[n][0][2] +
				 dp[n][1][0] + dp[n][1][1] +
				 dp[n][2][0] + dp[n][2][2])%mod << '\n';
	}
}