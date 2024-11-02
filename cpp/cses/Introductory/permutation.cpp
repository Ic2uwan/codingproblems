#include <bits/stdc++.h>
#define ioopti ios_base::sync_with_stdio(false), cin.tie(nullptr);
using namespace std;
using ll = long long;

void solve(int in){
	if(in % 2 == 1){
		for(int i = in; i > 0; i-=2){
			cout << i << ' ';
		}
		for(int i = in - 1; i > 0; i-=2){
			cout << i << ' ';
		}
	}
	else{
		for(int i = in - 1; i > 0; i-=2){
			cout << i << ' ';
		}
		for(int i = in; i > 0; i-=2){
			cout << i << ' ';
		}
	}
}

int main(){
	ioopti
	int in;
	cin >> in;
	if(in == 1) cout << 1;
	else if(in <= 3) cout << "NO SOLUTION";
	else solve(in);
}
