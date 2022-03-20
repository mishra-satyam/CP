// FEMWICK TREES ARE ALWAYS ONE BASE INDEXED


// range update, point query

#define LSB(i) ((i) & -(i))
const int maxn=N;
struct fenwick{
	ll A[maxn];
	ll query(int i){
		ll sum = 0;
		while (i > 0)
			sum += A[i], i -= LSB(i);
		return sum;
	}
	void update(int i, ll k){
		if(i<1)return;
		while (i < maxn)
			A[i] += k, i += LSB(i);
	}
	void rupd(int l,int r,ll v){
		update(l,v);
		update(r+1,-v);
	}
}fenw;
////////////////////////////////////////////////////////////////////////////////////////
#define LSB(i) ((i) & -(i))
typedef struct fenwick{
	int maxn;
	ll A[N];
	void operator()(int n){
		maxn = n+1;
		FOR(i,0,n+1) A[i] = 0;
	}
	fenwick(){}
	fenwick(int n){
		maxn = n+1;
		FOR(i,0,n+1) A[i] = 0;
	}
	ll query(int i){
		ll sum = 0;
		while (i > 0)
			sum += A[i], i -= LSB(i);
		return sum;
	}
	void update(int i, ll k){
		if(i<1)return;
		while (i < maxn)
			A[i] += k, i += LSB(i);
	}
	void rupd(int l,int r,ll v){
		update(l,v);
		update(r+1,-v);
	}
}fenw;
////////////////////////////////////////////////////////////////////////////////////////









// point update, range query

#define LSB(i) ((i) & -(i))
const int maxn=N;
struct fenwick{
	ll A[maxn];
	ll query(int i){
		ll sum = 0;
		while (i > 0)
			sum += A[i], i -= LSB(i);
		return sum;
	}
	void update(int i, ll k){
		if(i<1)return;
		while (i < maxn)
			A[i] += k, i += LSB(i);
	}
	ll query(int l,int r){
		return (query(r) - query(l-1)) ;
	}
}fenw;
////////////////////////////////////////////////////////////////////////////////////////
#define LSB(i) ((i) & -(i))
typedef struct fenwick{
	int maxn;
	ll A[N];
	void operator()(int n){
		maxn = n+1;
		FOR(i,0,n+1) A[i] = 0;
	}
	fenwick(){}
	fenwick(int n){
		maxn = n+1;
		FOR(i,0,n+1) A[i] = 0;
	}
	ll query(int i){
		ll sum = 0;
		while (i > 0)
			sum += A[i], i -= LSB(i);
		return sum;
	}
	void update(int i, ll k){
		if(i<1)return;
		while (i < maxn)
			A[i] += k, i += LSB(i);
	}
	ll query(int l,int r){
		return (query(r) - query(l-1)) ;
	}
}fenw;
////////////////////////////////////////////////////////////////////////////////////////






/*
IMPORTANT POINTS
1.	It is 1 based indexed, so please work accordingly

2.	Here one important thing to note is that if you are using this struct with typedef
	then make shure that it is initalised to zeros

	void set(int n){
		FOR(i,0,n){
			A[i] = 0;
		}
	}

3.	void operator()(int n){
		maxn = n+1;
		FOR(i,0,n+1) A[i] = 0;
	}
4.	fenwick(int n){
		maxn = n+1;
		FOR(i,0,n+1) A[i] = 0;
	}
*/
