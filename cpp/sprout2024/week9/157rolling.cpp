#include <bits/stdc++.h>
#define IO ios_base::sync_with_stdio(0), cin.tie(nullptr)
#define ll long long
using namespace std;

int a[100], b[100];
int dp[2][1000005];
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
		for(int i = 0; i < n; ++i){
			for(int j = 0; j <= m; ++j){
				if(j < a[i]){
					dp[(i+1)%2][j] = dp[(i)%2][j];
				}
				else{
					dp[(i+1)%2][j] = max(dp[(i)%2][j],
									     dp[(i)%2][j-a[i]] + b[i]);
				}
				//cout << dp[(i+1)%2][j] << ' ';
			}
			//cout << '\n';
		}
		cout << dp[(n)%2][m] << '\n';
	}
}