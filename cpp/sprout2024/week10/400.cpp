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
// dot
ll operator*(const pt &p1, const pt &p2){
	return p1.xx * p2.xx + p1.yy * p2.yy;
}
// cross
ll operator^(const pt &p1, const pt &p2){
	// cout << "cross product of " << p1.xx << p1.yy << p2.xx << p2.yy << " is " <<p1.xx * p2.yy - p1.yy * p2.xx << '\n';
	return p1.xx * p2.yy - p1.yy * p2.xx;
}

int lT = 0, uT = 0, rT = 0;
void trn(pt p1, pt p2, pt p3){
	pt v1 = p2 - p1;
	pt v2 = p3 - p2;
	ll prod = v1^v2;
	if(prod > 0){
		++lT;
	}
	else if(prod < 0){
		++rT;
	}
	// straight or u-turned
	// if v1*v2 < 0
	else if(v1 * v2 < 0){
		++uT;
	}
	return;
}

int main(){
	IO;
	int N;
	cin >> N;
	pt pp, cp, np;
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	pp = {a, b}, cp = {c, d};
	for(int i = 2; i < N; ++i){
		cin >> a >> b;
		np = {a, b};
		trn(pp, cp, np);
		pp = cp;
		cp = np;
	}
	cout << lT << ' ' << rT << ' ' << uT << '\n';
}