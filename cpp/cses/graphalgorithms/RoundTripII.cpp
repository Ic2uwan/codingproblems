#include <bits/stdc++.h>
#define IO ios_base::sync_with_stdio(0), cin.tie(0)

using ll = long long;
using namespace std;


vector<ll> node[100005];
vector<ll> cycle;
ll idx[100005];
bool vis[100005];
bool on_cycle[100005];

void dfs(ll nd){
	for(ll &a : node[nd]){
		if(!vis[a]){
			vis[a] = 1;
			dfs(a);
		}
	}
	cycle.emplace_back(nd);
}

int main(){
	ll n, m;
	cin >> n >> m;
	ll a, b;
	while(m--){
		cin >> a >> b;
		node[a].emplace_back(b);
	}
	for(int i = 1; i <= n; ++i){
		if(!vis[i]){
			vis[i] = 1;
			dfs(i);
		}
	}
	reverse(cycle.begin(), cycle.end());
	// timestamp
	for(int i = 0; i < n; ++i){
		idx[cycle[i]] = i;
	}
	bool valid = 1;
	for(int i = 1; i <= n; ++i){
		for(ll &j : node[i]){
			if(idx[j] <= idx[i]){
				valid = 0;
				break;
			}
		}
		if(!valid) break;
	}
	if(valid){
		for(ll &a : cycle){
			cout << a << ' ';
		}
	}
	else{
		cout << "IMPOSSIBLE\n";
	}
}