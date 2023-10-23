#include <bits/stdc++.h>
#define ass ios_base::sync_with_stdio(false); cin.tie(0);
#define eb emplace_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

vector<pii> arng;
vector<pii> brng;
vector<pii> a, b;
set<int> ansset;

int main(){
    //ass
    int n, m, q;
    int tmp, tmp1;
    cin >> n >> m;
    a.resize(n);
    b.resize(m);
    for(int i = 0; i < m; i++){
        cin >> tmp >> tmp1;
        a[i] = make_pair(tmp, i);
        b[i] = make_pair(tmp1, i);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    cin >> q;
    for(int i = 0; i < q; i++){
        cin >> tmp >> tmp1;
        arng.eb(make_pair(tmp, tmp1));
        cin >> tmp >> tmp1;
        brng.eb(make_pair(tmp, tmp1));
    }
    //input
    for(int i = 0; i < q; i++){
        int ans = 0;
        auto l = lower_bound(a.begin(), a.end(), arng[i].first);
        //auto r = upper_bound(a.begin(), a.end(), arng[i].second);
        while((*l).first <= arng[i].second){
            ansset.emplace((*l).second);
            l++;
        }
        auto s = lower_bound(b.begin(), b.end(), brng[i].first);
        //auto t = upper_bound(b.begin(), b.end(), brng[i].second);
        while((*s).first <= brng[i].second){
            ansset.emplace((*s).second);
            s++;
        }
        ans = ansset.size();
        ansset.clear();
        cout << ans << '\n';
    }
}