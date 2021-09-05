const int N = 1e5+5;
const int LOG = 20;

vi adj[N];
int up[N][LOG]; // up[v][j] is 2^j-th ancestor of v
int depth[N];
int parent[N];
void addedge(int u, int v){
    adj[u].pb(v);
    adj[v].pb(u);
}


void DFS_visit(int u, int p){
    for(auto &v: adj[u]){
        if (v == p) continue;
        depth[v] = depth[u] + 1;
        up[v][0] = u; // a is parent of b
		for(int j = 1; j < LOG; j++) {
			up[v][j] = up[ up[v][j-1] ][j-1];
		}
        DFS_visit(v, u);
    }
}

// for (int i=0;i<n;i++)
//     up[i][0] = parent[i];
//
// for (int j=0;j<LOG;j++){
//     for (int i=0;i<n;i++){
//         up[i][j] = up[ up[i][j-1] ][j-1];
//     }
// }

int get_lca(int a, int b) { // O(log(N))
	if(depth[a] < depth[b]) {
		swap(a, b);
	}
	// 1) Get same depth.
	int k = depth[a] - depth[b];
	for(int j = LOG - 1; j >= 0; j--) {
		if(k & (1 << j)) {
			a = up[a][j]; // parent of a
		}
	}
	// 2) if b was ancestor of a then now a==b
	if(a == b) {
		return a;
	}
	// 3) move both a and b with powers of two
	for(int j = LOG - 1; j >= 0; j--) {
		if(up[a][j] != up[b][j]) {
			a = up[a][j];
			b = up[b][j];
		}
	}
	return up[a][0];
}

// always remember to clear the adj list for multiple testcases
// set depth root = 0
// call dfs(root, -1)

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Link : https://www.topcoder.com/thrive/articles/Range%20Minimum%20Query%20and%20Lowest%20Common%20Ancestor


/*
ANOTHER WAY

NOTES FOR THIS WAY
1.  clear tour and level and set idx as 0
    for multiple testcases
2.  N must be twice the max number of nodes
    in a tree(and adjust LOG accordingly)
*/

// 2*number of nodes
const int N = 1e5+5;
const int LOG = 17;

vi adj[N];
int parent[N];

vi tour;
vi level;
vi node_idx(N);
int idx = 0;
void generate(int v, int lvl = 0){
    tour.pb(v);
    level.pb(lvl);
    node_idx[v] = idx;
    idx++;
    for (auto &x : adj[v]){
        // if adj contains parent then
        // please add a line here
        generate(x, lvl+1);
        tour.pb(v);
        level.pb(lvl);
        idx++;
    }
}

int table[2*N][LOG];

int lg(int x){
    int k = log2(x);
    while(1<<k < x) k++;
    while(1<<k > x) k--;
    return k;
}

// here n is number of nodes
void make_table(int n1){
    // index of topmost node in a range
    n1 = 2*n1-1;
    int LOG1 = lg(n1) + 1;
    for (int i=0;i<n1;i++){
        table[i][0] = i;
    }

    for (int j = 1; j<LOG1; j++){
        for (int i=0; i + (1<<j) -1 < n1; i++){
            if (level[table[i][j-1]] > level[table[i+(1<<(j-1))][j-1]])
                table[i][j] = table[i+(1<<(j-1))][j-1];
            else
                table[i][j] = table[i][j-1];
        }
    }
}

int query(int n1, int n2){
    if(node_idx[n1] > node_idx[n2]) swap(n1, n2);
    // idx(a) < idx(b)
    int l = node_idx[n1],r = node_idx[n2];
    int len = r-l+1;
    int power = lg(r-l+1);
    int idx1;
    if (level[table[l][power]] > level[table[r-(1<<power)+1][power]])
        idx1 = table[r-(1<<power)+1][power];
    else
        idx1 = table[l][power];
    return tour[idx1];
}
