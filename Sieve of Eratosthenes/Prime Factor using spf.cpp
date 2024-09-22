#include <bits/stdc++.h>
#define FastIO                  \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);                   \
  cout.tie(0); 

using ll = long long; 
#define nn      '\n'  
using namespace std; 

const int N = 1e6 + 5;
bitset<N> marked;
vector<int> prime; 
int lowest_prime[N] = {0};
void Sieve() {
    for(int i = 4; i <= N; i+=2) {
        marked[i] = 1; 
        lowest_prime[i] = 2;
    }
    for(int i = 3; i * i <= N; i+= 2) {
        if(!marked[i]) { 
            for(int j = i * i; j <= N; j += (i << 1)) {
              marked[j] = 1; 
              if(lowest_prime[j] == 0) { 
                   lowest_prime[j] = i;
              }
            }
        }
    }
    prime.push_back(2);
    lowest_prime[2] = 2;
    for(int i = 3; i <= N; i+=2) {
        if(!marked[i]) { 
            lowest_prime[i] = i;
            prime.push_back(i);
        }
    }
} 
void solve() {  
    int n; cin >> n;
    vector<int> prime_factor;
    while(n > 1) {
        int spf = lowest_prime[n];
        while(n % spf == 0) {
            n /= spf;
            prime_factor.push_back(spf);
        }
    }
    for(auto &it : prime_factor) cout << it << " ";
    cout << endl;
}
int32_t main() {
    FastIO;   
    Sieve(); 
    int test_case = 1; 
   // cin >> test_case;  
    while (test_case--) {
        solve();
    }

    return 0;
}
