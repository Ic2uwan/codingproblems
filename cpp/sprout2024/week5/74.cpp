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
		for(int i = 0; i < N; ++i){
			cin >> stones[i];
		}
		int mxlen = 0;
		for(int i = 0; i < N-mxlen; ++i){
			int len = 1;
			int stat = 0; // 1 for finding next bigger element, 0 for next smaller
			// stack<int> monostk;
			int idx = -1;
			for(int j = i+1; j < N; ++j){
				int mn = INT_MAX, mx = 0;
				int curval = stones[j-1];
				// cout << curval << ' ';
				if(stat){ // finding next smallest
					mn = stones[j-1]; idx = j-1;
					while(j!=N&&stones[j]<curval){ // if not the end and not higher than last selected stone
						if(stones[j] < mn){
							mn = stones[j];
							idx = j;
						}
						++j;
					}
				}else{
					mx = stones[j-1]; idx = j-1;
					while(j!=N&&stones[j]>curval){
						if(stones[j] > mx){
							mx = stones[j];
							idx = j;
						}
						++j;
					}
				}
				if(idx!=-1){
					++len;
					stat = !stat;
					j = idx+1;
				}
			}
			// cout << '\n';
			mxlen = max(mxlen, 2*((len+1)/2)-1);
		}
		// cout << "ans: " << mxlen << '\n';
		cout << mxlen << '\n';
	}
}
