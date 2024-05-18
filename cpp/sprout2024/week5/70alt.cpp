#include <bits/stdc++.h>
#define IO ios_base::sync_with_stdio(0), cin.tie(nullptr)
#define ll long long
using namespace std;

int main(){
	IO;
	int T;
	cin >> T;
	while(T--){
		int n;
		cin >> n;
		priority_queue<ll, vector<ll>, greater<ll>> num;
		for(int i = 0, a; i < n; ++i){
			cin >> a;
			num.push(a);
		}
		ll cost = 0;
		while(num.size()!=1){
			ll a, b;
			a = num.top();
			num.pop();
			b = num.top();
			num.pop();
			cost += a + b;
			num.push(a+b);
		}
		cout << cost << '\n';
	}
}
