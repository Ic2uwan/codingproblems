#include <bits/stdc++.h>
#define ioopti ios_base::sync_with_stdio(false), cin.tie(nullptr);
using namespace std;
using ll = long long;

int main(){
	ioopti
	vector<ll> v;
	ll in, n;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> in;
		v.emplace_back(in);
	}
	ll moves = 0;
	for(int i = 0; i < n - 1; i++){
		if(v[i + 1] < v[i]){
			moves += (v[i] - v[i + 1]);
			v[i + 1] = v[i];
		}
	}
	cout << moves;
}
