#include <bits/stdc++.h>
#define IO ios_base::sync_with_stdio(0), cin.tie(nullptr)
#define int long long
#define rep(a, b) for(int i = a; i < b; ++i)
#define rep2(a, b) for(int j = a; j < b; ++j)


using namespace std;

int grd[1000][1000];
int dp[1000][1000];
const int MOD = 1e9+7;

void calcpth(int y, int x){
	if(grd[y][x] == -1){
		dp[y][x] = 0;
		return;
	}
	if(y - 1 >= 0){
		dp[y][x] += dp[y - 1][x];
	}
	if(x - 1 >= 0){
		dp[y][x] += dp[y][x - 1];
	}
	dp[y][x] %= MOD;
}

signed main(){
	IO;
	int n;
	cin >> n;
	rep(0, n){
		rep2(0, n){
			char a;
			cin >> a;
			if(a=='*')
				grd[i][j] = -1;
		}
	}
	dp[0][0] = 1;
	rep(0, n){
		// base = grd[i][i]
		calcpth(i, i);
		for(int dy = 1; i + dy < n; ++dy){
			calcpth(i + dy, i);
		}
		for(int dx = 1; i + dx < n; ++dx){
			calcpth(i, i + dx);
		}
	}
	cout << dp[n-1][n-1] << '\n';
}