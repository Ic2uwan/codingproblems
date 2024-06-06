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
int d1[200005], d2[200005], v[200005];
vector<Node> edges[2][200005];
signed main(){
		priority_queue<Node, vector<Node>, Node::cmp> pq;
		fill(d1, d1+200005, 1LL<<60);
		fill(d2, d2+200005, 1LL<<60);
		memset(v, 0, sizeof(v));
		int n, m, q;
		cin >> n >> m >> q;
		for(int i = 0; i < m; ++i){
			int a, b, c;
			cin >> a >> b >> c;
			edges[0][a].emplace_back(Node(b, c));
			edges[1][b].emplace_back(Node(a, c));
		}
		pq.push(Node(1, 0));
		d1[1] = 0; // dist of s is 0
		while(!pq.empty()){
			Node cur = pq.top();
			pq.pop();
			if(v[cur.d])
				continue;
			for(auto a : edges[0][cur.d]){
				if(d1[cur.d]+ a.w < d1[a.d]){
					d1[a.d] = d1[cur.d] + a.w;
					pq.push(Node(a.d, d1[a.d]));
				}
			}
			v[cur.d] = 1;
		}
		memset(v, 0, sizeof(v));
		pq.push(Node(n, 0));
		d2[n] = 0; // dist of s is 0
		while(!pq.empty()){
			Node cur = pq.top();
			pq.pop();
			if(v[cur.d])
				continue;
			for(auto a : edges[1][cur.d]){
				if(d2[cur.d]+ a.w < d2[a.d]){
					d2[a.d] = d2[cur.d] + a.w;
					pq.push(Node(a.d, d2[a.d]));
				}
			}
			v[cur.d] = 1;
		}
		while(q--){
			int a, b;
			cin >> a >> b;
			cout << min(d1[a] + d2[b] + 1, d1[n]) << '\n';
		}
}