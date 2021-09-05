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

void print(vi &a, int n){
	FOR(i,0,n)
	cout << a[i] << " ";
	cout << endl;
}

const int N = 2e5;

vector<vector<int>> adj(N);
vector<vector<int>> adjrev(N); // adjacency list of graph
vector<bool> visited(N,0);
vector<int> order;
vector<int> component;
int component_count = 0;

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

void DFS(int n){
	FOR(i,0,n)
		visited[i] = 0;

    component_count = 0;
	component.clear();
    FOR(i,0,n){
        if(!visited[order[i]]){
            DFS_visit(order[i]);
			// here you will get the component
			// process it here

            component_count++;
			component.clear();
    	}
  	}
}

// dont forget to clear adj everytime for a new test case


void solve(){
	int n,m,q,t1,t2;
	cin >> n >> m;

	for(int i=0; i<n; i++){
		adj[i].clear();
		adjrev[i].clear();
	}

	FOR(i,0,m){
		cin >> t1 >> t2;
		addedge(--t1,--t2);
	}

	topological_sort(n);
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
