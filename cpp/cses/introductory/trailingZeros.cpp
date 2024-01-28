#include <bits/stdc++.h>
#define ioopti ios_base::sync_with_stdio(false), cin.tie(nullptr)
using namespace std;
using ll = long long;

int main(){
	ioopti;
	int n;
	cin >> n;
	int ans = 0;
	while(n){
		ans += n / 5;
		n /= 5;
	}
	cout << ans << endl;
}
