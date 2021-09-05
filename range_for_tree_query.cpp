// build the range for the query
pii range[N];
int clk=-1;
void preorder(int v, int p = -1){
    range[v].fi = ++clk;
    // dist1[v] = lvl++;
    for (auto &x : adj[v]){
        if (x == p) continue;
        preorder(x, v);
    }
    range[v].sc = clk;
}


// reinitialize clk = -1 for multiple test cases
/*
// FOR 0 based indexing
                clk = -1
// FOR 1 based indexing
                clk = 0
*/
//
// Path query on trees (static)
// kind of path query and point update

// code
 // just do a ++clk in line 11
