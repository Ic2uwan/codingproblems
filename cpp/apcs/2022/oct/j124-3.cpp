#include <bits/stdc++.h>
#define IO ios_base::sync_with_stdio(0), cin.tie(0)
#define maxn 100005
#define ll long long

using namespace std;

ll ans = 0;
void dfs(ll last){
	int a;
	cin >> a;
	if(!a) return;
	ans += last ? abs(last - a) : 0;
	if(a&1){
		dfs(a);
		dfs(a);
		dfs(a);
	}
	else{
		dfs(a);
		dfs(a);
	}
}
int main(){
	IO;
	dfs(0);
	cout << ans << '\n';
}