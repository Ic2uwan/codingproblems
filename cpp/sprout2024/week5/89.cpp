#include <bits/stdc++.h>
#define IO ios_base::sync_with_stdio(0), cin.tie(nullptr)
#define ll long long
#define pii pair<int, int>
#define ff first
#define ss second
using namespace std;


pii c[10005]; // eating time ff, cooking time ss
bool comp(pii a, pii b){
	return a.ss > b.ss;
}
int main(){
	IO;
	int T;
	cin >> T;
	while(T--){
		fill(c, c+10005, make_pair(0, 0));
		int N;
		cin >> N;
		for(int i = 0; i < N; ++i){
			int a, b;
			cin >> a >> b;
			c[i].ff = a, c[i].ss = b;
		}
		sort(c, c+N, comp);
		ll elapsed = 0, mx = 0;
		for(int i = 0; i < N; ++i){
			elapsed += c[i].ff;
			mx = max(mx, elapsed+c[i].ss);
		}
		cout << mx << '\n';
	}
}