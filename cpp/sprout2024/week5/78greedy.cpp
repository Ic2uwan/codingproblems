#include <bits/stdc++.h>
#define IO ios_base::sync_with_stdio(0), cin.tie(nullptr)
#define ll long long
using namespace std;

int boxes[5];
int main(){
	IO;
	int T;
	cin >> T;
	while(T--){
		int ans;
		for(int i = 0; i < 5; ++i){
			cin >> boxes[i];
		}
		cin >> ans;
		if(!boxes[0]&&!boxes[1]&&!boxes[2]&&!boxes[3]&&!boxes[4]&&!ans){
			cout << 0 << '\n';
			continue;
		}
		ans += boxes[4];
		boxes[0] -= 11*boxes[4];
		ans += boxes[3];
		boxes[1] -= 5*boxes[3];
		ans += boxes[2] / 4;
		if(boxes[2]%4 == 1){
			boxes[0] -= 7;
			boxes[1] -= 5;
			++ans;
		}
		else if(boxes[2]%4 == 2){
			boxes[0] -= 6;
			boxes[1] -= 3;
			++ans;
		}
		else if(boxes[2]%4 == 3){
			boxes[0] -= 5;
			boxes[1] -= 1;
			++ans;
		}
		if(boxes[1] < 0){
			boxes[0] += 4*boxes[1];
		}
		else if(boxes[1] > 0){
			ans += boxes[1] / 9;
			if(boxes[1] % 9){
				++ans;
			}
			boxes[0] -= 36-(4*(boxes[1]%9));
		}
		if(boxes[0] > 0){
			ans += (boxes[0] + 35) / 36; 
		}
		cout << ans << '\n';
	}
}