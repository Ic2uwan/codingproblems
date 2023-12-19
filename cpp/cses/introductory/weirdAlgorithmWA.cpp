#include <bits/stdc++.h>
#define ioopti ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;


long long algo(long long n){
	cout << n << ' ';
	if(n == 1) return 1;
	else if(n % 2 == 0){
		return algo(n / 2);
	}else{
		return algo(n * 3 + 1);
	}
}
int main(){
	ioopti
	long long n;
	cin >> n;
	algo(n);
	return 0;
}
