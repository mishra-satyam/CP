const int mod = 1e9 + 7;
const int N = 1e5+10;

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

typedef struct string_hash
{
    int b = 31, n = 0;
    string_hash(int x){
        b = x;
    }
    int inv[N], hsh[N];

    void hash(const string& s){

        n = sz(s);
        inv[n-1] = power(b, mod-n);
        FORd(i,0,n-1){
            inv[i] = 1ll*b*inv[i+1]%mod;
        }

        int pow = b;
        hsh[0] = 0;
        hsh[1] = s[0]-'a'+1;
        FOR(i,2,n+1){
            hsh[i] = (0ll + hsh[i-1] + 1ll*(s[i-1]-'a'+1)*pow%mod)%mod;
            pow = 1ll*pow*b%mod;
        }

    }

    int gethash(int l, int r){
        int val = (0ll + hsh[r+1] - hsh[l] + mod) % mod;
        val = 1ll * val * inv[l] % mod;
        return val;
    }

}str_hash;
