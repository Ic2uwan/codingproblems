#include <bits/stdc++.h>
#define IO ios_base::sync_with_stdio(0), cin.tie(nullptr)
#define ll long long
using namespace std;


int num[(int)1e5];
int main(){
	IO;
	int T;
	cin >> T;
	while(T--){
		memset(num, 0, sizeof(num));
		int n;
		cin >> n;
		for(int i = 0; i < n; ++i){
			cin >> num[i];
		}
		sort(num, num+n);
		ll cost = 0;
		cost = num[0] + num[1];
		cout << "cost" << cost << '\n';
		for(int i = 2; i < n; ++i){
			cost += cost + num[i];
		cout << num[i] << " cost" << cost << '\n';
		}
		cout << cost << '\n';
	}
}
