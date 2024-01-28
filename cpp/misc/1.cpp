#include <bits/stdc++.h>
#define ioopti ios_base::sync_with_stdio(false), cin.tie(nullptr);

using namespace std;

int main(){
	ioopti
	int n = 0;
	cin >> n;
	vector<pair<int, int>> ass;
	int a, b;
	for(int i = 0; i < n+1; i++){
		cin >> a >> b;
		ass.push_back({a, b});
	}
	int tmp;
	cout << "a(x)=\n";
	if(n == 0) cout << 0 << ' ' << ass[0].second << '\n';
	else
	for(int i = 0; i < n; i++){
		tmp = ass[i].first * ass[i].second;
		cout << tmp << ' ';
		if(ass[i].second != 0) tmp = ass[i].second - 1;
		cout << tmp << '\n';
	}
	cout << "A(x)=\n";
	for(int i = 0; i < n+1; i++){
		tmp = ass[i].first / (ass[i].second + 1);
		cout << tmp << ' ';
		cout << ass[i].second + 1 << '\n';
	}
	cout << "c 0";
}
