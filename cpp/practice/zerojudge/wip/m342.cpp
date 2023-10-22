#include <bits/stdc++.h>
using namespace std;


int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, in;
	cin >> n;
	pair<int, int> mx1(0, 0);
	pair<int, int> mx2(0, 0);
	for(int i = 0; i < n; i++){
		cin >> in;
		if((in > mx1.first || mx1.first == 0) && (in < mx2.first)){
			mx1 = make_pair(in, i + 1);
		}else if(in > mx2.first){
			mx1 = mx2;
			mx2 = make_pair(in, i + 1);
		}
	}
	cout << min(mx1.second, mx2.second) << ' ' << max(mx1.second, mx2.second);
}
