#include <bits/stdc++.h>
#define ioopti ios_base::sync_with_stdio(false), cin.tie(nullptr);
using namespace std;
using ll = long long;
#define mod 1e9

ll cnt = 0;
ll reduce(ll fac){
	while((fac % 10) == 0){
		cnt++;
		fac /= 10;
	}
	return fac;
}

int main(){
	ioopti
	ll n, fac;
	cin >> n;
	fac = 1;
	for(int i = 2; i <= n; i++){
		fac *= reduce(i);
		fac = reduce(fac);
	}
	cout << cnt;
}
