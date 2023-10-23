#include <iostream>
#include <vector>

using namespace std;

enum dir{
    up,
    down,
    left,
    right
};
struct mirror{
    int x, y;
    bool state; // 0 = '/', 1 = '\'
    mirror(int _x, int _y, bool _state){
        x = _x;
        y = _y;
        state = _state;
    }
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
    vector<mirror> mirrorV;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x >> y >> t;
        mirrorV.push_back(mirror(x, y, t));
    }
    int laser[3] = {0, 0, dir::right}; //{x, y, direction}
    while(mirrorFound){
        mirrorFound = false;
        minDist = 0;
        minI = 0;
        //cout << "now " << laser[0] << ' ' << laser[1] << "direction " << laser[2] << '\n';
        switch(laser[2]){
            case dir::up:
                for(int i = 0; i < n; i++){
                    if(mirrorV[i].x == laser[0] && mirrorV[i].y > laser[1]){
                        mirrorFound = true;
                        findMin(minDist, mirrorV[i].y - laser[1], minI, i);
                    }
                }
                break;
            case dir::down:
                for(int i = 0; i < n; i++){
                    if(mirrorV[i].x == laser[0] && mirrorV[i].y < laser[1]){
                        mirrorFound = true;
                        findMin(minDist, laser[1] - mirrorV[i].y, minI, i);
                    }
                }
                break;
            case dir::left:
                for(int i = 0; i < n; i++){
                    if(mirrorV[i].y == laser[1] && mirrorV[i].x < laser[0]){
                        mirrorFound = true;
                        findMin(minDist, laser[0] - mirrorV[i].x, minI, i);
                    }
                }
                break;
            case dir::right:
                for(int i = 0; i < n; i++){
                    if(mirrorV[i].y == laser[1] && mirrorV[i].x > laser[0]){
                        mirrorFound = true;
                        findMin(minDist, mirrorV[i].x - laser[0], minI, i);
                    }
                }
                break;
        }
        if(mirrorFound){
            //cout << "hit mirror at " << mirrorV[minI].x << ' ' << mirrorV[minI].y;
            laser[0] = mirrorV[minI].x;
            laser[1] = mirrorV[minI].y;
            laser[2] = turn[mirrorV[minI].state][laser[2]];
            count++;
        }
    }
    cout << count;
}
//    while mirrorFound
//        mirrorFound = false
//        switch direction
//            case up
//                i iterates through mirrorV
//                    condition i.x == laser.x, i.y higher than laser.y
//                        mirrorFound = true
//
//                        find the min of distance{
//                            min(mindist, i.y - laser.y)
//                            minI = the closest i
//                        }
//            case down
//                i iterates through mirrorV
//                    condition i.x == laser.x, i.y less than laser.y
//                        mirrorFound = true
//
//                        find the min of distance{
//                            min(mindist, laser.y - i.y)
//                            minI = the closest i
//                        }
//            case left
//                i iterates through mirrorV
//                    condition i.y == laser.y, i.x less than laser.x
//                        mirrorFound = true
//
//                        find the min of distance{
//                            min(mindist, laser.x - i.x)
//                            minI = the closest i
//                        }
//            case right
//                i iterates through mirrorV
//                    condition i.y == laser.y, i.x greater than laser.x
//                        mirrorFound = true
//
//                        find the min of distance{
//                            min(mindist, laser.x - i.x)
//                            minI = the closest i
//                        }
//        end switch
//        if mirrorFound{
//            turn[2][4] = condition of turing
//            direction = turn[mirrorV[minI].state][direction]
//            count++
//        }
//    end while
//    print count
