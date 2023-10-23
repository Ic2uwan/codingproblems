#include <iostream>
#include <vector>
#include <array>

using namespace std;

int n, m, lives;

void move(array<int, 5> &boss){
    boss[0] += boss[2];
    boss[1] += boss[3];
}

void conditionCheck(array<int, 5> &boss, vector<array<int, 3>> &bombV){
    if(boss[0] < 0 || boss[0] >= n || boss[1] < 0 || boss[1] >= m){
        //cout << ' ' << boss[0] << ' ' << boss[1] << " out of bounds\n";
        boss[4] = 0;
        lives -= 1;
    }
    else
    for(int i = 0; i < bombV.size(); i++){
        if(boss[0] == bombV[i][0] && boss[1] == bombV[i][1] && bombV[i][2] != 0){
            boss[4] = 0;
            bombV[i][2] = -1;
            //cout << ' ' << boss[0] << ' ' << boss[1] << " blew\n";
            lives -= 1;
            break;
        }
    }
}

void clearBomb(vector<array<int, 3>> &bombV, int &bombSum){
    bombSum = bombV.size();
    for(int i = 0; i < bombV.size(); i++)
        if(bombV[i][2] != 1){
            bombV[i][2] = 0;
            bombSum--;
        }
}

int main(){
    int k, r, c, s, t, bombNum = 0;
    bool found;
    vector<array<int, 3>> bombV; //{y, x, state} placed = 1, blew = -1, cleared = 0
    vector<array<int, 5>> bossV; //{y, x, dy, dx, state} alive = 1, dead = 0
    cin >> n >> m >> k;
    lives = k;
    for(int i = 0; i < k; i++){
        cin >> r >> c >> s >> t;
        bossV.push_back({r, c, s, t, 1});
    }
    while(lives > 0){
        for(int i = 0; i < k; i++){
            if(bossV[i][4] == 1){
                found = false;
                //if(!bombV.empty()){
                    for(int j = 0; j < bombV.size(); j++){
                        if(bossV[i][0] == bombV[j][0] && bossV[i][1] == bombV[j][1] && bombV[j][2] != 0){
                            found = true;
                            break;
                        }
                    }
                //}
                if(!found){
                    bombV.push_back({bossV[i][0], bossV[i][1], 1});
                    cout << i << ' ' << bossV[i][0] << ' ' << bossV[i][1] << " pushed\n";
                }
                move(bossV[i]);
            }
        }
        for(int i = 0; i < k; i++){
            if(bossV[i][4] == 1) 
                conditionCheck(bossV[i], bombV);
        }
        clearBomb(bombV, bombNum);
    }
    cout << bombNum;
    return 0;
}
