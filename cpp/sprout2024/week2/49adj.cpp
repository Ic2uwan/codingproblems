#include <bits/stdc++.h>
#define IOOPTI ios_base::sync_with_stdio(false); cin.tie(nullptr)

using namespace std;

vector<vector<int>> adjList;
vector<int> treeSize;

int traverse(int id){
	int cnt = 1;
	if(!adjList[id].empty()){
		for(int i : adjList[id]){
			if(treeSize[i] == -1)
				cnt += traverse(i);
			else 
				cnt += treeSize[i];
		}
	}
	treeSize[id] = cnt;
	return cnt;
}

int main(){
	IOOPTI;
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		treeSize = vector<int>(n+5,-1);
		adjList = vector<vector<int>>(n+5);
		for(int i = 0; i < m; ++i){
			int x, y;
			cin >> x >> y;
			adjList[x].emplace_back(y);
		}
		int q;
		cin >> q;
		for(int i = 0; i < q; ++i){
			int in;
			cin >> in;
			int cnt = traverse(in);
			cout << cnt << '\n';
		}
		treeSize.clear();
		treeSize.shrink_to_fit();
		adjList.clear();
		adjList.shrink_to_fit();
	}
}