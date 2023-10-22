#include <bits/stdc++.h>
#define n 9
using namespace std;


array<int, n> a = {0, 1, 9, 6, 5, 5, 4, 1, 3};
array<int, n * 4> seg;

void pull(int id){
    seg[id] = seg[id * 2] + seg[id * 2 + 1];
}

void build(int L, int R, int id = 1){
    if(L == R){
        seg[id] = a[L];
        return;
    }
    int M = (L + R) / 2;
    build(L, M, id * 2);
    build(M + 1, R, id * 2 + 1);
    pull(id);
}
int query(int ql, int qr, int L, int R, int id){
    if(qr < L || R < ql) return 0;
    if(ql <= L && R <= qr) return seg[id];
    int M = (L + R) / 2;
    return query(ql, qr, L, M, id * 2) + query(ql, qr, L, M, id * 2 + 1);
}

void prtSeg(){
    int cnt = 1;
    int now = 0;
    for(auto i : seg){
        if(i != 0){
            cout << i << ' ';
            now++;
            if(now == cnt){
                cout << '\n';
                cnt *= 2;
                now = 0;
            }
        }
    }
}

int main(){
    build(1, 8);
    prtSeg();
    cout << query(3, 5, 1, 8, 4);

}