#include <bits/stdc++.h>
using namespace std;


int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int k, t, s;
	int critical = 0;
	pair<int, int> mx = make_pair(0, -2);
	cin >> k;
	for(int i = 0; i < k; i++){
		cin >> t >> s;
		if(s > mx.second){
			mx = make_pair(t, s);
		}
		if(s == -1){
			critical++;
		}
	}
	int ans;
	ans = mx.second - k - (critical * 2);
	if(ans < 0)
		cout << 0 << ' ';
	else
		cout << ans << ' ';
	cout << mx.first << '\n';
}
