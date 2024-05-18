#include <bits/stdc++.h>
#define IO ios_base::sync_with_stdio(0), cin.tie(nullptr)
#define ll long long
using namespace std;


int N;
int stones[1000005];

int main(){
	IO;
	int T;
	cin >> T;
	while(T--){
		memset(stones, 0, sizeof(stones));
		cin >> N;
		for(int i = 0; i < N; ++i)
			cin >> stones[i];
		int mxlen = 0;
		// find first
		int idx = 0;
		while(idx!=N&&stones[idx+1]>=stones[idx]){
			++idx;
		}
		// begin iteration
		int obj = 1; // 0 for finding a higher one, 1 for finding a lower one
		int tar = INT_MAX;
		int len = 1;
		// cout << stones[idx] << ' ';
		while(idx<N){
			if(stones[idx] == stones[idx+1]){ // if repeating, continue
				++idx;
				continue;
			}
			else if(obj){ // find less
				while(stones[idx] <= stones[idx+1]) ++idx;
			}
			else{ // find greater
				while(stones[idx] >= stones[idx+1] && stones[idx]!=0) ++idx;
			}
			// cout << stones[idx] << ' ';
			++len;
			obj = !obj;
		}
		// cout << '\n';
		cout << 2*((len+1)/2)-3 << '\n';
	}
}
