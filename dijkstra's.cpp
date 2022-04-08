const int N = 1e5;

vpii adj[N];
// {vectex, dist}
bool visited[N];
int dist[N];
int parent[N];

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
		dist[i] = INT_MAX;
		parent[i] = -1;
	}

	while(!s.empty()){
		int cur = s.begin()->sc;
		int d = s.begin()->fi;
		s.erase(s.begin());

		if (visited[cur]) continue;
		dist[cur] = d;
		visited[cur] = true;
		for(auto &tmp:adj[cur]){
			if (visited[tmp.fi]) continue;
			// for better time complexity
			if (d+tmp.sc < dist[tmp.fi]){
				s.insert({d+tmp.sc, tmp.fi});
				dist[tmp.fi] = d+tmp.sc;
				parent[tmp.fi] = cur;
			}
		}
	}
}

// dont forget to clear adj for multiple test cases

/*
// IMPORTANT POINTS
1.  O((n+m)logn)
2. please change "set" "dist" "d" for ll
*/
