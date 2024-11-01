#include <bits/stdc++.h>
#define IO ios_base::sync_with_stdio(0), cin.tie(0)
#define int long long
#define ff first
#define ss second
using namespace std;

pair<int, int> a[200005];
signed main(){
	int n, tar;
	cin >> n >> tar;
	for(int i = 0; i < n; ++i){
		cin >> a[i].first;
		a[i].second = i + 1;
	}
	sort(a, a+n);
	int l = n-1;
	int r = 0;
	bool found = 0;
	while(r < l){
		if(a[r].ff+a[l].ff==tar){
			cout << a[r].ss << ' ' << a[l].ss << '\n';
			found = 1;
			break;
		}
		if(a[r].ff+a[l].ff > tar){
			--l;
		}
		else if(a[r].ff+a[l].ff < tar){
			++r;
		}
	}
	if(!found){
		cout << "IMPOSSIBLE" << '\n';
	}
}