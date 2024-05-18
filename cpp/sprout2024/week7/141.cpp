#include <bits/stdc++.h>
#define IO ios_base::sync_with_stdio(0), cin.tie(nullptr)
#define int long long
using namespace std;

int arr[100000];
int dp[100000];

signed main(){
	IO;
	int T;
	cin >> T;
	while(T--){
		int N;
		cin >> N;
		for(int i = 0; i < N; ++i){
			cin >> arr[i];
		}
		dp[0] = arr[0];
		dp[1] = arr[1];
		dp[2] = arr[2] + arr[0];
		for(int i = 3; i < N; ++i){
			dp[i] = max(dp[i-3], dp[i-2]) + arr[i];
		}
		cout << max(dp[N-1], dp[N-2]) << '\n';
	}
}