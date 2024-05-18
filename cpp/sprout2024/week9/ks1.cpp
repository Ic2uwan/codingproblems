#include <bits/stdc++.h>
#define IO ios_base::sync_with_stdio(0), cin.tie(nullptr)
#define ll long long
using namespace std;

int a[100], b[100];
int dp[2][10000000];
int main(){
	IO;
	int T;
	cin >> T;
	while(T--){
		memset(dp, -1, sizeof(dp));
		int n, m;
		cin >> n >> m;
		for(int i = 0; i < n; ++i){
			cin >> a[i] >> b[i];
		}
		dp[0][0] = 0;
		for(int j = m; j >= 0; --j){
			if(j < a[0]){
				dp[0][j] = 0;
			}
			else{
				dp[0][j] = b[0];
			}
		}
		for(int i = 1; i < n; ++i){
			for(int j = m; j >= 0; --j){
				if(j < a[i]){
					dp[(i)%2][j] = dp[(i+1)%2][j];
				}
				else{
					dp[(i)%2][j] = max(dp[(i+1)%2][j],
									   dp[(i+1)%2][j-a[i]] + b[i]);
				}
			}
		}
		cout << dp[(n-1)%2][m] << '\n';
	}
}