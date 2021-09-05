const int N = 2e5;

vi adj[N];
bool visited[N];
int dist[N];
int parent[N];

void addedge(int u, int v){
    adj[u].pb(v);
    adj[v].pb(u);
}

// void addedge(int u, int v){
//     // par ch
//     adj[u].pb(v);
//     parent[v] = u;
// }


void dfs(int v, int p = -1){
    for (auto &x : adj[v]){
        if (x == p) continue;
        dfs(x, v);
    }
}

void bfs(int s, int n){
    queue<int> q;
    // to see the left points
    FOR(i,0,n){
        dist[i] = INT_MAX;
        visited[i] = 0;
    }

    //for multisource bfs
    // add rest sources here
    q.push(s);
    dist[s] = 0;
    visited[s] = true;
    parent[s] = -1;

    while(!q.empty()){
        int cur = q.front();
        q.pop();

        for(int &adjv:adj[cur]){
            if (!visited[adjv]){
                visited[adjv] = true;
                q.push(adjv);
                parent[adjv] = cur;
                dist[adjv] = dist[cur] + 1;
            }
        }
    }
}
