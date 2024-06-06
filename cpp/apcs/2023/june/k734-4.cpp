#include <bits/stdc++.h>
#define IO ios_base::sync_with_stdio(0), cin.tie(0);
#define maxn 100005
using namespace std;


vector<int> k2b[maxn];
vector<int> bk[maxn];
int bcnt[maxn];
stack<int> myk;
bool used[maxn];
int main(){
	IO;
	int n, m, k;
	cin >> n >> m >> k;
	fill(bcnt, bcnt + maxn, k);
	int t;
	cin >> t;
	for(int i = 1, a; i <= t; ++i){
		cin >> a;
		myk.push(a);
		used[a] = true;
	}
	for(int i = 1; i <= n; ++i){
		for(int j = 1, a; j <= k; ++j){
			cin >> a;
			k2b[a].emplace_back(i);
		}
	}
	for(int i = 1; i <= n; ++i){
		for(int j = 1, a; j <= k; ++j){
			cin >> a;
			bk[i].emplace_back(a);
		}
	}
	int ans = 0;
	while(!myk.empty()){
		int curk = myk.top();
		myk.pop();
		for(auto a : k2b[curk]){
			if(--bcnt[a] == 0){
				++ans;
				for(auto b : bk[a]){
					if(!used[b]){
						myk.push(b);
						used[b] = true;
					}
				}
			}
		}
	}
	cout << ans << '\n';
}