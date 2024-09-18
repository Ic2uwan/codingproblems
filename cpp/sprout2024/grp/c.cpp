#include <bits/stdc++.h>
#define IO ios_base::sync_with_stdio(0), cin.tie(0);
#define int long long
#define mxn 100005
using namespace std;

int N, M;
vector<tuple<int, int, int>> measurements;

bool isValid(int x, int y) {
    for (auto [xi, yi, di] : measurements) {
        if (abs(x - xi) + abs(y - yi) != di) {
            return false;
        }
    }
    return true;
}

signed main() {
    IO;
    cin >> N >> M;
    
    int x, y, d;
    for (int i = 0; i < M; ++i) {
        cin >> x >> y >> d;
        measurements.emplace_back(x, y, d);
    }
    
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            if (isValid(i, j)) {
                cout << i << ' ' << j << '\n';
                return 0;
            }
        }
    }
}