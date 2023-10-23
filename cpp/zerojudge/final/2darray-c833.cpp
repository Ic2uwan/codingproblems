#include <iostream>
#include <string.h>

using namespace std;
int main(){
    size_t n, m;
    cin >> n >> m;
    char c[n], r[m], in[n];
    memset(r, 0, sizeof(r));
    memset(c, 0, sizeof(c));
    for(size_t i = 0; i < n; i++){
        cin >> in;
        for(size_t j = 0; j < m; j++){
            if(in[j] == '#'){
                r[i] = 1;
                c[j] = 1;
            }
        }
    }
    for(size_t i = 0; i < n; i++){
        for(size_t j = 0; j < m; j++){
            putchar((r[i] == 1 || c[j] == 1) ? '#' : 'X');
        }
    putchar('\n');
    }
}