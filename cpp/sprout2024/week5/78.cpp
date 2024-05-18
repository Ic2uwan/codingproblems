#include <bits/stdc++.h>
#define IO ios_base::sync_with_stdio(0), cin.tie(nullptr)
#define ll long long
using namespace std;


int mp[6][6];
int boxes[5];
int space;
void prtgrid(){
	for(int i = 0; i < 6; ++i){
		for(int j = 0; j < 6; ++j){
			cout << mp[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}
bool chck(int sz, int y, int x){
	// if(boxes[sz-1]==0) return false;
	for(int i = 0; i < sz; ++i){
		for(int j = 0; j < sz; ++j){
			if(mp[i+y][j+x]==1)
				return false;
		}
	}
	// cout << "in box size " << sz << '\n'; 
	// prtgrid();
	for(int i = 0; i < sz; ++i){
		for(int j = 0; j < sz; ++j){
			mp[i+y][j+x] = 1;
			--space;
		}
	}
	return true;
}
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
		while(true){
			bool brkflg = false;
			for(int i = 0; i < 5; ++i)
				if(boxes[i]) brkflg = true;
			if(!brkflg)
				break;
			
			memset(mp, 0, sizeof(mp));
			space = 64;
			for(int i = 4; i >= 0; --i){
				if(boxes[i])
				for(int y = 0; (y < 6-i)&&(boxes[i]!=0)&&space; ++y){
					for(int x = 0; (x < 6-i)&&(boxes[i]!=0&&space); ++x){
						if(chck(i+1, y, x)){
							boxes[i]-=1;
						}
					}
				}
			}
			++ans;
		}
		cout << ans << '\n';
	}
}