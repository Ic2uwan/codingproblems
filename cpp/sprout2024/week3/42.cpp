#include <bits/stdc++.h>
#define pii pair<int, int>
#define ff first
#define ss second
#define IO ios_base::sync_with_stdio(0), cin.tie(nullptr)
using namespace std;


int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int H, W;
int mp[1005][1005];
// int vis[1005][1005];

void bfs(pii origin){
	// vector<vector<int>> vis(H, vector<int>(W,0));
	queue<pii> q;
	q.push(origin);
	// vis[origin.ff][origin.ss] = true;
	while(!q.empty()){
		pii now = q.front();
		q.pop();
		for(int i = 0; i < 4; ++i){
			if((now.ff + dy[i]) < H && (now.ff + dy[i]) >= 0 && (now.ss + dx[i]) < W && (now.ss + dx[i]) >= 0){
				if(mp[now.ff + dy[i]][now.ss + dx[i]] != -1){
					mp[now.ff + dy[i]][now.ss + dx[i]] = -1;
					q.push(make_pair(now.ff + dy[i], now.ss + dx[i]));
				}
			}
		}
	}
	return;
}

int main(){
	IO;
	int t;
	cin >> t;
	while(t--){
		memset(mp,0,sizeof(mp));
		// memset(vis,0,sizeof(vis));
		cin >> H >> W;
		// vector<vector<int>> mp(H, vector<int>(W,0));
		char in;
		for(int i = 0; i < H; ++i){
			for(int j = 0; j < W; ++j){
				cin >> in;
				if(in == '#'){
					mp[i][j] = -1;
				}/*
				else if(in == '.'){
					mp[i][j] = 0;
				}*/
			}
		}
		int cnt = 0;
		for(int i = 0; i < H; ++i){
			for(int j = 0; j < W; ++j){
				if(mp[i][j] != -1){
					++cnt;
					bfs(make_pair(i, j));
				}
			}
		}
		cout << cnt << '\n';
	}
}

