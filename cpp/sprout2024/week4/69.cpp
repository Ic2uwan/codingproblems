#include <bits/stdc++.h>
#define IO ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define ll long long
using namespace std;

ll c[10005];
ll a[10005], b[10005];
ll d[10005];


int N, K;
int srch(int day){
	memset(d, 0, sizeof(d));
	for(int i = 0; i < N; ++i){
		d[i] = a[i] + day * b[i];
	}
	sort(d, d+N, greater<ll>());
	// for(int i = 0; i < N; ++i) cout << c[i] << ' ';
	// cout << '\n';
	auto ptr = lower_bound(c, c+N, d[0], greater<ll>());
	if(ptr == c+N) return 0;
	// cout << "ptr is " << *ptr << '\n';
	int cnt = 0;
	while(ptr != c+N){
		// cout << "in \n";
		// cout << "ptr is " << *ptr << '\n';
		if(*ptr < d[cnt]){
			++cnt;
			if(cnt == K) return cnt;
		}
		++ptr;
	}
	return cnt;
}
int main(){
	IO;
	int T;
	cin >> T;
	while(T--){
		memset(c, 0, sizeof(c));
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		cin >> N >> K;
		for(int i = 0; i < N; ++i){
			cin >> a[i] >> b[i];
		}
		for(int i = 0; i < N; ++i){
			cin >> c[i];
		}
		sort(c, c+N, greater<ll>());
		int dayl = 0, dayr = int(1e8), mid;
		int ans = -1;
		while(dayl <= dayr){
			mid = (dayl+dayr)/2;
			int val = srch(mid);
			// cout << dayl << ' ' << mid << ' ' << dayr << ' ' << val << ' ' << K << '\n';
			if(K > val){
				dayl = mid + 1;
			}
			else{
				ans = mid;
				dayr = mid - 1;
			}
		}
		cout << ans << '\n';
	}
}
