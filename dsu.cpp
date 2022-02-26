const int N = 2e5 + 5;

int parent[N];
int sizee[N];
int total_sets;

int find_set(int x){
    if (parent[x] == x) return x;
    parent[x] = find_set(parent[x]);
    return parent[x];
}

void union_sets(int x, int y){
    x = find_set(x);
    y = find_set(y);
    if (x == y) return;
    total_sets--;
    if (sizee[x] > sizee[y]) swap(x,y);
    // sizee(x) <= sizee(y)
    parent[x] = y;
    if (sizee[x] == sizee[y]) sizee[y]++;
    // sizee[y] += sizee[x];
    // max_val[y] = max(max_val[x], max_val[y]);
}

void initialize(int n){
    // here n is the number of index of largest
    // original element in the set
    FOR(i,0,n+1){
        parent[i] = i;
        sizee[i] = 1;
    }
    total_sets = n;
}

struct RollbackUF {
	vector<int> e; vector<pair<int, int>> st;
	RollbackUF(int n) : e(n, -1) {}
	int size(int x) { return -e[find(x)]; }
	int find(int x) { return e[x] < 0 ? x : find(e[x]); }
	int time() { return sz(st); }
	void rollback(int t) {
		for (int i = time(); i --> t;)
			e[st[i].first] = st[i].second;
		st.resize(t);
	}
	bool join(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return false;
		if (e[a] > e[b]) swap(a, b);
		st.push_back({a, e[a]});
		st.push_back({b, e[b]});
		e[a] += e[b]; e[b] = a;
		return true;
	}
};

// beware this is logN not alphaN

// link: https://bit.ly/2V2sTBI

struct UF {
	vector<int> e;
	UF(int n) : e(n+1, -1) {}
	bool sameSet(int a, int b) { return find(a) == find(b); }
	int size(int x) { return -e[find(x)]; }
	int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
	bool join(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return false;
		if (e[a] > e[b]) swap(a, b);
		e[a] += e[b]; e[b] = a;
		return true;
	}
};

// link: https://bit.ly/2UUdnID


struct RollbackUF {
	vector<int> e; vector<pair<int, int>> st;
    int total;
	RollbackUF(int n) : e(n, -1) {}
	int size(int x) { return -e[find(x)]; }
    // rollback find
    int findrb(int x) { return e[x] < 0 ? x : findrb(e[x]); }
	int time() { return sz(st); }
	void rollback(int t) {
		for (int i = time(); i --> t;)
			e[st[i].first] = st[i].second;
		st.resize(t);
	}
    // rollback join
	bool joinrb(int a, int b) {
		a = findrb(a), b = findrb(b);
		if (a == b) return false;
        total--;
		if (e[a] > e[b]) swap(a, b);
		st.push_back({a, e[a]});
		st.push_back({b, e[b]});
		e[a] += e[b]; e[b] = a;
		return true;
	}
    // normal find
    int findn(int x) { return e[x] < 0 ? x : e[x] = findn(e[x]); }
    // normal join
	bool joinn(int a, int b) {
		a = findn(a), b = findn(b);
		if (a == b) return false;
        total--;
		if (e[a] > e[b]) swap(a, b);
		e[a] += e[b]; e[b] = a;
		return true;
	}
};
