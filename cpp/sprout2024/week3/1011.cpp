#include <bits/stdc++.h>
#define pii pair<int, int>
#define ff first
#define ss second
#define IO ios_base::sync_with_stdio(0), cin.tie(nullptr)
#define maxn 200005
using namespace std;


vector<int> adj[maxn];
int gen[100005];
int main(){
	IO;
	int T;
	cin >> T;
	while(T--){
		memset(gen, 0, sizeof(gen));
		int n, m;
		cin >> n;
		cin >> m;
		for(int i = 0; i < n; i++) {
        	adj[i].clear();
			// adj[i].shrink_to_fit();
    	}
		for(int i = 0, in1, in2; i < m; ++i){
			cin >> in1 >> in2;
			adj[in1].emplace_back(in2);
			adj[in2].emplace_back(in1);
		}
		// dfs
		bool rb = false;
		for(int i = 0; i < n; ++i){
			stack<int> nxt;
			if(gen[i]==0){
				gen[i] = 1; // assign a color for the root node of this current graph
				nxt.push(i);
				while(!nxt.empty()){
					int now = nxt.top();
					nxt.pop();
					for(auto a : adj[now]){
						if(gen[a] == 0){ 				// if unassigned, assign
							gen[a] = gen[now] * (-1);
							nxt.push(a);
						}
						else if(gen[a] == gen[now]){	// if homo, break
							rb = true;
							break;
						}
					}
				}
			}
			if(rb){
				cout << "RAINBOW.\n";
				break;
			}
		}
		if(!rb){
			cout << "NORMAL.\n";
		}
	}
}