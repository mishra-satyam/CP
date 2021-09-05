// To merge the smaller set into the bigger set:

set<ll> small, big;
big.insert(begin(small), end(small));
small.clear();


// To merge two sorted arrays:

vector<ll> small, big, res;
merge(begin(small), end(small), begin(big), end(big), begin(res));
big = move(res);
small.clear();


// for trees
void dfs(int v, int p = -1, int d = 0) {
    int bc = v, bs = 0;
    for (auto &x : adj[v]) {
        if (x == p) continue;
        dfs(x, v, d+1);
        if (sz(mst[idx[x]]) > bs) {
            bs = sz(mst[idx[x]]);
            bc = x;
        }
    }
    idx[v] = v;
    int pt = idx[bc];
    idx[v] = pt;

    for (auto &x : adj[v]) {
        if (x == p || x == bc) continue;
        for (auto &y : mst[idx[x]]) {
            mst[pt].insert(y);
        }
    }

    // do something here
    // in mst of pt add contribution of this node "v"
    // or whatever thing is required according to the
    // need at this node
}

// sometimes it is better to use priority_queue
