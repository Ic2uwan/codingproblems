#include <bits/stdc++.h>
#define IO ios_base::sync_with_stdio(0), cin.tie(nullptr)
#define int long long
#define mod 1000007
using namespace std;
int arr[100];
int dp[100][100]; // dp min cost from [L, R]

main(){
	int T;
	cin >> T;
	while(T--){
		int pf[100];
		int n;
		cin >> n;
		cin >> arr[0];
		pf[0] = arr[0];
		for(int i = 1; i < n; ++i){
			cin >> arr[i];
			pf[i] = pf[i-1] + arr[i];
		}

		for(int len = 2; len <= n; ++len) {
			for(int i = 0; i <= n - len; ++i) {
				int j = i + len - 1;
				dp[i][j] = INT64_MAX;
				for(int k = i; k < j; ++k) {
					int cost = dp[i][k] + dp[k+1][j] + pf[j] - (i == 0 ? 0 : pf[i-1]); // tenary op for prefix sum
					dp[i][j] = min(dp[i][j], cost);
				}
			}
		}
		cout << dp[0][n-1] << '\n';
	}
}