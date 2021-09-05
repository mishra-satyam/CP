template<typename T> int lcs(T s1, T s2){
    int l1 = sz(s1), l2 = sz(s2);
    int dp[l1+1][l2+1];
    FOR(i,0,l1+1) dp[i][0] = 0;
    FOR(i,0,l2+1) dp[0][i] = 0;
    FOR(i,1,l1+1){
        FOR(j,1,l2+1){
            if (s1[i-1] == s2[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else{
                dp[i][j] = max( dp[i][j-1], dp[i-1][j] );
            }
        }
    }
    // FOR(i,0,l1+1){
    //     FOR(j,0,l2+1){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    return dp[l1][l2];
}
