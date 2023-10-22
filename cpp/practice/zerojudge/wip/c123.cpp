#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main() {
    int n;
    int tmp;
	bool amogus;
    while(true) {
		cin >> n;
		if(n == 0) break;
        while(true){
			stack<int> s;
			queue<int> goal;
			for(int i = 0; i < n; i++) {
				cin >> tmp;
				if(tmp == 0) goto nextcase;
				goal.push(tmp);
			}
			for(int i = 1; i <= n; i++) {
				if(i == goal.front()){
					goal.pop();
					while(!goal.empty() && !s.empty() && s.top() == goal.front()) {
						goal.pop();
						s.pop();
					}
				}
				else s.push(i);
			}
			if (s.empty()) cout << "Yes\n";
			else cout << "No\n";
		}
		nextcase:
			cout << '\n';
	}
	return 0;
}