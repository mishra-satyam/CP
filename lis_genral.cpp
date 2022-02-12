int n;
cin >> n;
vi h(n), a(n);
FOR(i,0,n) cin >> h[i];
FOR(i,0,n) cin >> a[i];

set<pll> tmp;
ll ans = a[0];

tmp.insert({h[0], a[0]});

FOR(i,1,n){
    // debug(h[i], tmp);
    // cout << "\n";
    auto it = tmp.lower_bound({h[i], 0});
    ll val;
    if (it == tmp.begin()){
        val = a[i];
    }
    else{
        auto x = it;
        x--;
        val = a[i] + x->sc;
    }
    amax(ans, val);
    while(it != tmp.end() && it->sc <= val){
        auto x = it;
        it++;
        tmp.erase(x);
    }
    tmp.insert({h[i], val});
}
// debug(tmp);
cout << ans << "\n";

/*
This is yet another way to find lis
*/
int ans = 0;
int dp[n+1];
fill(dp, dp+n+1, 1e9);
//   length -> best end (smallest end)

// the thing that is really cool about this code is
// that here we maintain the best end that we can get
// with just one change at a time.

// so it makes easy to rollback this thing

// also this dp will always have non-decreasing values
// obviously this is the reason why we can binary search
for(int i = 0; i < n ; i++){
    int idx = upper_bound(dp+1, dp+n+1, a[i]-1) - dp;
    // int len = idx - 1;
    if (idx > ans) ans = idx;
    dp[idx] = a[i];
}

/////////////////////////////////////////////////////////////////////

int lis(vector<int> a) {
    int ans = 0;
    int n = sz(a);
    int dp[n+1];
    fill(dp, dp+n+1, 2e9);
    for(int i = 0; i < n ; i++){
        // remove this -1 if you want longest non-dereasing subsequence
        int idx = upper_bound(dp+1, dp+n+1, a[i]-1) - dp;
        // int len = idx - 1;
        if (idx > ans) ans = idx;
        dp[idx] = a[i];
    }
    return ans;
}
/////////////////////////////////////////////////////////////////////

// atcoder DP Q flowers (general lis easy to code)
// short explanation of what i did here
/*
so basically i have maintained the best thing that can be done till a point
(here height) and it will not contain any garbage value(it will contain only
valuable values) and therefore i even need to maintain this invariant.
(which is done through the while loop)
*/

// IMPORTANT POINTS
/*
1.
*/
