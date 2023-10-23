#include <bits/stdc++.h>
using namespace std;


vector<vector<int>> mat;

int dx[4] = {0, 1, 0, 1};
int dy[4] = {0, 0, 1, 1};
int chunkMax(int y, int x){
	int cMax = numeric_limits<int>::min();
	for(int i = 0; i < 4; i++){
		cMax = max(cMax, mat[y+dy[i]][x+dx[i]]);
	}
	return cMax;
}
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, in;
	cin >> n;
	mat.reserve(n);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> in;
			mat[i].emplace_back(in);
		}
	}
	for(int i = 0; i < n; i+=2){
		for(int j = 0; j < n; j+=2){
			cout << chunkMax(i, j) << ' ';
		}
		cout << '\n';
	}
}
