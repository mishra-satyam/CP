const int N = 1e5;
const ll INF = 1e18;
const ll NINF = -1e18;

struct edge{
    // a => b
    int a, b;
    ll cost;
};

void addedge(int x, int y, int w){
    edge e1,e2;
    e1.a = x, e1.b = y, e1.cost = w;
    e2.a = y, e2.b = x, e2.cost = w;
    edgelist.pb(e1);
    edgelist.pb(e2);
}

ll distanceval[N];
vector<edge> edgelist;
int parent[N];

void bellman_ford(int s, int n){
    FOR(i,0,n){
        distanceval[i] = INF;
        parent[i] = -1;
    }
    distanceval[s] = 0;
    for (;;)
    {
        bool any = false;
        for (int j = 0; j < (int)edgelist.size(); ++j)
            if (distanceval[edgelist[j].a] < INF)
                if (distanceval[edgelist[j].b] > distanceval[edgelist[j].a] + edgelist[j].cost)
                {
                    distanceval[edgelist[j].b] = distanceval[edgelist[j].a] + edgelist[j].cost;
                    parent[edgelist[j].b] = edgelist[j].a;
                    any = true;
                }
        if (!any)  break;
    }
}
