const ll INF = 1e18;

// this must be n*n matrix
// with adj[i][i] = 0
// and adj[i][j] = inf
// if no edge between i and j
vector<ll> distanceval[505];

void floyd_warshall(int n){
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (distanceval[i][k] < INF && distanceval[k][j] < INF)
                    amin(distanceval[i][j], distanceval[i][k] + distanceval[k][j]);
            }
        }
    }
}

// ma'am algo DAA
void floyd_warshall(int n){
    ll t = 2;
    while(t <= (n-1)){
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < n; ++k) {
                    if (distanceval[i][k] < INF && distanceval[k][j] < INF)
                    amin(distanceval[i][j], distanceval[i][k] + distanceval[k][j]);
                }
            }
        }
        t = t*2;
    }
}
