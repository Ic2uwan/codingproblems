#include <bits/stdc++.h>
	using namespace std;
	typedef long long ll;
	 
	queue<ll> goal;
	stack<ll> s;
	 
	int main() {
	    while (true) {
	        ll n;
	        (void)!scanf("%lld", &n);
	        if (!n) {
	            int a = 1;
	        }
	        if (!n) break;
	        
	        while (true) {
	            goal = queue<ll>();
	            s = stack<ll>();
	            for (ll i = 0; i < n; i++) {
	                ll x;
	                (void)!scanf("%lld", &x);
	                if (!x) goto newround;
	                goal.push(x);
	            }
	            
	            for (ll i = 1; i <= n; i++) {
	                if (i == goal.front()) {
	                    goal.pop();
	                    while (!s.empty() && !goal.empty() && s.top() == goal.front()) {
	                        goal.pop();
	                        s.pop();
                            cout << "popped \n";
	                    }
	                }
	                else s.push(i);
	            }
	            if (s.empty()) printf("Yes\n");
	            else printf("No\n");
	        }
	        
	newround:
	        printf("\n");
	    }
	}