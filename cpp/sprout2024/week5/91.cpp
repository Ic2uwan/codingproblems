#include <bits/stdc++.h>
#define IO ios_base::sync_with_stdio(0), cin.tie(nullptr)
#define ll long long
using namespace std;


int main(){
	IO;
	int T;
	cin >> T;
	while(T--){
		stack<int> ans;
		ll num;
		cin >> num;
		if(num == 1){
			cout << 1 << '\n';
			continue;
		}
		for(int i = 9; i >= 2; --i){
			while(num%i==0){
				num/=i;
				ans.push(i);
			}
		}
		if(num == 1){
			while(!ans.empty()){
				cout << ans.top();
				ans.pop();
			}
			cout << '\n';
		}
		else{
			cout << -1 << '\n';
		}
	}
}