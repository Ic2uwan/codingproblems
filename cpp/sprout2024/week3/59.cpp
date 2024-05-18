#include <bits/stdc++.h>
#define IO ios_base::sync_with_stdio(0), cin.tie(nullptr)

using namespace std;

priority_queue<int, vector<int>, greater<int>> heap;
int main(){
	IO;
	int n;
	cin >> n;
	while(n--){
		int in;
		cin >> in;
		if(in == 1){
			cin >> in;
			heap.push(in);
		}
		else if(in == 2){
			if(heap.empty()){
				cout << "empty!\n";
			}
			else{
				cout << heap.top() << '\n';
				heap.pop();
			}
		}
	}
}
