#include <bits/stdc++.h>
#define IOOPTI ios_base::sync_with_stdio(false); cin.tie(nullptr)

using namespace std;

int main(){
	stack<int> stk;
	int T;
	cin >> T;
	while(T--){
		int in;
		cin >> in;
		if(in == 1){
			cin >> in;
			stk.push(in);
		}
		else{
			if(!stk.empty()){
				cout << stk.top() << '\n';
				stk.pop();
			}
			else{
				cout << "empty!\n";
			}
		}
	}
}
