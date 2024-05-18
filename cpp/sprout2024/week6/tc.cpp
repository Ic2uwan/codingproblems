#include <bits/stdc++.h>
#include <random>

using namespace std;
int main(){
	// Create a random number generator
	mt19937 rng(random_device{}());

	// Create a distribution. This will 'shape' your random number.
	uniform_int_distribution<int> dist(0, 1000000000); // 10^9

	cout << 1000 << '\n';
	int i = 1000;
	while(i--){
		cout << ' ' << dist(rng);
	}
}