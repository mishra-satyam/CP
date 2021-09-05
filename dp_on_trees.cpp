void dfs(int v, int p = -1)
{
    sub[v] = 1;
    dp[v][0] = 1;
    dp[v][1] = 1;

    for(auto &x : adj[v])
    {
        if (x == p) continue;
        dfs(x, v);

        fill(tmp , tmp + k + 1 , 0);
        for(int i = 1; i <= min(sub[v] , k); i++)
            for(int j = 0; j <= sub[x] && i + j <= k; j++)
                tmp[i + j] += dp[v][i] * dp[x][j];

        sub[v] += sub[x];

        for(int i = 0; i <= min(k , sub[v]); i++)
            dp[v][i] += tmp[i];
    }
}

/*
// IMPORTANT POINTS WRT REROOTING
1.  if you use prefix technique to remove a contribution of parent subtree
    then you can use this code.
    Also note that when you reroot a tree to some other child node
    then the only extra thing that that child gets is parent nodes' contribution
    everything else was already there with that child node
2.  (https://codeforces.com/contest/543/problem/D) (Road Improvement) here i used
    "extra" to get the contribution of parent of current root node. This is required only
    while using prefix and suffix as in this case prefix and suffix array only include
    value from the child and not from the parent.
_________________________________________________________________________________________________
int cur = 1;
pref[v].pb(cur);
for (auto &x : adj[v]){
    if (x == p) continue;
    cur = 1ll*cur*(total[x]+1)%mod;
    pref[v].pb(cur);
}
cur = 1;
suff[v].pb(cur);
for(auto it = adj[v].rbegin();it != adj[v].rend();it++){
    if (*it == p) continue;
    cur = 1ll*cur*(total[*it]+1)%mod;
    suff[v].pb(cur);
}
reverse(all(suff[v]));
___________________________________________________________________________________________________

*/
