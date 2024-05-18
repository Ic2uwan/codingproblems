#include <bits/stdc++.h>


using namespace std;


int main(){
	ios_base::sync_with_stdio(0); cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--){
		stack<int> S;
		vector<int> goal;
		int N;
		cin >> N;
		goal.reserve(N);
		for(int i = 0; i < N; ++i){
			cin >> goal[i];
		}
		int ptr = 0;
		for(int i = 1; i <= N; ++i){
			if(i == goal[ptr]){
				ptr++;
			}
			else{
				S.push(i);
			}
			while(!S.empty() && S.top() == goal[ptr]){
				ptr++;
				S.pop();
			}
		}
		if(S.empty()){
			cout << "Yes\n";
		}
		else{
			cout << "No\n";
		}
	}
}
