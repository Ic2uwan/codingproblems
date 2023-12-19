#include <bits/stdc++.h>
#define ioopti ios_base::sync_with_stdio(false), cin.tie(nullptr);
using namespace std;

int main(){
	ioopti
	string str;
	cin >> str;
	int curMax = 1;
	char cur = str[0];
	for(int i = 1, cnt = 1; i < (int)str.size(); i++){
		if(str[i] == cur){
			//cout << str[i] << " ";
			cnt++;
		}
		else{
			curMax = max(curMax, cnt);
			//cout << cnt << "\n";
			cnt = 1;
			cur = str[i];
			//cout << "next\n" << cur << " ";
		}
		if(i + 1 == (int)str.size()){
			curMax = max(curMax, cnt);
		}
	}
	cout << curMax;
}
