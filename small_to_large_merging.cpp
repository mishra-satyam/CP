// To merge the smaller set into the bigger set:

set<ll> small, big;
big.insert(begin(small), end(small));
small.clear();


// To merge two sorted arrays:

vector<ll> small, big, res;
merge(begin(small), end(small), begin(big), end(big), begin(res));
big = move(res);
small.clear();


// for trees
void dfs(int v, int p = -1, int d = 0) {
    int bc = v, bs = 0;
    for (auto &x : adj[v]) {
        if (x == p) continue;
        dfs(x, v, d+1);
        if (sz(mst[idx[x]]) > bs) {
            bs = sz(mst[idx[x]]);
            bc = x;
        }
    }
    idx[v] = v;
    int pt = idx[bc];
    idx[v] = pt;

    for (auto &x : adj[v]) {
        if (x == p || x == bc) continue;
        for (auto &y : mst[idx[x]]) {
            mst[pt].insert(y);
        }
    }

    // do something here
    // in mst of pt add contribution of this node "v"
    // or whatever thing is required according to the
    // need at this node
}

// sometimes it is better to use priority_queue

// LINK :- https://discuss.codechef.com/t/paircnt-editorial/92300

/////////////////////////////////////////////////////////////////////
#include <bits/stdc++.h>
#define initrand mt19937 mt_rand(time(0));
#define rand mt_rand()
#define MOD 1000000007
#define INF 1000000000
#define mid(l, u) ((l+u)/2)
#define rchild(i) (i*2 + 2)
#define lchild(i) (i*2 + 1)
#define lz lazup(l, u, i);
using namespace std;
const int N = 1e5 + 5;
long long qans[N];
int qd[N];
vector<int> adj[N];
vector<int> qn[N];
int ind[N];
map<pair<int, int>, int> mp[N];
void dfs(int i, int p, int d){
    int bigC = i;
    int bigSize = 0;
    for(int j: adj[i]){
        if(j==p) continue;
        dfs(j, i, d+1);
        if(mp[ind[j]].size() > bigSize){
            bigC = j;
            bigSize = mp[ind[j]].size();
        }
    }
    ind[i] = i;
    int impind = ind[bigC];
    ind[i] = impind;
    for(int k: qn[i]){
        qans[k] += mp[impind][{qd[k] + d, k}];
    }
    for(int k: qn[i]){
        mp[impind][{d, k}] ++;
    }
    for(int x: adj[i]){
        if(x==p || x==bigC) continue;
        for(pair<pair<int, int>, int> k: mp[ind[x]]){
            qans[k.first.second] += (((long long) k.second) * ((long long)mp[impind][{qd[k.first.second] + 2*d - k.first.first, k.first.second}]));
        }
        for(pair<pair<int, int>, int> k: mp[ind[x]]){
            mp[impind][k.first] += k.second;
        }
    }
}
/////////////////////////////////////////////////////////////////////
