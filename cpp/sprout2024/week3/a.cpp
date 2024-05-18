#include <bits/stdc++.h>
#define ios ios::sync_with_stdio(0),cin.tie(0)
#define MAX 102
using namespace std;
int n,sx,sy;
int dx[4]={-1,0,1,0}, dy[4]={0,-1,0,1};//左下右上
char maze[MAX][MAX];
bool visit[105][105];

struct node{
    int x,y,path;
};
queue<node> qq;
int bfs(){
    int now_x = sx, now_y = sy;
    qq.push(node{sx,sy,0});
    while(!qq.empty()){
        now_x = qq.front().x;
        now_y = qq.front().y;
        if(maze[now_x][now_y]=='@')return qq.front().path;
        int front = qq.front().path+1;
        for(int i=0;i<4;i++){
            int nx = now_x+dx[i],ny = now_y+dy[i];
            if(!visit[nx][ny] && maze[nx][ny]!='#'){
                qq.push(node{nx,ny,front});
                visit[nx][ny] = 1;
            }
        }
        qq.pop();
    }
    return -1;
}
signed main(){
    ios;
    while(cin>>n && n!=0){
        memset(visit, 0, sizeof(visit));
        while(!qq.empty())qq.pop();
        for(int i=0;i<n;i++)cin>>maze[i];
        
        for(int i=0;i<n;i++)
            for(int j=0;j<strlen(maze[i]);j++)
                if(maze[i][j]=='K'){
                    sx = i;sy = j;
                    break;
                }
        int ans = bfs();
        if(ans>=0)cout<<ans<<"\n";
        else cout<<"= =\""<<"\n";
    }
    return 0;
}
