#include <bits/stdc++.h>
#define IOOPTI ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define maxn (int)1e5+5

using namespace std;
vector<vector<int>> adj;
int mxval[maxn];
int N;
// bool visited[maxn];

int traverse(int cur, int prv){
	int ogsz = 1; // size of this tree
	int susz; // size of the subtree (permutated)
	for(auto &id: adj[cur]){
		if(id != prv){
			susz = traverse(id, cur);
			ogsz += susz; // sum up the subtrees
			mxval[cur] = max(mxval[cur], susz);
		}
	}
	mxval[cur] = max(mxval[cur], N - ogsz);
	return ogsz;
}

int main(){
	IOOPTI;
	int T;
	cin >> T;
	// int N;
	while(T--){
		memset(mxval, 0, sizeof(mxval));
		cin >> N;
		adj.clear();
        adj.resize(N);
		for(int i = 1; i < N; ++i){
			int x, y;
			cin >> x >> y;
			adj[x].emplace_back(y);
			adj[y].emplace_back(x);
		}
		traverse(0, -1);
		int sm = numeric_limits<int>::max();
        int ans = -1;
        for (int i = 0; i < N; ++i){
            if (mxval[i] < sm){
                ans = i;
                sm = mxval[i];
            }
        }
		cout << ans << '\n';
	}
}
