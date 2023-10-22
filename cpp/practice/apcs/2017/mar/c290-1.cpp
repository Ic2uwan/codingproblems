#include <bits/stdc++.h>
#define ioopti ios_base::sync_with_stdio(false); cin.tie(NULL);

using namespace std;

int main(){
	ioopti
	string a;
	int sum = 0;
	cin >> a;
	for(int i = 0; i < a.size(); i++){
		if(i % 2 == 0){
			sum += (a[i] - '0');
		} else {
			sum -= (a[i] - '0');
		}
	}
	cout << abs(sum) << '\n';	
}
