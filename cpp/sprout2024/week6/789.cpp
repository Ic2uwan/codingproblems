#include <bits/stdc++.h>
#define IO ios_base::sync_with_stdio(0), cin.tie(nullptr)
#define ll long long
using namespace std;

int N;
int arr[100005];
int tmp[100005];
void fun(int L,int R){
    if(R-L<=1) return;
    int idx = L, M = (L+R) / 2;
    for(int i = L; i <= R; ++i){
        tmp[i] = arr[i];
    }
    for(int i = L; i <= R; i += 2){
        arr[idx++] = tmp[i];
    }
    for(int i = L+1; i <= R; i += 2){
        arr[idx++] = tmp[i];
    }
    fun(L, M);
    fun(M+1, R);
}

int main(){
    IO;
    cin >> N;
    for(int i = 0; i < N; ++i)
        arr[i] = i+1;

    fun(0, N-1);

    for(int i = 0; i < N-1; ++i)
        cout << arr[i] << " ";
	cout << arr[N-1] << '\n';
}