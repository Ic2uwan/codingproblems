#include <bits/stdc++.h>
#define ioopti ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

int main(){
	ioopti
	long long n;
	cin >> n;
	while(n!=1){
		cout << n << ' ';
		if(n % 2){
			n = n * 3 + 1;
		}else{
			n = n / 2;
		}
	}
	cout << 1;
	return 0;
}
