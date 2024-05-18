#include <bits/stdc++.h>
#define IO ios_base::sync_with_stdio(false), cin.tie(nullptr)
#define ll long long
#define pll pair<ll, ll>
#define xx first
#define yy second

using namespace std;


int x, y, px, py;
int getdir(){
	int dir;
	if(x > px)
		dir = 0;
	else if(x < px)
		dir = 2;
	else if(y < py)
		dir = 1;
	else 
		dir = 3;
	return dir;
}
int main(){
	IO;
	int N;
	cin >> N;
	int lT = 0, rT = 0, uT = 0;
	int dir, pdir; // E, S, W, N = 0, 1, 2, 3
	
	
	
	cin >> px >> py;
	cin >> x >> y;
	pdir = getdir();
	x = px, y = py;
	for(int i = 2; i < N; ++i){
		cin >> x >> y;
		dir = getdir();
		if((pdir-dir+4)%4==2) ++uT;
		else if((pdir-dir+4)%4==1) ++rT;
		else if((pdir-dir+4)%4==3) ++lT;
		px = x, py = y, pdir = dir;
	}
	cout << lT << ' ' << rT << ' ' << uT << '\n';
}