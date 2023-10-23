#include <bits/stdc++.h>
#define optio ios_base::sync_with_stdio(0); cin.tie(0)
#define eb emplace_back

#define MAXN int(1e5)
#define MAXM int(1e5)

// longest common subsequence

using namespace std;
int a[MAXN], b[MAXM], fn[MAXN][MAXM];

int n, m;

int dp(){
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            if(a[i] == b[j])
                fn[i][j] = fn[i - 1][j - 1] + 1;

}

int main(){
    optio;
}
