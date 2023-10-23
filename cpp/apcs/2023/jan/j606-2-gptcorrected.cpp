#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int k, q, r;
    int in;
    string s;
    cin >> k >> q >> r;
    cin >> s;

    vector<string> lis(q + 1); // Change the vector to store strings and reserve space
    lis[0] = s; // Assign the initial string

    for (int i = 0; i < q; i++) {
        vector<char> str(k, ' '); // Create a vector of characters with k elements, initialized with spaces
        for (int j = 0; j < k; j++) {
            cin >> in;
            str[in - 1] = lis[i][j];
        }
        lis[i + 1] = string(str.begin(), str.end()); // Convert the character vector to a string and assign it
    }

    for (int j = 0; j < r; j++) {
        for (int i = 1; i <= q; i++) {
            cout << lis[i][j];
        }
        cout << '\n';
    }
}
