#include <bits/stdc++.h>
#define ioopti ios_base::sync_with_stdio(false), cin.tie(nullptr);
using namespace std;
using ll = long long;

int main(){
	ioopti
	ll n, sum;
	cin >> n;
	sum = (1+n)*n/2;
	if(sum % 2 == 0) cout << "YES\n";
	else{
		cout << "NO\n";
		return 0;
	}
	vector<ll> firstv, secondv;
	ll fs = 0, ss = 0;
	for(ll i = n; i > 0; i--){
		if(fs > ss){
			ss += i;
			secondv.emplace_back(i);
		}
		else{
			fs += i;
			firstv.emplace_back(i);
		}
	}
	cout << firstv.size() << '\n';
	for(ll i : firstv)
		cout << i << ' ';
	cout << '\n';
	cout << secondv.size() << '\n';
	for(ll i : secondv)
		cout << i << ' ';
	cout << '\n';
}
