#include <bits/stdc++.h>
#define IO ios_base::sync_with_stdio(0), cin.tie(nullptr)
#define ll long long
using namespace std;

int a[100], b[100];
int dp[100005];
int main(){
	IO;
	int T;
	cin >> T;
	while(T--){
		for(int i = 0; i < 100005; ++i){
            dp[i] = 1 << 30;
        }
		dp[0] = 0;
		int n, m;
		cin >> n >> m;
		for(int i = 0; i < n; ++i){
			cin >> a[i] >> b[i];
		}
		// dp[n][v] = min(dp[n-1][v], dp[n-1][v-b[n]] + a[n])
		for (int i = 0; i < n; ++i){
			for (int j = 10000; j >= b[i]; --j){
				dp[j] = min(dp[j], dp[j - b[i]] + a[i]);
			}
		}
		int ans = 0;
		for(int i = 0; i <= 10000; ++i){
			// cout << dp[i] << ' ';
			if((dp[i] <= m) && (i > ans)){
				ans = i;
			}
		}
		cout << ans << '\n';
	}
}