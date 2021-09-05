// Please verify this code
// verified

const int N = 1e5;

vpii adj[N];
// {vectex, dist}
bool visited[N];
int distanceval[N];
int parent[N];
vpii adj_new[N];


void insert(int x, int y, int w){
    adj[x].pb({y,w});
    adj[y].pb({x,w});
}

void dijkstra(int source, int n){
    set<pii> s;
    // {dist, vertex}
    //for multisource dijkstra
    // add rest sources here
    s.insert({0,source});

    FOR(i,0,n){
        visited[i] = 0;
        distanceval[i] = INT_MAX;
        parent[i] = -1;
        adj_new[i].clear();
    }

    while(!s.empty()){
        int cur = s.begin()->sc;
        int d = s.begin()->fi;
        s.erase(s.begin());

        if (!visited[cur]){
            if (parent[cur] != -1) adj_new[parent[cur]].pb({cur, distanceval[cur]});
            distanceval[cur] = d;
            visited[cur] = true;
            for(auto &tmp:adj[cur]){
                if (!visited[tmp.fi]){
                    // for better time complexity
                    if (tmp.sc < distanceval[tmp.fi]){
                        s.insert({tmp.sc, tmp.fi});
                        distanceval[tmp.fi] = tmp.sc;
                        parent[tmp.fi] = cur;
                    }
                }
            }
        }
    }
}

// dont forget to clear adj for multiple test cases

/*
// IMPORTANT POINTS
1.  O((n+m)logn)
2.  please change "set" "distanceval" "d" for ll
3.  only for undirected graphs
*/
