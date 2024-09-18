#include <bits/stdc++.h>
#define IO ios_base::sync_with_stdio(0), cin.tie(0)

using namespace std;

unordered_map<string, int> ump;

int main(){
	IO;
	int N, M;
	cin >> N >> M;
	for(int i = 0; i < N; ++i){
		string tmp;
		cin >> tmp;
		ump[tmp] += 1;
	}
	for(int i = 0; i < M; ++i){
		string tmp;
		cin >> tmp;
		cout << ump[tmp] << '\n';
	}
}