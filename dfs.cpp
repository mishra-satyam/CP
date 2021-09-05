const int n = 10000;

vi adj[n];
bool visited[n];

void addedge(int u, int v){
    adj[u].pb(v);
    adj[v].pb(u);
}


void DFS_visit(int u){
    visited[u] = true;
    for(auto &v: adj[u]){
        if(!visited[v]){
            DFS_visit(v);
        }
    }
}

void DFS(int n){
    FOR(i,0,n){
        visited[i] = 0;
    }

    FOR(i,0,n){
        if(!visited[i]){
            DFS_visit(i);
        }
    }
}

// always remember to clear the adj list for multiple testcases
