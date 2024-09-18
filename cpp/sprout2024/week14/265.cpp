#include <bits/stdc++.h>
using namespace std;

const int D = 256;
const int Q = 97;

void search(const string& pat, const string& txt) {
	int M = pat.size();
	int N = txt.size();
	int i, j;
	int p = 0;  
	int t = 0;  
	int h = 1;

	for (i = 0; i < M - 1; i++)
		h = (h * D) % Q;

	for (i = 0; i < M; i++) {
		p = (D * p + pat[i]) % Q;
		t = (D * t + txt[i]) % Q;
	}

	for (i = 0; i <= N - M; i++) {
		if (p == t) {
			for (j = 0; j < M; j++) {
				if (txt[i + j] != pat[j])
					break;
			}

			if (j == M)
				cout << i << ' ';
		}

		if (i < N - M) {
			t = (D * (t - txt[i] * h) + txt[i + M]) % Q;
			if (t < 0)
				t = (t + Q);
		}
	}
}

int main() {
	string txt;
	string pat;
	cin >> pat;
	cin >> txt;
	search(pat, txt);
	cout << '\n';
	return 0;
}