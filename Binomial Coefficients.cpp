
#include <bits/stdc++.h>
#define FastIO                  \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);                   \
  cout.tie(0);

#define vll        vector<ll>
#define vii        vector<int>
#define nn         '\n'

#define gcd(a,b)   __gcd(a,b)
#define lcm(a,b)   (a*b) / gcd(a,b)
#define sp         " "

#define sz(x)      (int)x.size()
#define all(x)     (x).begin(), (x).end()
#define rall(x)    (x).rbegin(), (x).rend()


using namespace std;
using ll = long long int;

///--------->>>>>>>>>>>>>>>>>>>>>>>>>>>>>----Modular Arithmetic----<<<<<<<<<<<<<<<<<<<<<<<<<---------------

const  ll MOD = (ll) 1e9 + 7;
inline void normal(ll &a) { a %= MOD; (a < 0) && (a += MOD); }
inline ll modMul(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a*b)%MOD; }
inline ll modAdd(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a+b)%MOD; }
inline ll modSub(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); a -= b; normal(a); return a; }
inline ll modPow(ll b, ll p) { ll r = 1; while(p) { if(p&1) r = modMul(r, b); b = modMul(b, b); p >>= 1; } return r; }
inline ll modInverse(ll a) { return modPow(a, MOD-2); }  /// When MOD is prime.
inline ll modDiv(ll a, ll b) { return modMul(a, modInverse(b)); }

/// Direction_array......
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

///--------->>>>>>>>>>>>>>>>>>>>>>>>>>>>>----The End----<<<<<<<<<<<<<<<<<<<<<<<<<---------------

//const int N =  1e6 + 5;
//bitset<N> marked;
//vll  prime;

///--------->>>>>>>>>>>>>>>>>>>>>>>>>>>>>----MiRaZ_HoSsAiN_ShAhIn----<<<<<<<<<<<<<<<<<<<<<-----------------

//void Sieve()
//{
//    for(int i = 4; i <= N; i+=2) {
//        marked[i] = 1;
//    }
//    for(int i = 3; i * i <= N; i+= 2) {
//        if(!marked[i])
//        for(int j = i * i; j <= N; j += (i << 1)) {
//            marked[j] = 1;
//        }
//    }
//    prime.push_back(2);
//    for(int i = 3; i <= N; i+=2) {
//        if(!marked[i]) {
//            prime.push_back(i);
//        }
//    }
//}
//bool isPrime(ll n) {
//    if(n < 2) return false;
//    return !marked[n];
//}

///---------------------------------------->>>>>---Start---<<<<<---------------------------------------------
const int N = 1e6 + 7;
int fact[N];
void factorial() {
    fact[1] = 1;
    fact[0] = 1;
    for(int i = 1; i < N; i++ ) {
        fact[i] = (fact[i - 1] % MOD * i % MOD) % MOD;
    }
}
void solve() {
    int a, b;
    cin >> a >> b;
    int A = fact[a];
    int B = fact[b];
    int C = fact[a - b];
//    cout << A << sp << B << sp << C << nn;
    int BC = (B % MOD * C % MOD) % MOD;
//    cout << BC << nn;
    a %= MOD;
    ll ans = 1LL * A * modInverse(BC);
    ans %= MOD;
    cout << ans << nn;
}
int32_t main() {
    FastIO;
//    Sieve();
    factorial();
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
