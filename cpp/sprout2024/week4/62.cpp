#include <bits/stdc++.h>
#define IO ios_base::sync_with_stdio(false); cin.tie(nullptr)
using namespace std;


// backtracking enumeration

int mp[9][9];
// void printgrid(){
// 	for(int i = 0; i < 9; ++i){
// 		for(int j = 0; j < 9; ++j){
// 			cout << mp[i][j] << ' ';
// 		}
// 		cout << '\n';
// 	}
// 	cout << '\n';
// }
void printall(){
	for(int i = 0, a; i < 81; ++i){
		cout << mp[i/9][i%9];
	}
	cout << '\n';
}
int validate(int id, int num){
	int a = id/9, b = id%9;
	for(int i = 0; i < 9; ++i){
		if(((num == mp[a][i])&&(i!=b))||
		   ((num == mp[i][b])&&(i!=a))||
		   ((num == mp[3*(a/3)+(i%3)][3*(b/3)+(i%3)])&&
		   !(((3*(a/3)+(i%3))==a)&&((3*(b/3)+(i%3))==b)))){
			return 0;
		}
	}
	return 1;
}
void check(int id, bool *valid){
	int a = id/9, b = id%9;
	for(int i = 0; i < 9; ++i){
		if(mp[a][i]!=-1) valid[mp[a][i]] = 0;
		if(mp[i][b]!=-1) valid[mp[i][b]] = 0;
		if(mp[3*(a/3)+(i%3)][3*(b/3)+(i%3)]!=-1) valid[mp[3*(a/3)+(i%3)][3*(b/3)+(i%3)]] = 0;
	}
	return;
}
int solve(int id){
	if(id == 81) return 1;
	bool valid[10]; memset(valid, 1, sizeof(valid));
	check(id, valid);
	int a = id / 9, b = id % 9;
	if(mp[a][b] != -1){
		if(validate(id, mp[a][b]))// if illegal, break;
			return solve(id + 1); // if empty, move next
		else
			return 0;
	}
	for(int i = 1; i <= 9; ++i){
		if(valid[i] == 1){
			mp[a][b] = i;
			if(solve(id + 1)) return 1;
			mp[a][b] = -1; // reset if no solution
		}
	}
	return 0;
}
int main(){
	IO;
	int T;
	cin >> T;
	while(T--){
		// memset(mp, -1, sizeof(mp));
		char in;
		for(int i = 0, a; i < 81; ++i){
			cin >> in;
			if(in=='.')
				mp[i/9][i%9] = -1;
			else
				mp[i/9][i%9] = in - '0';
			// cout << in - '0' << '\n';
		}
		if(solve(0)){
			printall();
		}
		else{
			cout << "No solution.\n";
		}
	}
}