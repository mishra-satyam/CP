const int N = 2e5;
const ll INF = 1e18;
const ll NINF = -1e18;

// please add parent thing in this code


// adj list representation
vpil adj[N];
ll dist[N];
int parent[N];

bool spfa(int s, int n) {
    FOR(i,0,n) dist[i] = INF, parent[i] = -1;
    vector<int> cnt(n, 0);
    vector<bool> inqueue(n, 0);
    queue<int> q;

    dist[s] = 0;
    q.push(s);
    inqueue[s] = true;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        inqueue[v] = false;

        for (auto edge : adj[v]) {
            int to = edge.first;
            ll len = edge.second;

            if (dist[v] + len < dist[to]) {
                dist[to] = dist[v] + len;
                parent[to] = v;
                if (!inqueue[to]) {
                    q.push(to);
                    inqueue[to] = true;
                    cnt[to]++;
                    // check if we can move this outside
                    // this can be moved to get better Time
                    // complexity
                    if (cnt[to] > n)
                        return false;  // negative cycle
                }
            }
        }
    }
    return true;
}
