#include <bits/stdc++.h>
#define FastIO                  \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);                   \
  cout.tie(0);
 
using namespace std;
using ll = long long int;

const int N = 1e6 + 5;
int cnt[N];
void divisor_cnt() {
   for(int i = 1; i <= N; i++ ) {
        for(int j = i; j <= N; j +=i ) {
            cnt[j]++;
        }
    }
} 
void solve()
{
    int n;
    cin >> n;
    cout << cnt[n] << nn;
}
int32_t main()
{
    FastIO;
    divisor_cnt();
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
