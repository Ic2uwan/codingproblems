#include <bits/stdc++.h>
#define IO ios_base::sync_with_stdio(0), cin.tie(0)
#define ll long long

using namespace std;

ll arr[200005];
/*
5
3 1 2 7 4
3 4 6 13 17

4
5 -65 -67 -67
5 -60 -127 -194
    -132

*/
map<ll, ll> prefs;
int main(){
	prefs[0] = 1;
	IO;
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i){
		cin >> arr[i];
	}
	ll pfs = 0;
	ll cnt = 0;
	for(int i = 0; i < n; ++i){
		pfs += arr[i];
		pfs %= n;
		cnt += prefs[(pfs+n)%n]++;
	}
	cout << cnt << '\n';
}