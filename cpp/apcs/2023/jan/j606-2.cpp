#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int k, q, r;
	int in;
	cin >> k >> q >> r;
	vector<string> s(q + 1, string(k, '_')); 
	
	cin >> s[0];
	for(int i = 1; i <= q; i++){
		for(int j = 0; j < k; j++){
			cin >> in;
			s[i][in - 1] = s[i-1][j];
		}
	}
	// for(string str : s){cout << str << '\n';}
	for(int j = 0; j < r; j++){
		for(int i = 1; i <= q; i++){
			cout << s[i][j];
		}
		cout << '\n';
	}
}
