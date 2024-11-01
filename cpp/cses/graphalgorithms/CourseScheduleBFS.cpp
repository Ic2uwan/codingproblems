#include <bits/stdc++.h>
#define IO ios_base::sync_with_stdio(0), cin.tie(0)

using ll = long long;
using namespace std;


vector<ll> node[100005];
vector<ll> ans;
ll ind[100005];
int main(){
	ll n, m;
	cin >> n >> m;
	ll a, b;
	while(m--){
		cin >> a >> b;
		node[a].emplace_back(b);
		++ind[b];
	}
	queue<ll> nq;
	for(int i = 1; i <= n; ++i){
		if(!ind[i]){
			nq.push(i);
		}
	}
	while(!nq.empty()){
		auto now = nq.front();
		ans.emplace_back(now);
		nq.pop();
		for(ll &i : node[now]){
			if(!(--ind[i])){
				nq.push(i);
			}
		}
	}
	if(ans.size() == n){
		for(auto &i : ans){
			cout << i << ' ';
		}
	}
	else{
		cout << "IMPOSSIBLE";
	}
}