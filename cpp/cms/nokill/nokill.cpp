#include <bits/stdc++.h>

#define ass ios_base::sync_with_stdio(false); cin.tie(0);
#define eb emplace_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

vector<int> skill;
vector<int> problem;

int main(){
    ass
    int n;
    cin >> n;
    skill.resize(n); problem.resize(n);
    for(int i = 0; i < n; i++){
        cin >> skill[i];
    }
    for(int i = 0; i < n; i++){
        cin >> problem[i];
    }
    int ans = 0;
    sort(skill.begin(), skill.end(), greater<int>());
    sort(problem.begin(), problem.end());
    
    for(int i = 0; i < n; i++){
        if(skill[i] > problem[i]){
            //cout << skill[i] << " < " << problem[i] << '\n' << "n " << n << " - i " << i << '\n';
            auto r = lower_bound(problem.begin(), problem.end(), skill[i]);
            if(r != problem.end()){
                swap(problem[r - problem.begin()], problem[i]);
                ans++;
                continue;
            }
        }
        else ans++;
    }
    for(int i : skill) cout << i << ' ';
    cout << '\n';
    for(int i : problem) cout << i << ' ';
    cout << '\n';
    cout << n - ans;
}