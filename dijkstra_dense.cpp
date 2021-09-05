vpii adj[10005];
// {vectex, dist}
bool visited[10005];
int distanceval[10005];
int parent[10005];

void addedge(int x, int y, int w){
    adj[x].pb({y,w});
    adj[y].pb({x,w});
}

void dijkstra(int source, int n){
    FOR(i,0,n){
        visited[i] = 0;
        distanceval[i] = INF;
        parent[i] = -1;
    }

    d[source] = 0;
    for(int i=0;i<n;i++){
        int v = -1;
        for (int j = 0; j < n; j++) {
            if (!visited[j] && (v == -1 || distanceval[j] < distanceval[v]))
                v = j;
        }

        if (d[v] == INF)
            break;

        visited[v] = true;
        for (auto edge : adj[v]) {
            int to = edge.first;
            int len = edge.second;

            if (d[v] + len < d[to]) {
                distanceval[to] = distanceval[v] + len;
                parent[to] = v;
            }
        }
    }
}

/*
// IMPORTANT POINTS
1.  O(n^2)
2. please change "set" "distanceval" "d" for l     
*/
