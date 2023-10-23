#include <iostream>
#include <vector>

using namespace std;

struct cpos{
    char name;
    pair<int, int> xy;
    cpos(){}
    cpos(char a, pair<int, int> b){
        name = a;
        xy = b;
    }
};

void insertVec(vector<cpos> &result, cpos x){
    if (result.empty()) {
        result.push_back(x);
        return;
    }
    else{
        for(size_t i = 0; i < result.size(); i++){
            if(x.name < result[i].name && i == 0){
                result.insert(result.begin(), x);
                break;
            }
            else if(x.name > result[i].name && i == result.size()-1){
                result.push_back(x);
                break;
            }
            else if(x.name > result[i-1].name && x.name < result[i].name){
                result.insert(result.begin()+i, x);
                break;
            }
        }
    }
}

int main(){
    int w, h, n;
    cin >> w >> h >> n;
    vector<cpos> result;
    int num = 0;
    char map[w][h];
    for(int i = 0; i < w; i++){
        for (int j = 0; j < h; j++){
            cin >> map[i][j];
            if(map[i][j] != '0'){
                insertVec(result, cpos(map[i][j], {i, j}));
                //cout << i << ' ' << j << '\n';
                num++;
            }
        }
    }
    if(num < n) cout << "Mission fail.";
    else for(int i = 0; i < n; i++) cout << result[i].xy.first << ' ' << result[i].xy.second << '\n';
}