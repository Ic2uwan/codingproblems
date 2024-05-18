#include <bits/stdc++.h>
#define IO ios_base::sync_with_stdio(0), cin.tie(nullptr)
#define int long long
using namespace std;

int arr[100000];
int dp[100000]; // dp[i] : last added digit is arr[i]

signed main(){
	IO;
	int T;
	cin >> T;
	while(T--){
		memset(dp, 0, sizeof(dp));
		int N, k;
		cin >> N >> k;
		for(int i = 0; i < N; ++i){
			cin >> arr[i];
		}
		for(int i = 0; i < k; ++i){
			dp[i] = arr[i];
		}
		for(int i = k; i < 2*k; ++i){
			dp[i] = arr[i] + *max_element(arr, arr+i-k+1);
		}
		for(int i = 2*k; i < N; ++i){
			dp[i] = arr[i] + *max_element(dp+i-(2*k), dp+i-k+1);
		}
		cout << *max_element(dp, dp+N+1) << '\n';
	}
}
