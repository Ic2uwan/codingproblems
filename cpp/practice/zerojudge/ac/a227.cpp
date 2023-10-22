#include <bits/stdc++.h>

using namespace std;


void hanoi(int n, char A, char B, char C){
	if(n == 0) return;
	hanoi(n - 1, A, C, B);
	cout << "Move ring " << n << " from " << A << " to " << C << '\n';
	hanoi(n - 1, B, A, C);
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	while(cin >> n){
		hanoi(n, 'A', 'B', 'C');
		cout << '\n';
	}
}
