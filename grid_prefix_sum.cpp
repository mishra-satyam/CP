const int N = 1e6+10;
vl a[N];
vl ps[N];
ll ans;

ll n, m, k, t;
cin >> n >> m >> k;
a[0].resize(m+1);
FOR(i,1,n+1){
    a[i].clear();
    a[i].pb(0);
    FOR(j,1,m+1){
        cin >> t;
        a[i].pb(t);
    }
}

FOR(i,0,n+1){
    debug(i, a[i]);
}

ps[0].resize(m+1);
FOR(i,1,n+1){
    ps[i].clear();
    ps[i].pb(0);
    FOR(j,1,m+1){
        t = a[i][j] + ps[i][j-1] + ps[i-1][j] - ps[i-1][j-1];
        ps[i].pb(t);
    }
}

FOR(i,0,n+1){
    debug(i, ps[i]);
}

ans = 0;
FOR(i,1,n+1){
    FOR(j,1,m+1){
        ll l = 1, r = min(m-j, n-i)+1, len = min(m-j, n-i)+1;
        ll tmp = len+1;
        while(l <= r){
            ll mid = (l+r)/2;
            if ( (ps[i+mid-1][j+mid-1] + ps[i-1][j-1] - ps[i-1][j+mid-1] - ps[i+mid-1][j-1] ) >= (1ll * k * mid * mid)){
                tmp = mid;
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        ans += (len - tmp + 1);
    }
}
cout << ans << "\n";


//////////////////////////////////////////////////////////////////
typedef struct partial_sum {
	int n, m;
    vector<vector<int>> ps;
	partial_sum(vector<vector<int>> a) {
        n = sz(a);
        m = sz(a[0]);
        ps.resize(n+1);
        ps[0].resize(m+1);
        int t;
        FOR(i,1,n+1){
            ps[i].clear();
            ps[i].pb(0);
            FOR(j,1,m+1){
                t = a[i-1][j-1] + ps[i][j-1] + ps[i-1][j] - ps[i-1][j-1];
                ps[i].pb(t);
            }
        }
	}

    int sum(int i1, int j1, int i2, int j2) {
        i1++, i2++, j1++, j2++;
        if (i1 > i2 || j1 > j2) swap(i1, i2), swap(j1, j2);

        // i1, j1  i2, j2
        assert(i1<=i2 and j1<=j2);
        return (ps[i2][j2] - ps[i1-1][j2] - ps[i2][j1-1] + ps[i1-1][j1-1]);
    }

}psa;
//////////////////////////////////////////////////////////////////////////
