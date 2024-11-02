#include <bits/stdc++.h>
#define IO ios_base::sync_with_stdio(0), cin.tie(0)
#define int long long

using namespace std;

int arr[200005];
int ps[200005];
signed main(){
	IO;
	int n, x;
	int ans = 0;
	cin >> n >> x;
	for(int i = 0; i < n; ++i){
		cin >> arr[i];
	}
	// ps[0] = 0;
	for(int i = 1; i <= n; ++i){
		ps[i] = ps[i-1] + arr[i-1];
	}
	for(int i = 0; i <= n-1; ++i){
		for(int j = i+1; j <= n; ++j){
			if(ps[j] - ps[i] == x){
				++ans;
			}
		}
	}
	cout << ans << '\n';
}