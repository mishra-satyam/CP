const ll mod = 1e9+7;

/*
int fast_pow(int a, int p) {
  int res = 1;
  while (p) {
    if (p % 2 == 0) {
      a = a * 1ll * a % mod;
      p /= 2;
    } else {
      res = res * 1ll * a % mod;
      p--;
    }
  }
  return res;
}
*/

int power(int x, int y){
    int res = 1;     // Initialize result
    while (y){
        // If y is odd, multiply x with result
        if (y & 1)
            res = res * 1ll * x % mod;

        // y must be even now
        y = y>>1; // y = y/2
        x = x * 1ll * x % mod;  // Change x to x^2
    }
    return res;
}

int moddiv(int a, int b){
    return a * 1ll * power(b, mod - 2) % mod;
}


int C(int n, int k) {
    return fact(n) * 1ll * power(fact(k), mod - 2) % mod * 1ll * power(fact(n - k), mod - 2) % mod;
}


// preprocessing m power n in mod
int m_pow_n[210][410];
int tmp = 1;
FOR(i,0,210){
    tmp = i;
    m_pow_n[i][0] = 1;
    FOR(j,1,410){
        m_pow_n[i][j] = tmp;
        tmp = (tmp * 1ll * i) % mod;
    }
}


int fact(int n) {
    int res = 1;
    for (int i = 1; i <= n; i++) {
    res = res * 1ll * i % mod;
    }
    return res;
}


// N => number of values of factorial
// to be precomputed under modulous of mod
int fact[N], invfact[N];
void precompute(){
    fact[0] = 1;
    int i;
    // FOR(i,1,N){
    for(i=1;i<N;i++){
        fact[i] = fact[i-1] * 1ll * i %  mod;
    }
    i--;
    invfact[i] = power(fact[i], mod-2);
    for(i--; i>=0; i--){
        invfact[i] = invfact[i+1] * 1ll * (i+1) % mod;
    }
}

int ncr(int n, int r){
    if (r>n || n<0 || r<0) return 0;
    return fact[n] * 1ll * invfact[r] % mod * 1ll * invfact[n-r] % mod;
}

// preprocessing ncj in mod
int ncj[210][210];
// nCj = n-1Cj + n-1Cj-1
// 0 <= n <= 210
// 0c0 = 1
ncj[0][0] = 1;
FOR(i,1,210){
    ncj[i][0] = 1;
    FOR(j,1,i){
        ncj[i][j] = (ncj[i-1][j] + ncj[i-1][j-1]) % mod;
    }
    ncj[i][i] = 1;
}

FOR(i,0,210){
    cout << "\ni = " << i << "\n";
    FOR(j,0,i+1){
        // cout << "j = " << j << " ";
        cout << ncj[i][j] << " ";
    }
}
