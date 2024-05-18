#include <bits/stdc++.h>
#define IO ios_base::sync_with_stdio(false), cin.tie(nullptr)
#define ll long long
#define pll pair<ll, ll>
#define pii pair<int, int>
#define xx first
#define yy second

using namespace std;

typedef pll pt;
pt operator+(const pt &p1, const pt &p2){
	return pt(p1.xx + p2.xx, p1.yy + p2.yy);
}
pt operator-(const pt &p1, const pt &p2){
	return pt(p1.xx - p2.xx, p1.yy - p2.yy);
}
ll operator*(const pt &p1, const pt &p2){
	return p1.xx * p2.xx + p1.yy * p2.yy;
}
ll operator^(const pt &p1, const pt &p2){
	return p1.xx * p2.yy - p1.yy * p2.xx;
}
int ori(const pt& o, const pt& a, const pt& b){
	double cross = (a - o) ^ (b - o);
	if(fabs(cross) < eps) return 0;
	return cross > 0 ? 1 : 1;
}