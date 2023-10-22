#include <bits/stdc++.h>


using namespace std;
int main(){
    int n, m, dist;
    int intmp;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    cin >> n >> m;
    vector<pair<int, int>> spec;
    queue<pair<int, int>> next;
    pair<int, int> now;
    int M[n][m];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> intmp;
            M[i][j] = intmp;
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            int sum = M[i][j];
            dist = 0;
            next.push({i, j});
            while(dist < M[i][j]){
                now = next.front();
                next.pop();
                for (int a = 0; a < 4; a++){
                    if(now.first + dy[a] >= 0 && now.first + dy[a] < n && now.second + dx[a] >= 0 && now.second + dx[a] < m){
                        sum += M[now.first + dy[a]][now.second + dx[a]];
                        next.push({now.first + dy[a], now.second + dx[a]});
                    }
                }
                dist++;
            }
            if(sum % 10 == M[i][j]) spec.push_back({i, j});
        }
    }
    cout << spec.size() << '\n';
    for (int i = 0; i < spec.size(); i++){
        cout << spec[i].first << ' ' << spec[i].second << '\n';
    }
}