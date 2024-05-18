#include <bits/stdc++.h>
#define IO ios_base::sync_with_stdio(0), cin.tie(nullptr)
#define ll long long
#define pii pair<int, int>
#define ff first
#define ss second
using namespace std;

bool mp[1024][1024];
// void Report(int a, int b, int c, int d, int e, int f) {
//     cout << "Report: " << a << ", " << b << ", " << c << ", " << d << ", " << e << ", " << f << endl;
// 	for(int i = 0; i < 4; ++i) {
//         for(int j = 0; j < 4; ++j) {
//             cout << mp[i][j] << ' ';
//         }
//         cout << '\n';
//     }
// 	cout << '\n';
// }
// (grid size, starting x, starting y, assigned x, assigned y)
void dnc(int n, int x, int y, int aX, int aY){
	if(n <= 1) return;
	int nN = n / 2;
	int Q, xf = false, yf = false;
	int nX = x+nN, nY = y+nN;
	if(aX >= nX) xf = true;
	if(aY >= nY) yf = true;
	pii ass[5];
	ass[1] = {nX-1, nY-1};
	ass[2] = {nX-1, nY};
	ass[3] = {nX, nY-1};
	ass[4] = {nX, nY};
	bool og[5];
	og[1] = mp[nX-1][nY-1];
	og[2] = mp[nX-1][nY];
	og[3] = mp[nX][nY-1];
	og[4] = mp[nX][nY];
	mp[nX-1][nY-1] = 1;
	mp[nX-1][nY] = 1;
	mp[nX][nY-1] = 1;
	mp[nX][nY] = 1;
	if(xf){
		if(yf)
			Q = 4;
		else
			Q = 3;
	}else{
		if(yf)
			Q = 2;
		else
			Q = 1;
	}
	mp[ass[Q].ff][ass[Q].ss] = og[Q];
	ass[Q] = {ass[4].ff, ass[4].ss};
	Report(ass[1].ff+1, ass[1].ss+1, ass[2].ff+1, ass[2].ss+1, ass[3].ff+1, ass[3].ss+1);
	ass[Q] = {aX, aY};
	dnc(nN, x, y, ass[1].ff, ass[1].ss);
	dnc(nN, x, nY, ass[2].ff, ass[2].ss);
	dnc(nN, nX, y, ass[3].ff, ass[3].ss);
	dnc(nN, nX, nY, ass[4].ff, ass[4].ss);
}

void solve(int N, int X, int Y){
	memset(mp, 0, sizeof(mp));
	mp[X-1][Y-1] = 1;
	dnc(N, 0, 0, X-1, Y-1);
}
// int main() {
//     solve(4, 3, 4);
//     return 0;
// }