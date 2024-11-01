#include <bits/stdc++.h>
#define IO ios_base::sync_with_stdio(0), cin.tie(0)

using ll = long long;
using namespace std;

ll arr[200005];
ll n, k; // k = max div

bool check(ll tar){
	ll cnt = 0;
	ll sum = 0;
	for(int i = 0; i < n; ++i){
		if(arr[i] > tar) return 0;
		if(sum + arr[i] > tar){
			sum = 0;
			++cnt;
		}
		sum += arr[i];
	}
	return (cnt < k);
}
int main(){
	cin >> n >> k;
	for(int i = 0; i < n; ++i){
		cin >> arr[i];
	}
	ll l = 0, r = INT64_MAX;
	ll mid;
	while(l < r){
		mid = (r + l) / 2;
		// cout << l << ' ' << r << '\n';
		if(check(mid)){
			r = mid;
		}
		else{
			l = mid+1;
		}
	}
	cout << l << '\n';
}