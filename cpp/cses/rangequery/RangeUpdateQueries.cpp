#include <bits/stdc++.h>
#define IO ios_base::sync_with_stdio(0), cin.tie(0)
#define int long long

using namespace std;
using ll = long long;

int n, q;
int arr[200005];
struct Segtree{
	struct Node{
		int val;
		Node *lc = nullptr, *rc = nullptr;
		int tag = 0;
	} *root = new Node;
	void build(Node *x, int lx, int rx){
		if(lx+1==rx){
			x->val = arr[lx];
			return;
		}
		int mid = (lx+rx)>>1;
		x->lc = new Node, x->rc = new Node;
		build(x->lc, lx, mid);
		build(x->rc, mid, rx);
	}
	void push(Node *x, int lx, int rx){
		if(x->tag){
			if(lx+1==rx){
				x->val += x->tag;
			}
			else{
				x->lc->tag += x->tag;
				x->rc->tag += x->tag;
			}
			x->tag = 0;
		}
	}
	void modify(Node *x, int lx, int rx, int l, int r, int v){
		if(lx>=r||rx<=l) return;
		if(l<=lx&&rx<=r){
			x->tag += v;
			return;
		}
		int mid = (lx+rx)>>1;
		modify(x->lc, lx, mid, l, r, v);
		modify(x->rc, mid, rx, l, r, v);
	}
	int query(Node *x, int lx, int rx, int pos){
		push(x, lx, rx);
		if(lx+1==rx){
			return x->val;
		}
		int mid = (lx+rx)>>1;
		if(pos < mid) return query(x->lc, lx, mid, pos);
		else return query(x->rc, mid, rx, pos);
	}
}st;

signed main(){
	IO;
    cin >> n >> q;
    for(int i = 1; i <= n; ++i){
        cin >> arr[i];
    }
	st.build(st.root, 0, n+1);
    int a, b, c, d;
    while(q--){
        cin >> a;
		if(a==1){
			cin >> b >> c >> d;
			st.modify(st.root, 0, n+1, b, c+1, d);
		}
		else{
			cin >> b;
			cout << st.query(st.root, 0, n+1, b) << '\n';
		}
	}
}