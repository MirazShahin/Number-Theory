 
const int M = 5000000;
int phi[M + 2]; 
void PHI() {
  for (int i = 2; i <= M; i++) {
    phi[i] = i;
  }
  for (int p = 2; p <= M; p++) {
    if (phi[p] == p) { // p is a prime
      for (int k = p; k <= M; k += p) {
        phi[k] -= phi[k] / p;
      }
    }
  }
} 
