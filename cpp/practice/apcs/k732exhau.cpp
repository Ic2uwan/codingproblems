#include <bits/stdc++.h>

int n, m;

using namespace std;

array<array<int, 54>, 54> M;
int sum(int x, int y, int d){
    int s = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(abs(i - x) + abs(j - y) <= d) s += M[i][j];
        }
    }
    return s;
}
int main(){
    int dist;
    int intmp;
    cin >> n >> m;
    vector<pair<int, int>> ans;
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> intmp;
            M[i][j] = intmp;
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if(sum(i, j, M[i][j]) % 10 == M[i][j]) ans.push_back({i, j});
        }
    }
    cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); i++){
        cout << ans[i].first << ' ' << ans[i].second << '\n';
    }
}