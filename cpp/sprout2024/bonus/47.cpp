#include <bits/stdc++.h>
#define IO ios_base::sync_with_stdio(0), cin.tie(nullptr)
#define ull unsigned long long
#define int long long
using namespace std;

signed main() {
	int N;
	cin >> N;
	set<int> s;
	while (N--) {
		bool flg = 0;
		int ass[2];
		string op;
		int x;
		cin >> op >> x;

		if(op[0] == 'i') {
			s.insert(x);
		} else if(op[0] == 'd') {
			s.erase(x);
		} else if(op[0] == 'q') {
			auto it = s.lower_bound(x);
			int lp;
			if(it == s.begin()) {
				lp = *it;
			}
			else if(it == s.end()) {
				lp = *prev(it);
			}
			else {
				int pp = *prev(it);
				int np = *it;
				if(abs(x - pp) < abs(x - np)) {
					lp = pp;
				}
				else if(abs(x - pp) == abs(x - np)){
					ass[0] = pp;
					ass[1] = np;
					flg = true;
				}
				else{
					lp = np;
				}
			}
			if(flg){
				cout << ass[0] << ' ' << ass[1] << '\n';
			}
			else{
				cout << lp << '\n';
			}
		}
	}

	return 0;
}