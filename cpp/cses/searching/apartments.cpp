#include <bits/stdc++.h>
#define IO ios_base::sync_with_stdio(0), cin.tie(0)
#define ll long long
using namespace std;

ll app[200005];
ll ap[200005];
int main(){
	IO;
	ll n, m, k;
	ll cnt = 0;
	cin >> n >> m >> k;
	for(int i = 0; i < n; ++i){
		cin >> app[i];
	}
	for(int i = 0; i < m; ++i){
		cin >> ap[i];
	}
	sort(app, app+n);
	sort(ap, ap+m);
	// two pointers
	ll i = 0, j = 0;
	while(i < n && j < m){
		if(abs(app[i] - ap[j]) <= k){
			++i;
			++j;
			++cnt;
		}
		else if(app[i] + k < ap[j]){
			++i;
		}
		else{
			++j;
		}
	}
	cout << cnt << '\n';
}