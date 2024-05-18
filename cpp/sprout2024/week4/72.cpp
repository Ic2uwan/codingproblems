#include <bits/stdc++.h>
#define IO ios_base::sync_with_stdio(false); cin.tie(nullptr)
using namespace std;



double func(double t, double *a){
	// cout << a[0] << ' ' << a[1] << ' ' << a[2] << '\n';
	return a[0] * (t - a[1]) * (t - a[1]) + a[2];
}

double d[15][8];
int main(){
	IO;
	int T;
	cin >> T;
	while(T--){
		memset(d, 0, sizeof(d));
		int n;
		cin >> n;
		for(int i = 0; i < n; ++i){
			double a, b, c;
			cin >> a >> b >> c;
			d[i][0] = a, d[i][1] = b, d[i][2] = c;
		}
		/*
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < 3; ++j)
				cout << d[i][j] << ' ';
			cout << '\n';
		}
		*/
		double l = 0, r = 300;
    	double mxmr, mxml;
		for(int i = 0; i < int(1e6); ++i){
			mxmr = -1, mxml = -1;
			double mr = (l + 2*r) / 3.0;
    		double ml = (2*l + r) / 3.0;
			for(int j = 0; j < n; ++j){
    			mxmr = max(mxmr, func(mr, d[j]));
    			mxml = max(mxml, func(ml, d[j]));
			}
			if(mxml > mxmr){
				l = ml;
			}
			else{
				r = mr;
			}
		}
		cout << setprecision(15) << mxml << '\n';
	}
}
