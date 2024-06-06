#include <bits/stdc++.h>
#define int long long
#define IO ios_base::sync_with_stdio(0), cin.tie(0)

using namespace std;

int indeg[100000];

signed main(){
	IO;
	int T;
	cin >> T;
	while(T--){
		vector<int> edge[100000];
		priority_queue<int, vector<int>, greater<int>> pq;
		vector<int> ans;
		memset(indeg, 0, sizeof(indeg));
		int n, m, a, b;
		cin >> n >> m;
		for(int i = 0; i < m; ++i){
			cin >> a >> b;
			edge[a].emplace_back(b);
			++indeg[b];
		}
		for(int i = 0; i < n; ++i){
			if(indeg[i] == 0)
				pq.push(i);
		}
		while(!pq.empty()){
			int cur = pq.top();
			// cout << cur << '\n';
			pq.pop();
			for(auto k : edge[cur]){
				if(--indeg[k] == 0){
					pq.push(k);
				}
			}
			ans.emplace_back(cur);
		}
		if(ans.size()==n){
			for(int i = 0; i < n-1; ++i){
				cout << ans[i] << ' ';
			}
			cout << ans[n-1] << '\n';
		}
		else{
			cout << "QAQ\n";
		}
	}
}