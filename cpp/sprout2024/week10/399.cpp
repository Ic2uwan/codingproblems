#include <bits/stdc++.h>
#define IO ios_base::sync_with_stdio(false), cin.tie(nullptr)
#define ll long long
#define pll pair<ll, ll>
#define xx first
#define yy second

using namespace std;

ll dis(pll &fst, pll &snd){
	return ((fst.xx - snd.xx)*(fst.xx - snd.xx) + (fst.yy - snd.yy)*(fst.yy - snd.yy));
}
map<ll, ll> mp;
pll vp[1005];
ll cnt[1000000];
int main(){
	IO;
	ll ans = 0;
	memset(cnt, 0, sizeof(cnt));
	int N;
	cin >> N;
	for(int i = 0, a, b; i < N; ++i){
		cin >> a >> b;
		vp[i] = {a, b};
	}
	ll idx = 0;
	for(int i = 0; i < N; ++i){
		for(int j = i+1; j < N; ++j){
			ll dist = dis(vp[i], vp[j]);
			++mp[dist];
		}
	}
	for(auto &i : mp){
		ans += ((i.second * (i.second - 1)) >> 1);
	}
	cout << ans << '\n';
}