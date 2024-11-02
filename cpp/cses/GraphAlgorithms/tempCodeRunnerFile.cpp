for(ll &a : node[nd]){
		if(!vis[a]){
			vis[a] = 1;
			dfs(a);
		}
	