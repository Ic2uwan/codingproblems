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
		x->val = min(x->lc->val, x->rc->val);
	}
	void modify(Node *x, int lx, int rx, int pos, int v){
		if(lx==rx-1){
			x->val = v;
			// cout << lx << " modified to " << x->val << '\n';
			return;
		}
		int mid = (lx+rx)>>1;
		if(pos < mid) modify(x->lc, lx, mid, pos, v);
		else modify(x->rc, mid, rx, pos, v);
		x->val = min(x->lc->val, x->rc->val);
	}
	int query(Node *x, int lx, int rx, int l, int r){
		if(lx>=r||rx<=l) return INT64_MAX;
		if(l<=lx&&rx<=r) return x->val;
		int mid = (lx+rx)>>1;
		return min(query(x->lc, lx, mid, l, r), query(x->rc, mid, rx, l, r));
	}
}st;

signed main(){
	IO;
    cin >> n >> q;
    for(int i = 1; i <= n; ++i){
        cin >> arr[i];
    }
	st.build(st.root, 0, n+1);
    int a, b, c;
    while(q--){
        cin >> a >> b >> c;
		if(a==1){
			st.modify(st.root, 0, n+1, b, c);
		}
		else{
			cout << st.query(st.root, 0, n+1, b, c+1) << '\n';
		}
	}
}