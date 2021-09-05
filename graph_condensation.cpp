const int N = 2e5;

vector<vector<int>> adj(N);
vector<vector<int>> adjrev(N); // adjacency list of graph
vector<bool> visited(N,0);
vector<int> order;
vector<int> component;
int component_count = 0;


vector<int> roots(N, 0);
vector<int> root_nodes;
vector<vector<int>> adj_scc(N);



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
	component.pb(u);
    for(auto &v: adjrev[u]){
        if(!visited[v]){
            DFS_visit(v);
      	}
    }
}

void make_graph(int n){

    topological_sort(n);

	FOR(i,0,n){
        visited[i] = 0;
        roots[i] = 0;
        adj_scc[i].clear();
    }

    component_count = 0;
	component.clear();
    root_nodes.clear();
    // dont change this, this for index of order
    FOR(i,0,n){
        if(!visited[order[i]]){
            DFS_visit(order[i]);
			// here you will get the component
			// process it here

            int root = component.front();
            for (auto &u : component) roots[u] = root;
            root_nodes.push_back(root);

            component_count++;
			component.clear();
    	}
  	}
    FOR(v,0,n){
        for (auto &u : adj[v]) {
        int root_v = roots[v], root_u = roots[u];

        if (root_u != root_v)
            adj_scc[root_v].push_back(root_u);
        }
    }
}



// dont forget to clear (adj)(only this) everytime for a new test case
// take edges and call make_graph only
// if you are taking everything to be 1 indexed then dont change
// the loop for index of order as even then it will remain 0 indexed
