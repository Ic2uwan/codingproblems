#include <bits/stdc++.h>
#define IO ios_base::sync_with_stdio(0), cin.tie(0)
#define int long long
#define eb emplace_back
 
using namespace std;
 
vector<int> node[100005];
int vis[100005];
int par[100005];
vector<int> ans;
int sv, ev;
 
bool dfs(int u, int p){
	vis[u] = 1;
	par[u] = p;
	for(int &a : node[u]){
		if(a==p) continue;
		if(!vis[a]){
			if(dfs(a, u))return true;
		}
		else{
			sv = a;
			ev = u;
			return true;
		}
	}
	return false;
}
signed main(){
	IO;
	int n, m;
	cin >> n >> m;
	int a, b;
	while(m--){
		cin >> a >> b;
		node[a].eb(b);
		node[b].eb(a);
	}
	bool flag = false;
	for(int i = 1; i <= n; ++i){
		if(!vis[i]){
			if(dfs(i, -1)){
				flag = true;
				break;
			}
		}
	}
	if(flag){
		int nv = ev;
		ans.eb(ev);
		while(nv!=sv){
			ans.eb(par[nv]);
			nv = par[nv];
		}ans.eb(ev);
		cout << ans.size() << '\n';
		for(int &a : ans){
			cout << a << ' ';
		}
	}
	else{
		cout << "IMPOSSIBLE\n";
	}
 
}