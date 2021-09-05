#include <bits/stdc++.h>
using namespace std;
using namespace chrono;

typedef long long ll;

typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef pair<ll,int> pli;
typedef pair<ll,int> pil;
typedef pair<ll,ll> pll;
typedef vector<pair<int, int>> vpii;
typedef vector<pair<ll, int>> vpli;
typedef vector<pair<int, ll>> vpil;
typedef vector<pair<ll, ll>> vpll;

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
#define mem0(a) memset(a,0,sizeof(a))
#define mem1(a) memset(a,-1,sizeof(a))
#define meminf(a) memset(a,1,sizeof(a))
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define found(a,x) (a.find(x) != a.end())
#define sz(x) (int)(x.size())


#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)

template<typename T> T gcd(T a, T b) {return (b ? __gcd(a, b) : a);}
template<typename T> T lcm(T a, T b) {return (a * (b / gcd(a, b)));}
template<typename T,typename T1>T amax(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T amin(T &a,T1 b){if(b<a)a=b;return a;}

template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a)
{in>>a.fi>>a.sc;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a)
{out<<"{ "<<a.fi<<" "<<a.sc<<" }";return out;}

const int mod = 1e9+7;

template<typename T> void print(T &a)
{
    for(auto &x : a)
        cout << x << " ";
    cout << "\n";
}

#ifndef ONLINE_JUDGE
#include "upd_cfdebug.h"
#else
#define debug(x...)
#endif

#ifndef ONLINE_JUDGE
#include<sys/resource.h>
#include <sys/time.h>
#endif

const int N = 1e6+10;

struct node
{
	int s = 0;
	// use more variables if you want more information
	// these default values should be identity_element
	node(){}
	node(int val){
		s = val;
	}
	void merge(const node &l,const node &r){ // store the thing you wanna query

		s = l.s + r.s;

		// if we wanted the maximum, then we would do
		// like v = max(l.v,r.v)
	}
};

// example: add on a range: identity transformation = 0
// old += new

// if old is identity which is 0, then 0 + new which new

struct update
{
	int v = 0; // 4
	// use more variables if you want more information
	// these default values should be identity_transformation
	update(){}
	update(int val){
		v = val; // 5
	}
	// combine the current update with the other update (see keynotes)
	void combine(update &other,const int32_t &tl,const int32_t &tr){
		v += other.v; // 6

		// you can be sure that the "other" is newer than current

	}
	// store the correct information in the node x
	void apply(node &x,const int32_t &tl,const int32_t &tr){
		// no change in freq
		x.s += v;

	}
};

// template<typename node,typename update>
struct segtree
{
	int len;
	vector<node> t;
	vector<update> u;
	vector<bool> lazy;
	node identity_element;
	update identity_transformation;
	segtree(int l){
		len = l;
		t.resize(4 * len);
		u.resize(4 * len);
		lazy.resize(4 * len);
		identity_element = node();
		identity_transformation = update();
	}

	void pushdown(const int32_t &v, const int32_t &tl, const int32_t &tr){
		if(!lazy[v]) return;
		int32_t tm = (tl + tr) >> 1;
		apply(v<<1,tl,tm,u[v]);
		apply(v<<1|1,tm+1,tr,u[v]);
		u[v] = identity_transformation;
		lazy[v] = 0;
	}

	void apply(const int32_t &v, const int32_t &tl, const int32_t &tr, update upd){
		if(tl != tr){
			lazy[v] = 1;
			u[v].combine(upd,tl,tr);
		}
		upd.apply(t[v],tl,tr);
	}

	// template<typename T>
	void build(const int32_t &v, const int32_t &tl, const int32_t &tr){
        u[v] = identity_transformation;		// extra
		if(tl == tr){
			t[v] = identity_element;
			return;
		}
		int32_t tm = (tl + tr) >> 1;
		build(v<<1,tl,tm);
		build(v<<1|1,tm+1,tr);
		t[v].merge(t[v<<1],t[v<<1|1]);

	}

