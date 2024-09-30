#include <bits/stdc++.h>
#define FastIO                  \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);                   \
  cout.tie(0);

using ll = long long;
#define nn '\n'
using namespace std;
 

// Constants
const int N = 5e6 + 5;
bitset<N> marked;
vector<int> prime;
int lowest_prime[N] = {0};
int prefix[N] = {0}; 

void Sieve() {
    for (int i = 4; i < N; i += 2) {
        marked[i] = 1; 
        lowest_prime[i] = 2;
    }
    for (int i = 3; i * i < N; i += 2) {
        if (!marked[i]) {
            for (int j = i * i; j < N; j += (i << 1)) {
                marked[j] = 1;
                if (lowest_prime[j] == 0) {
                    lowest_prime[j] = i;
                }
            }
        }
    }
    prime.push_back(2);
    lowest_prime[2] = 2;
    for (int i = 3; i < N; i += 2) {
        if (!marked[i]) {
            lowest_prime[i] = i;
            prime.push_back(i);
        }
    }
}
void factorize_cnt() {
    for (int i = 2; i < N; i++) { 
        int n = i; 
        while(n > 1) {
            int spf = lowest_prime[n];  
            while (n % spf == 0) {
                prefix[i]++;
                n /= spf;   
            }
        }  
    } 
    for (int i = 2; i < N; i++) {
        prefix[i] += prefix[i - 1];
    }
} 
void solve() {
    int a, b;
    cin >> a >> b;
    if(b == 1) {
        cout << prefix[a] << nn;
    } 
    else {
        cout << prefix[a] - prefix[b] << nn;
    }
}
int32_t main() { 
    FastIO;
    Sieve();
    factorize_cnt();
    int test_case = 1;
    cin >> test_case; 
    int Case = 1;
    while(test_case--) {
//    cout << "Case " << Case << ": ";
        solve();
        Case++;
    }
 
    return 0;
}
/*
 * do something instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */
