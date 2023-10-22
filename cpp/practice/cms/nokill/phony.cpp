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
    
    auto a = lower_bound(problem.begin(), problem.end(), skill[0]);
    if(a == problem.end()) ans = 0;
    else ans = a - problem.begin();
    cout << ans;
}