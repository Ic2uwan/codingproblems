#include <bits/stdc++.h>
#define IO ios_base::sync_with_stdio(0), cin.tie(0)
#define int long long

using namespace std;

int arr[200005];
signed main(){
	IO;
	int n, x;
	int ans = 0;
	cin >> n >> x;
	for(int i = 0; i < n; ++i){
		cin >> arr[i];
	}
	int r = 0, l = 1;
	int sum = arr[0];
	while(l <= n){
		if(sum == x){
			// cout << r << ' ' << l << '\n';
			++ans;
			sum += arr[l];
			++l;
			sum -= arr[r];
			++r;
		}
		else if(sum < x){
			sum += arr[l];
			++l;
		}
		else if(sum > x){
			sum -= arr[r];
			++r; 
		}
	}
	cout << ans << '\n';
}