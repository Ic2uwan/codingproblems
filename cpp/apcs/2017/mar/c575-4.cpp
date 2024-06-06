#include <bits/stdc++.h>
#define IO ios_base::sync_with_stdio(0); cin.tie(0);
#define maxn 50005
using namespace std;

int p[maxn];
int n, k;

bool solve(int r){
	int cnt = 1;
	int idx = 0;
	int cover = p[0] + r;
	while(idx < n){
		if(p[idx] > cover){
			++cnt;
			cover = p[idx] + r;
		}
		else{
			++idx;
		}
	}
	return !(cnt > k);
}

int main(){
	IO;
	int mx = 0, mn = -1;
	cin >> n >> k;
	for(int i = 0; i < n; ++i){
		cin >> p[i];
	}
	sort(p, p+n);
	int l = 0, r = p[n-1] - p[0];
	while(l < r){
		int mid = (l + r) / 2;
		if(solve(mid)){
			r = mid;
		}
		else{
			l = mid + 1; 
		}
	}
	cout << l << '\n';
}
