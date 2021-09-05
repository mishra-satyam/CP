const int N = 2e5;
// vector<vector<int>> adj(N); // adjacency list of graph
// vector<bool> visited(N,0);
vi adj[N]; // adjacency list of graph
bool visited[N];
vector<int> order;

void addedge(int u, int v){
    adj[u].pb(v);
}

void dfs(int v) {
    visited[v] = true;
    for (int u : adj[v]) {
        if (!visited[u])
            dfs(u);
    }
    order.push_back(v);
}

void topological_sort(int n) {
    for (int i = 0; i < n; ++i) {
        visited[i] = 0;
    }
    order.clear();
    for (int i = 0; i < n; ++i) {
        if (!visited[i])
            dfs(i);
    }
    // first element of array is the topmost element
    reverse(order.begin(), order.end());
}

// dont forget to clear adj everytime for a new test case
