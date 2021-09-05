const int N = 2e5;

vector<vector<int>> adj(N);
vector<vector<int>> adjrev(N); // adjacency list of graph
vector<bool> visited(N,0);
vector<int> order;
vector<int> component;
int component_count = 0;

void addedge(int u, int v){
    adj[u].pb(v);
	adjrev[v].pb(u);
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
	FOR(i,0,n)
		visited[i] = 0;
    order.clear();
    for (int i = 0; i < n; ++i) {
        if (!visited[i])
            dfs(i);
    }
    reverse(order.begin(), order.end());
}

// please do all the initialisation part in the
// non recursive function itself
// as much as possible

void DFS_visit(int u){
    visited[u] = true;
	// component.pb(u);
    for(auto &v: adjrev[u]){
        if(!visited[v]){
            DFS_visit(v);
      	}
    }
}

void DFS(int n){
	FOR(i,0,n)
		visited[i] = 0;

    component_count = 0;
	// component.clear();
    FOR(i,0,n){
        if(!visited[order[i]]){
            DFS_visit(order[i]);
			// here you will get the component
			// process it here

            component_count++;
			// component.clear();
    	}
  	}
}

// dont forget to clear adj(only this) everytime for a new test case
