#include <bits/stdc++.h>
#define int long long
#define IO ios_base::sync_with_stdio(0), cin.tie(0)

using namespace std;

struct Node{
	int d;
	int w;
	Node(int a, int b){
		d = a;
		w = b;
	}
	struct cmp {
    bool operator()(Node const& n1, Node const& n2) {
        	return n1.w > n2.w;
    }
	};
};
vector<Node> edges[200005];
bool v[200005];
priority_queue<Node, vector<Node>, Node::cmp> pq;


signed main(){
	IO;
	int N, M;
	int ans = 0;
	cin >> N >> M;
	for(int i = 0; i < M; ++i){
		int v, u, w;
		cin >> v >> u >> w;
		edges[v].emplace_back(Node(u, w));
		edges[u].emplace_back(Node(v, w));
	}
	v[1] = 1;
	for(auto a : edges[1])
		pq.push(a);
	while(!pq.empty()){
		Node cur = pq.top();
		pq.pop();
		if(v[cur.d]) continue;
		v[cur.d] = 1;
		ans += cur.w;
		for(auto a : edges[cur.d]){
			// if(v[a.d]) continue;
			pq.push(a);
		}
	}
	cout << ans << '\n';
}