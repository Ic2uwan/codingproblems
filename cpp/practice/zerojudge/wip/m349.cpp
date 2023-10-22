#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	ll k, a, b, c;
	ll asc = 0, bsc = 0;
	cin >> k;
	for(int i = 0; i < k; i++){
		cin >> a >> b >> c;
		asc += b*a;
		bsc += c*a;
	}
	cout << asc << '\n' << bsc << '\n';
	if(asc==bsc){
		cout << "tie";
	}
	else if(asc>bsc){
		cout << 0;
	}
	else{
		cout << 1;
	}
}
