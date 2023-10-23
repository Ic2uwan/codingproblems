#include <iostream>
#include <string.h>
#include <queue>

using namespace std;
int main(){
    int num, n, m, sx, sy, tx, ty;
    while(cin >> num){
        for(int iter = 0; iter < n; iter++){
            cin >> n >> m >> sx >> sy >> tx >> ty;
            sx--;
            sy--;
            tx--;
            ty--;
            int a[n][m];
            int dx[4] = {0, 0, 1, -1};
            int dy[4] = {1, -1, 0, 0};
            string str;
            for(int j = 0; j < n; j++){
                cin >> str;
                for(int k =0; k < m; k++){
                    a[j][k] = str[k]-'0';
                }
            } //parse input
            int arr[n][m];
            memset(arr, -1, sizeof(arr)); //fill with -1
            queue <pair<int, int>> q; //declare queue q
            q.push({sx, sy}); //push starting point to queue
            arr[sx][sy] = 1; //assign distance to starting point to 1
            while(!q.empty()){
                pair<int, int> now;
                now = q.front(); //q.front() returns the first element of q, which is a pair<int, int>
                q.pop();
                for(int i = 0; i < 4; i++){
                    if(now.first+dx[i] >= 0 && now.first+dx[i] < n && now.second+dy[i] >= 0 && now.second+dy[i] < m){
                        if(a[now.first+dx[i]][now.second+dy[i]] == 0 && arr[now.first+dx[i]][now.second+dy[i]] == -1){
                            q.push({now.first+dx[i], now.second+dy[i]}); //add the current node to queue
                            arr[now.first+dx[i]][now.second+dy[i]] = arr[now.first][now.second] + 1; //distance = parent + 1
                        }
                    }
                }
            }
            if (arr[tx][ty] == -1) cout << 0 << '\n'; //if arr[tx][ty] = -1 : destination can't be reached
            else cout << arr[tx][ty] << '\n'; //prints out the distance
        }
    }
}