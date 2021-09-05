int period = 0;
void preproc() {  // Finding Pisano Period
    ull a = 0, b = 1;
    for (ull i = 0; i < MOD * MOD; ++i) {
        ull c = (a + b) % MOD;
        a = b;
        b = c;
        if (a == 0 && b == 1) {
            period = i + 1;
            break;
        }
    }
}

ull getMod(string &n) {    // Finding n%period
    ull num = 0;
    for (auto it = n.begin(); it != n.end(); ++it) {
        num = num * 10;
        num %= period;
        num += ((*it) - '0');
        num %= period;
    }
    return num;
}

pii fib(int n) {    // Finding fib(n)%MOD
    if (n == 0)
        return {0, 1};
    auto p = fib(n >> 1);
    int c = (p.F * ((((2 * p.S) % MOD) - p.F + MOD) % MOD)) % MOD;
    int d = ((((p.F * p.F) % MOD) + ((p.S * p.S) % MOD)) % MOD);
    if (n & 1)
        return {d, (c + d) % MOD};
    else
        return {c, d};
}

void solve() {
    string n;
    cin >> n;
    int f = getMod(n);
    cout << fib(f).F << endl;
}
