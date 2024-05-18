#include <bits/stdc++.h>
#define IO ios_base::sync_with_stdio(0), cin.tie(nullptr)
#define ll long long
using namespace std;

int a[100], b[100];
int dp[1005][105]; // dp[hp][cnt]
int main(){
	IO;
	int T;
	cin >> T;
	while(T--){
		memset(dp, 0, sizeof(dp));
		int n, m, k;
		cin >> n >> m >> k;
		for(int i = 0; i < n; ++i){
			cin >> a[i] >> b[i];
		}
		for(int i = 0; i < n; ++i){
			for(int j = m; j >= a[i]; --j){
				for(int o = 1; o <= k; ++o){
					dp[j][o] = max(dp[j][o], dp[j - a[i]][o-1] + b[i]);
				}
			}
		}
		cout << dp[m][k] << '\n';
	}
}