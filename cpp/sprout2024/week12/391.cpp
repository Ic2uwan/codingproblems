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
signed main(){
	int T;
	cin >> T;
	while(T--){
		vector<Node> edges[105];
		int d[105], v[105]; // dijsktra
		priority_queue<Node, vector<Node>, Node::cmp> pq;
		fill(d, d+105, INT64_MAX);
		memset(v, 0, sizeof(v));
		int n, m, s, e, f;
		cin >> n >> m >> s >> e >> f;
		for(int i = 0;i < m; ++i){
        	int a, b, c, d, cp;
			cin >> a >> b >> c >> d >> cp;
			if(f > d)
				edges[a].emplace_back(Node(b, c * d + cp * (f - d)));
			else
				edges[a].emplace_back(Node(b, c * f));
		}
		pq.push(Node(s, 0));
		d[s] = 0; // dist of s is 0
		while(!pq.empty()){
			Node cur = pq.top();
			pq.pop();
			if(v[cur.d])
				continue;
			for(auto a : edges[cur.d]){
				if(d[cur.d]+ a.w < d[a.d]){
					d[a.d] = d[cur.d] + a.w;
					pq.push(Node(a.d, d[a.d]));
				}
			}
			v[cur.d] = 1;
		}
		cout << d[e] << '\n';
	}
}