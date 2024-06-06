#include <bits/stdc++.h>
#define IO ios_base::sync_with_stdio(false), cin.tie(nullptr)
#define ll long long


using namespace std;
int T, N;
int arr[1000000];
int seg[4000000];
void build(int l, int r, int idx){
	if(l == r){
		seg[idx];
	}
}
int main(){
	IO;
	cin >> T >> N;
	for(int i = 0; i < N; ++i){
		cin >> arr[i];
	}
}