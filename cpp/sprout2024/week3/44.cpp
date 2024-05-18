#include <bits/stdc++.h>
#define pii pair<int, int>
#define ff first
#define ss second
#define IO ios_base::sync_with_stdio(0), cin.tie(nullptr)
using namespace std;


int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

int mp[105][105];
bool vis[105][105];
int step[105][105];
int main(){
	IO;
	int t;
	cin >> t;
	while(t--){
		int N, M;
		cin >> N >> M;
		queue<pii> q;
		pii cat;
		memset(mp,0,sizeof(mp));
		memset(vis,0,sizeof(vis));
		memset(step,-1,sizeof(step));
		char in;
		
		for(int i = 0; i < N; ++i){
			for(int j = 0; j < M; ++j){
				cin >> in;
				if(in == 'K'){
					cat = make_pair(i, j);
					mp[i][j] = 0;
				}
				else if(in == '#'){
					mp[i][j] = -1;
				}
				else if(in == '.'){
					mp[i][j] = 0;
				}
				else if(in == '@'){
					mp[i][j] = 1;
				}
			}
		}
		
		// for(int i = 0; i < N; ++i){
		// 	for(int j = 0; j < M; ++j){
		// 		cout << mp[i][j];
		// 	}
		// 	cout << '\n';
		// }
		// begin bfs

		q.push(cat);
		vis[cat.ff][cat.ss] = true;
		pii ans = {-1, -1};
		// bool flag = false;
		step[cat.ff][cat.ss] = 0;
		while(!q.empty()){
			pii now = q.front();
			q.pop();
			for(int i = 0; i < 4; ++i){
				if((now.ff + dy[i]) < N && (now.ff + dy[i]) >= 0 && (now.ss + dx[i]) < M && (now.ss + dx[i]) >= 0){
					if(mp[now.ff + dy[i]][now.ss + dx[i]] != -1 && vis[now.ff + dy[i]][now.ss + dx[i]] != 1){
						step[now.ff + dy[i]][now.ss + dx[i]] = step[now.ff][now.ss] + 1;
						if(mp[now.ff + dy[i]][now.ss + dx[i]] == 1){
							// flag = true;
							ans = make_pair(now.ff + dy[i], now.ss + dx[i]);
							break;
						}
						q.push(make_pair(now.ff + dy[i], now.ss + dx[i]));
						vis[now.ff + dy[i]][now.ss + dx[i]] = true;
					}
				}
			}
			if(ans.ff != -1){
				cout << step[ans.ff][ans.ss] << '\n';
				break;
			}
		}
		// for(int i = 0; i < N; ++i){
		// 	for(int j = 0; j < M; ++j){
		// 		cout << step[i][j] << "\t";
		// 	}
		// 	cout << '\n';
		// }
		// cout << cat.ff << ' ' << cat.ss << '\n';
		// cout << ans.ff << ' ' << ans.ss << '\n';
		if(ans.ff == -1){
			cout << "= =\"\n";
		}
	}
}

