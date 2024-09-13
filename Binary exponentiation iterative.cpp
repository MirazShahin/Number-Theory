#include <bits/stdc++.h>
using namespace std; 
const int MOD = 1e9 + 7;
long long binary_exp(int a, int b) {
    long long ans = 1;
    while(b > 0) {
        if((b & 1)) {
            ans *= a;
        }
        a *= a;
        b >>= 1;
    }
    return ans;
}
void solve() { 
    cout << binary_exp(2, 13) << endl;
}
int32_t main() { 
    int test_case = 1;
    //cin >> test_case;
    int Case = 1;
    while(test_case--) {
        //cout << "Case " << Case << ": ";
        solve();
        Case++;
    }
    return 0;
}
