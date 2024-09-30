const int MX = 1e6; 
vector<int> primes;
bitset<MX + 5> mark; 
 
void sieve() {
    int limit = sqrt(MX);
    for (int i = 3; i <= limit; i += 2) {
        if (!mark[i] and (i * i) <= MX) {
            for (int j = i * i; j <= MX; j += (i << 1)) {
                mark[j] = 1;
            }
        }
    }
    primes.push_back(2);
    for (int i = 3; i <= MX; i += 2) {
        if (!mark[i]) primes.push_back(i);
    }
}

bool isPrime(ll n) {
    if(n < 2) return false;
    return !mark[n];
} 