	node query(const int32_t &v,const int32_t &tl,const int32_t &tr,const int32_t &l,const int32_t &r){
		if(l > tr || r < tl){
			return identity_element;
		}
		if(tl >= l && tr <= r){
			return t[v];
		}
		pushdown(v,tl,tr);
		int32_t tm = (tl + tr) >> 1;
		node a = query(v<<1,tl,tm,l,r),b = query(v<<1|1,tm+1,tr,l,r),ans;
		ans.merge(a,b);
		return ans;
	}

	// rupd = range update
	void rupd(const int32_t &v,const int32_t &tl,const int32_t &tr,const int32_t &l,const int32_t &r,const update &upd){
		if(l > tr || r < tl){
			return;
		}
		if(tl >= l && tr <= r){
			apply(v,tl,tr,upd);
			return;
		}
		pushdown(v,tl,tr);
		int32_t tm = (tl + tr) >> 1;
		rupd(v<<1,tl,tm,l,r,upd);
		rupd(v<<1|1,tm+1,tr,l,r,upd);
		t[v].merge(t[v<<1],t[v<<1|1]);
	}

	public:
	// template<typename T>
	void build(){
		build(1,0,len-1);
	}
	node query(const int32_t &l,const int32_t &r){
		return query(1,0,len-1,l,r);
	}
	void rupd(const int32_t &l,const int32_t &r,const update &upd){
		rupd(1,0,len-1,l,r,upd);
	}
};

segtree s(N);
vi adj1[N];
vi adj2[N];
int dist1[N];
int dist2[N];
int parent1[N];
int parent2[N];
int ans;

void addedge(int u, int v, int i){
    // u = child v = parent
    if (i == 1){
        adj1[v].pb(u);
        parent1[u] = v;
    }
    else{
        adj2[v].pb(u);
        parent2[u] = v;
    }
}

// build the range for the query
pii range[N];
int clk=-1;
void preorder(int v, int lvl){
    range[v].fi = ++clk;
    dist1[v] = lvl++;
    for (auto &x : adj1[v]){
        preorder(x, lvl);
    }
    range[v].sc = clk;
}

// DFS on second one
void DFS(int v, int lvl){
    bool f = 0;
    if (dist1[v] == lvl){
        f = 1;
        s.rupd(range[v].fi, range[v].sc, 1);
        amax(ans, s.query(0, N-1).mx);
    }

    lvl++;
    for (auto &x : adj2[v]){
        DFS(x, lvl);
    }
    if (f){
        s.rupd(range[v].fi, range[v].sc, -1);
    }
}


void solve(){
    // DONT FORGET to take "N"
    // NEVER do "i j" or "n m" kind of mistake
    // NEVER dereference out of bound index
    int n;
    cin >> n;
    int t1, t2, t3;
    int root1, root2;
    FOR(i,1,n+1){
        adj1[i].clear();
        adj2[i].clear();
    }
    FOR(i,1,n+1){
        cin >> t1;
        if (t1 == -1) root1 = i;
        addedge(i,t1,1);
    }
    FOR(i,1,n+1){
        cin >> t1;
        if (t1 == -1) root2 = i;
        addedge(i,t1,2);
    }

    // segtree on first once
    // range max query, add on range query
    // dfs on second one
    ans = 0;
    clk = -1;
    preorder(root1, 0);
    s.build();
    DFS(root2, 0);
    cout << ans << "\n";
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    #ifndef ONLINE_JUDGE
        /* setting up soft limit on resources */
        rlimit rlim , rlim_time ;
        if(getrlimit( RLIMIT_FSIZE , &rlim) || getrlimit(RLIMIT_CPU , &rlim_time) )
           return 1 ;
        // maximum file size (in bytes) that your program will be able to create ;
        rlim.rlim_cur = 1000*1000;
        // maximum allowed runtime for your program ;
        rlim_time.rlim_cur = 1;
        if(setrlimit( RLIMIT_FSIZE , &rlim ) || setrlimit(RLIMIT_CPU , &rlim_time))
           return 2 ;
    #endif

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);
    #endif

    auto start1 = high_resolution_clock::now();

    int t=1;
    cin >> t;
    while(t--){
        solve();
    }

    auto stop1 = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop1 - start1);
    #ifndef ONLINE_JUDGE
    cout << "Time: " << duration.count() << " ms" << endl;
    #endif

    return 0;
}
