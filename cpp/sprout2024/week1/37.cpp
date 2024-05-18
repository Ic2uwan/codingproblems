#include <bits/stdc++.h>
#define IOOPTI ios_base::sync_with_stdio(false); cin.tie(nullptr)

using namespace std;

int main(){
	queue<int> q;
	int T;
	cin >> T;
	while(T--){
		int in;
		cin >> in;
		if(in == 1){
			cin >> in;
			q.emplace(in);
		}
		else{
			if(!q.empty()){
				cout << q.front() << '\n';
				q.pop();
			}
			else{
				cout << "empty!\n";
			}
		}
	}
}
