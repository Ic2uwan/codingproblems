#include <bits/stdc++.h>
#define IO ios_base::sync_with_stdio(0), cin.tie(0)

using ll = long long;
using namespace std;
// KMP
int lps[1000005];
int main(){
	string t, p;
	cin >> t;
	cin >> p;
	int len = 0, i = 1;
	while(i < p.size()){
		if(p[i] == p[len]){
			++len;
			lps[i] = len;
			++i;
		}
		else{
			if(len != 0){
				len = lps[len-1];
			}
			else{
				++i;
			}
		}
	}
	// for(int i = 0; i < p.size();++i){
	// 	cout << lps[i] << ' ';
	// }cout << '\n';
	int j = 0, cnt = 0;
	i = 0;
	while(i < t.size()){
		if(p[j] == t[i]){
			++i, ++j;
		}
		if(j == p.size()){
			++cnt;
			j = lps[j - 1];
		}
		else if(i < t.size() && p[j] != t[i]){
			if(j != 0){
				j = lps[j - 1];
			}
			else{
				++i;
			}
		}
	}
	cout << cnt << '\n';
}