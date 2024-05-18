#include <bits/stdc++.h>
#define IO ios_base::sync_with_stdio(false), cin.tie(nullptr)
#define ll long long
#define mul ((ll)(1e9))

using namespace std;

ll v[500];
map<ll, ll> mp;
int main(){
	IO;
	int N;
	ll ans = 0;
	memset(v, 0, sizeof(v));
	cin >> N;
	string str;
	for(int i = 0; i < N; ++i){
		cin >> str;
		for(int j = 2; j <= 10; ++j){
			v[i] += (str[j] - '0') * powl(10, 10-j);
		}
		mp[v[i]]++;
	}
	for(int i = 0; i < N; ++i){
		for(int j = 0; j < N; ++j){
			if(mp.count(v[i]+v[j])){
				ans += mp[v[i]+v[j]];
			}
		}
	}
	cout << ans << '\n';
}