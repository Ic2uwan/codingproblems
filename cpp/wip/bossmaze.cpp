#include <iostream>
#include <vector>

using namespace std;
class bomb{
    public:
        int x, y;
        int blow = -1;
        bomb(int _x, int _y){
            x = _x;
            y = _y;
        }
};

class boss{
    public:
        int x, y, a, b;
        bool alive = 1;
        boss(int _a, int _b, int _c, int _d){
            x = _a;
            y = _b;
            a = _c;
            b = _d;
        }
        void move(vector<bomb> &bombmap){
            //cout << "moved \n";
            bool found = false;
            for(int i = 0; i < bombmap.size(); i++){
                if(x == bombmap[i].x && y == bombmap[i].y){
                    found = true;
                    break;
                }
            }
            if(!found) bombmap.push_back(bomb(x, y));
            x += a;
            y += b;
        }
        void dead(int &lives){
            alive = false;
            lives -= 1;
        }
};

int main(){
    int n, m, k, r, c, s, t;
    cin >> n >> m >> k;
    int lives = k;
    vector<boss> bossV; 
    vector<bomb> bombmap;
    for(int i = 0; i < k; i++){
        cin >> r >> c >> s >> t;
        bossV.push_back(boss(r, c, s, t));
    }

    
    while(lives > 0){
        //cout << "lives "<< lives << '\n';
        for(int i = 0; i < k; i++){
            if(bossV[i].x < 0 || bossV[i].x >= n || bossV[i].y < 0 || bossV[i].y >= m){
                bossV[i].dead(lives);
                //cout << i << " dead \n";
            } //continue to next boss in bossV
            else if(bossV[i].alive){
                bossV[i].move(bombmap);
                for(int j = 0; j < bombmap.size(); j++){
                    if(bossV[i].x == bombmap[j].x && bossV[i].y == bombmap[j].y && bombmap[j].blow != 0){
                        bombmap[j].blow = 1; //goin' 2 be bombed
                        bossV[i].dead(lives); //ded
                        break;
                    }
                }
            }
        }
        for(int i = bombmap.size() - 1; i >= 0; i--) if(bombmap[i].blow == 1) bombmap[i].blow = 0; //erase bomb
    }
    int ans = 0;
    for(int i = 0; i < bombmap.size(); i++) if(bombmap[i].blow) ans++;
    cout << ans;
    return 0;
}