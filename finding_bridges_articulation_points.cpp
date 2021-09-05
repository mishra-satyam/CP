#include <bits/stdc++.h>
using namespace std;
using namespace chrono;

typedef long long ll;

typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef pair<ll,int> pli;
typedef vector<pair<ll, int>> vpli;

#define mp make_pair
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define fi first
#define sc second
#define lb lower_bound
#define ub upper_bound
#define ppc __builtin_popcount
#define ppcll __builtin_popcountll
#define mem(a,b) memset(a,b,sizeof(a))
#define all(x) (x).begin(),(x).end()


#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)

template<typename T> T gcd(T a, T b) {return (b ? __gcd(a, b) : a);}
template<typename T> T lcm(T a, T b) {return (a * (b / gcd(a, b)));}
template<typename T,typename T1>T amax(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T amin(T &a,T1 b){if(b<a)a=b;return a;}

const int mod = 1e9+7;

#define N 200005

void print(vi &a, int n){
	FOR(i,0,n)
	cout << a[i] << " ";
	cout << endl;
}

vector<int> adj[N];

void addedge(int u, int v){
	adj[u].pb(v);
	adj[v].pb(u);
}

vector<int> intime(N,-1);
vector<int> dist(N,-1);
vector<char> visited(N,'w');


int timetaken = 1;

void DFS_visit(int u, int parent/*,int level*/){
	dist[u] = timetaken;
	intime[u] = timetaken;
	timetaken++;

	// (this thing was added later)
	// maybe just change dist to tell
	// the level and let other things to be the same
	// dist[u] = level;
	// level++;

	// here level is distance from root node
	// level of root is zero

	// dist[u] = level;
	// intime[u] = level;
	// level++;

    int children = 0;
	visited[u] = 'g';

	for(auto &to: adj[u]){

		if(to==parent)continue;

		if(visited[to] == 'w'){

			DFS_visit(to,u/*,int level*/);
			dist[u] = min(dist[to], dist[u]);

			if(dist[to]>intime[u]){
                // this is a bridge edge

			}

            if (dist[to] >= intime[u] && parent != -1){
                // this is an articulation point
                // point u where u is not a root edge

				// this may happen MULTIPLE TIMES for
                // some values of u for different values of to

            }

            children++;
		}

		else{
            // this either front or a back edge

            // this is back edge
            if (visited[to] == 'g'){}

            // this is front edge

			// (this thing was added later) this can be cross edge as well
			// so check it based on the global clock intime

            else{}

            // necessary for both
            // so dont comment
			dist[u] = min(dist[u],intime[to]);
		}
	}
    // this is to check if the root
    // of dfs tree is articulation
    // point or not
    if (parent == -1  && children > 1){
        // this is an articulation point
        // where this point is root of the
        // dfs tree

    }

	visited[u] = 'b';
}

void DFS(int n){

	for(int i=0; i<n; i++){
		visited[i] = 'w';
		dist[i] = -1;
		intime[i] = -1;
	}

	timetaken = 1;
	// int level = 0;

	for(int i=0; i<n; i++){
		if(visited[i] == 'w'){
			DFS_visit(i,-1/*,level*/);
		}
	}

}

// never forget to clear adj for multiple testcase

void solve(){
	int n,m,q,t1,t2;
	cin >> n >> m;

	for(int i=0; i<n; i++){
		adj[i].clear();
	}

	FOR(i,0,m){
		cin >> t1 >> t2;
		addedge(--t1,--t2);
	}

	DFS(n);

	return;
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);

	int t=1;
	// cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
