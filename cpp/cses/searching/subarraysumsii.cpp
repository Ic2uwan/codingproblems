#include <bits/stdc++.h>
#define IO ios_base::sync_with_stdio(0), cin.tie(0)
#define int long long

using namespace std;

int arr[200005];
map<int, int> mp;
signed main(){
	IO;
	int n, x;
	int ans = 0;
	cin >> n >> x;
	for(int i = 0; i < n; ++i){
		cin >> arr[i];
	}
	int pfs = 0;
	mp[0] = 1;
	for(int i = 0; i < n; ++i){
		pfs += arr[i];
		ans += mp[pfs - x]; // there exists a subarray to [i] that sums up to x
		mp[pfs]++; 
	}
	cout << ans << '\n';
}