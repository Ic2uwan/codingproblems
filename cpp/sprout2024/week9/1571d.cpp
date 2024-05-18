#include <bits/stdc++.h>
#define IO ios_base::sync_with_stdio(0), cin.tie(nullptr)
#define ll long long
using namespace std;

int a[100], b[100];
int dp[10000005];
int main(){
	IO;
	int T;
	cin >> T;
	while(T--){
		memset(dp, 0, sizeof(dp));
		int n, m;
		cin >> n >> m;
		for(int i = 0; i < n; ++i){
			cin >> a[i] >> b[i];
		}
		for (int i = 0; i < n; ++i){
			for (int j = m; j >= a[i]; --j){
				dp[j] = max(dp[j], dp[j - a[i]] + b[i]);
			}
		}
		cout << dp[m] << '\n';
	}
}