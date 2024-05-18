#include <bits/stdc++.h>
#define IOOPTI ios_base::sync_with_stdio(false); cin.tie(nullptr)

using namespace std;

struct Node{
	int data;
	vector<int> child;
	Node(int dt){
		data = dt;
	}
};

vector<Node> nodes;
int cnt = 0;

void addNode(int data){
	nodes.emplace_back(data);
	// ptr->child.emplace_back(data);
}

void traverse(Node nd){
	if(!nd.child.empty()){
		for(auto i : nd.child){
			++cnt;
			traverse(nodes[i]);
		}
	}
	return;
}

Node *head = nullptr;
int main(){
	IOOPTI;
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n;++i){
		addNode(i);
	}
	for(int i = 0; i < m; ++i){
		int x, y;
		cin >> x >> y;
		nodes[x].child.emplace_back(y);
	}
	int q;
	cin >> q;
	for(int i = 0; i < q; ++i){
		int in;
		cin >> in;
		cout << cnt << '\n';
		cnt = 0;
	}
}
