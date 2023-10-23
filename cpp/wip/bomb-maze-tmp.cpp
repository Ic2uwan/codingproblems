#include <iostream>
#include <vector>

using namespace std;
int main() {
    /*
        int [100][100] bombmap
        vector<pair<int, int>> explodedbomb
        vector<Boss> boss

        read map boundary max_x, max_y // 0: no bomb, 1: has bomb, -1:exploded and need to be cleared before next round
        read boss

while(!boss.empty())
        moveeveryboss(boss, bombmap)
            for every boss
                bombmap[boss[i].x][boss[i].y] = 1
                boss[i].x += boss[i].s
                boss[i].y += boss[i].t
                if boss[i] out of boundary
                    remove boss[i]

        checkexplosion(boss, bombmap)
            for every boss
                if bombmap[boss[i].x][boss[i].y] != 0
                    bombmap[boss[i].x][boss[i].y] = -1
                    explodedbomb.push_back( {boss[i].x, boss[i].y} )
                    remove boss[i]

        clearbomb(bombmap, explodedbomb)
            for every explodedbomb
                bombmap[explodedbomb[i].x][explodedbomb[i].y] = 0
                remove explodedbomb[i]
endwhile

        int bombslot

        for 0 <= i <= max_x
            for 0 <= j <= max_y
                if bombmap[i][j] == 1
                    bombslot++        
            
    */
}