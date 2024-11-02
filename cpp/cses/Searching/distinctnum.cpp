#include <bits/stdc++.h>
#define IO ios_base::sync_with_stdio(0), cin.tie(0)
#define ll long long

using namespace std;
int main(){
	ll a, cnt;
	cin >> cnt;
	set<ll> s;
	while(cnt--){
		cin >> a;
		s.emplace(a);
	}
	cout << s.size() << '\n';
}