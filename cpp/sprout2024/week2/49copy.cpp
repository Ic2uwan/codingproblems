#include <bits/stdc++.h>
#define IOOPTI ios_base::sync_with_stdio(false); cin.tie(nullptr)

using namespace std;

struct Node{
	int count;
	int data;
	vector<int> child;
	Node(int dt){
		data = dt;
	}
};

vector<Node> nodes;
// int cnt = 1;//self contained

void addNode(int data){
	nodes.emplace_back(data);
	// ptr->child.emplace_back(data);
}


int traverse(int node){
	int cnt = 1;
    stack<int> stk;
    stk.push(node);
    while(!stk.empty()){
        int cur = stk.top();
        stk.pop();
        for(auto i : nodes[cur].child){
            stk.push(i);
            ++cnt;
        }
    }
    return cnt;
}

int main(){
	IOOPTI;
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		int sz[n+5];
		for(int i = 1; i <= n;++i){
			addNode(i);
		}
		for(int i = 0; i < m; ++i){
			int x, y;
			cin >> x >> y;
			nodes[x].child.emplace_back(y);
		}
		for(int i = 0; i < n; ++i){
			sz[i] = traverse(i);
		}
		int q;
		cin >> q;
		for(int i = 0; i < q; ++i){
			int in;
			cin >> in;
			cout << sz[in] << '\n';
		}
		nodes.clear();
	}
}
