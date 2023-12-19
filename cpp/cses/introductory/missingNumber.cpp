#include <bits/stdc++.h>

using namespace std;
#define ioopti ios_base::sync_with_stdio(false), cin.tie(nullptr)

int main(){
	ioopti;
	int n, input;
	cin >> n;
	vector<int> v(n, 0);
	
	for(int i = 0; i < n-1; i++){
		cin >> input;
		v[input-1] = 1;
	}
	for(int i = 0; i < n; i++){
		if(v[i] == 0){
			cout << i+1;
			break;
		}
	}
}
