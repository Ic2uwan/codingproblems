#include <iostream>
#include <vector>
#include <array>

using namespace std;

enum dir{
    up,
    down,
    left,
    right
};
void findMin(int &minDist, int dist, int &minI, int I){
    //cout << "dist " << dist << '\n' ;
    if(dist < minDist || !minDist){
        minDist = dist;
        minI = I;
    }
}
int main(){
    int n, x, y, t, minI, minDist, count = 0;
    bool mirrorFound = true;
    int turn[2][4] = {{dir::right, dir::left, dir::down, dir::up},
                      {dir::left, dir::right, dir::up, dir::down}};
    vector<vector<pair<int,int>>> indexX;//{y, state}
    vector<vector<pair<int,int>>> indexY;//{x, state}
    indexX.reserve(30000);
    indexY.reserve(60000);
    cin >> n;
    for(size_t i = 0; i < n; i++){
        cin >> x >> y >> t;
        indexX[x].push_back({y, t});
        indexY[y+30000].push_back({x, t});
    }
    int laser[3] = {0, 0, dir::right}; //{x, y, direction}
    while(mirrorFound){
        mirrorFound = false;
        minDist = 0;
        minI = 0;
        cout << "now " << laser[0] << ' ' << laser[1] << "direction " << laser[2] << '\n';
        switch(laser[2]){
            case dir::up:
                for(size_t i = 0; i < indexX[laser[0]].size(); i++){
                    if(indexX[laser[0]][i].first > laser[1]){
                        mirrorFound = true;
                        findMin(minDist, indexX[laser[0]][i].first - laser[1], minI, i);
                    }
                }
                break;
            case dir::down:
                for(size_t i = 0; i < indexX[laser[0]].size(); i++){
                    if(indexX[laser[0]][i].first < laser[1]){
                        mirrorFound = true;
                        findMin(minDist, laser[1] - indexX[laser[0]][i].first, minI, i);
                    }
                }
                break;
            case dir::left:
                for(size_t i = 0; i < indexY[laser[1]].size(); i++){
                    if(indexY[laser[1]+30000][i].first < laser[0]){
                        mirrorFound = true;
                        findMin(minDist, indexY[laser[1]+30000][i].first - laser[0], minI, i);
                    }
                }
                break;
            case dir::right:
                for(size_t i = 0; i < indexY[laser[1]].size(); i++){
                    if(indexY[laser[1]+30000][i].first > laser[0]){
                        mirrorFound = true;
                        findMin(minDist,  laser[0] - indexY[laser[1]+30000][i].first, minI, i);
                    }
                }
                break;
        }
        if(mirrorFound){
            if(laser[2] == dir::up || laser[2] == dir::down) laser[1] = indexX[laser[0]][minI].first;
            else laser[0] = indexY[laser[1]+30000][minI].first;
            cout << "hit mirror at " << laser[0] << ' ' << laser[1] << '\n';
            laser[2] = turn[indexX[laser[0]][minI].second][laser[2]];
            count++;
        }
    }
    cout << count;
}