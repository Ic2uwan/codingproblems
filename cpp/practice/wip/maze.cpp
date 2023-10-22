#include <iostream>
#include <vector>
#include <array>
using namespace std;

int count;
void bombCheck(vector<pair<int, int>> &bomb, array<int, 5> &boss){
    cout << bomb.size() << '\n';
    for(int i = 0; i < bomb.size(); i++){
        if(bomb[i].first == boss[0] && bomb[i].second == boss[1]){
            bomb.erase(bomb.begin() + i);
            cout << bomb.size() << "erased \n";
            boss[4] = 1;
            count--;
        }
    }
}

void move(vector<pair<int, int>> &bomb, array<int, 5> &boss, int m, int n){
    bomb.push_back({boss[0],boss[1]});
    boss[0] += boss[2];
    boss[1] += boss[3];
    bombCheck(bomb, boss);
    if(boss[0] > m || boss[1] > n){
        boss[4] = 1;
        count--;
    }
}

int main() {
    vector<pair<int, int>> bomb;
    int n, m, k;
    cin >> n >> m >> k;
    count = k;
    array<int, 5> boss;
    boss[4] = 0;
    vector<array<int, 5>> bosses;
    for(int i = 0; i < k; i++){
        cin >> boss[0] >> boss[1] >> boss[2] >> boss[3];
        bosses.push_back(boss);
    }
    while(count < 0){
        cout << count;
        for(int i = 0; i < k; i++){
            if(bosses[i][4] == 0)
            move(bomb, bosses[i], m, n);
        }
    }
    cout << bomb.size();
}