#include <bits/stdc++.h>
#define IO ios_base::sync_with_stdio(0), cin.tie(nullptr)
#define ll long long
#define mod 10000019
using namespace std;

ll seq[int(1e6+5)];
unsigned ll sum = 0;

void ms(ll L, ll R){
	if(L+1==R) return;
	ll M = (L+R)/2;
	ms(L, M);
	ms(M, R);
	ll iL = L, iR = M;
	ll tmp[R-L+1], idx = 0;
	unsigned ll pf[R-M+1];
	pf[0] = 0;
	for(ll i = M; i < R; ++i){
		pf[i-M+1] = (pf[i-M] + seq[i]) % mod;
	}
	while(iL < M){
		// for(ll i = M; i < iR; ++i){
		// 	sum += (seq[iL] + seq[i]) % mod;
		// 	// cout << seq[iL] << " + " << seq[i] << '\n';
		// }
		while(iR < R && seq[iL] > seq[iR]){
			// sum += (seq[iL] + seq[iR]) % mod;
			// cout << seq[iL] << " + " << seq[iR] << '\n';
			// sum %= mod;
			tmp[idx++] = seq[iR++];
		}
		sum = (sum + pf[iR-M]) % mod;
		sum = sum + (seq[iL]*(iR-M)) % mod;
		tmp[idx++] = seq[iL++];
	}
	while(iR < R){
		tmp[idx++] = seq[iR++];
	}
	for(ll i = L; i < R; ++i){
		seq[i] = tmp[i - L];
	}
}

int main(){
	IO;
	ll N;
	cin >> N;
	memset(seq, 0, sizeof(seq));
	for(ll i = 0; i < N; ++i){
		cin >> seq[i];
	}
	ms(0, N);
	// for(ll i = 0; i < N; ++i){
	// 	cout << seq[i] << ' ';
	// }
	cout << sum%mod << '\n';
}