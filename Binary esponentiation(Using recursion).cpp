#include <bits/stdc++.h>
using namespace std; 
const int MOD = 1e9 + 7;

long long binary_exp(int a, int b) {
    if(b == 0) return 1;
    long long res = binary_exp(a, b / 2);
    if((b & 1)) {
        return (a * (res * res) % MOD) % MOD;
    }
    else {
        return (res * res) % MOD;
    }
}
void solve() { 
    cout << binary_exp(2, 13) << endl;
}
int32_t main() { 
    solve();
    return 0;
}
