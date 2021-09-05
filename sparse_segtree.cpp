#include "bits/stdc++.h"
using namespace std;

const int N = 1e5 + 5;
const int INF = 1e9;


/*
KEYNOTES:
------------------------------------------
merge(X,identity_element) = X
------------------------------------------
------------------------------------------
identity_transformation.combine(X) = X
------------------------------------------
------------------------------------------
ALWAYS: older_update.combine(newer_update)
------------------------------------------
*/

// ADDED BY ME
/*
IMPORTANT POINTS FOR THIS CODE
1.  merge is for merging two node to get value for the parent node
2.  combine is for combining the previous and the new value that is
    remembered by that lazy person
3.	you can make a global segtree and the clear it everytime
	if ther is no pattern for initialisation(i.e. it is constant)
	then dont use array for it, just change the build function
	change len inside the public function to n(testcase wala n)
4.	one important thing is that in case of no overlap identity
	element is returned. So please keep this thing in mind.
	So change node(){} thing to make a perticular desired identity
	element.
*/


// example: addition: identity element is 0

// a + 0 = a or 0 + a = a

// min(x,INF) = x


template<typename node,typename update>
struct segtree
{
	int len;
    int blen;
	vector<node> t;
	vector<update> u;
    vector<bool> lazy;
	vector<int> li, ri;
	node identity_element;
	update identity_transformation;
    // here l is 2*QlogN
	segtree(int n, int q){
		len = n+2;
        blen = 1;
        int s = 2*(log2(n+2)+2)*q;
		t.resize(s);
		u.resize(s);
		lazy.resize(s);
        li.resize(s, 0);
        ri.resize(s, 0);
		identity_element = node();
		identity_transformation = update();
	}

	void pushdown(int32_t v, const int32_t &tl, const int32_t &tr){
		if(!lazy[v]) return;
		int32_t tm = (tl + tr) >> 1;
		li[v] = apply(li[v],tl,tm,u[v]);
		ri[v] = apply(ri[v],tm+1,tr,u[v]);
		u[v] = identity_transformation;
		lazy[v] = 0;
	}

	int apply(int32_t id, const int32_t &tl, const int32_t &tr, update upd){
        if (id == 0) id = ++blen;
 		if(tl != tr){
			lazy[id] = 1;
			u[id].combine(upd,tl,tr);
		}
		upd.apply(t[id],tl,tr);
        return id;
	}

	node query(int32_t id,const int32_t &tl,const int32_t &tr,const int32_t &l,const int32_t &r){
		if(l > tr || r < tl){
			return identity_element;
		}
        if (id == 0) return identity_element;
		if(tl >= l && tr <= r){
			return t[id];
		}
		pushdown(id,tl,tr);
		int32_t tm = (tl + tr) >> 1;
		node a = query(li[id],tl,tm,l,r),b = query(ri[id],tm+1,tr,l,r),ans;
		ans.merge(a,b);
		return ans;
	}

	// rupd = range update
	int rupd(int32_t id,const int32_t &tl,const int32_t &tr,const int32_t &l,const int32_t &r,const update &upd){
		if(l > tr || r < tl){
			return id;
		}
        if (id == 0) id = ++blen;
		if(tl >= l && tr <= r){
			apply(id,tl,tr,upd);
			return id;
		}
		pushdown(id,tl,tr);
		int32_t tm = (tl + tr) >> 1;
		li[id] = rupd(li[id],tl,tm,l,r,upd);
		ri[id] = rupd(ri[id],tm+1,tr,l,r,upd);
		t[id].merge(t[li[id]],t[ri[id]]);
        return id;
	}

	public:
	node query(const int32_t &l,const int32_t &r){
		return query(1,0,len-1,l,r);
	}
	void rupd(const int32_t &l,const int32_t &r,const update &upd){
		rupd(1,0,len-1,l,r,upd);
	}
};

// #define node node1
// #define update update1
struct node
{
    int mx = 0;
    // use more variables if you want more information
    // these default values should be identity_element
    node(){}
    node(int val){
        mx = val;
    }
    void merge(const node &l,const node &r){ // store the thing you wanna query

        mx = max(l.mx,r.mx);
    }
};

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
    }
    // store the correct information in the node x
    void apply(node &x,const int32_t &tl,const int32_t &tr){
        x.mx += v;
    }
};
// #undef node
// #undef update

// Link: https://pastebin.com/HenNdx4h

int main(){

	// segtree s(1000); // create a segment tree of length 1000
	// vector<int> v(1000);

    #ifdef SAT_LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);
    #endif

    segtree<node,update> t(100, 10);

    t.rupd(5,10,1000);

    auto q = t.query(1,10);
    cout << q.mx << "\n";
	return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////
// descent in sparse segtree (verified)
template<typename T>
int descent_right(int l, T x, int32_t v,const int &tl,const  int&tr, node &prev) {
	if (l > tr) // node is completely out of range
		return len;
	if(l <= tl){ // node is completely in range
		if (v == 0) return tl;
		node cur;
		cur.merge(prev,t[v]);
		if (!cur.check(x)){ // go further right than this node
			swap(prev,cur); // merging this node's contribution
			return len;
		}
		if (tl==tr) {
			return tr;
		}
	}
	if (v == 0) return l;
	pushdown(v, tl, tr);
	int tm = (tl+tr) >> 1;
	int ans=descent_right(l, x, li[v], tl, tm, prev); // trying to find in left child
	if(ans!=len)return ans; // found in left child
	return descent_right(l, x, ri[v], tm+1, tr, prev); // finding in right child
}

/////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////
// (verified)
// this one is with & so not sure if
// it will work in all Case

// SO IF YOU FIND SUCH CASE THEN PLEASE REMOVE THIS CODE


template<typename node,typename update>
struct segtree
{
	int len;
    int blen;
	vector<node> t;
	vector<update> u;
    vector<bool> lazy;
	vector<int> li, ri;
	node identity_element;
	update identity_transformation;
    // here l is 2*QlogN
	segtree(int n, int q){
		len = n+2;
        blen = 1;
        int s = 2*(log2(n+2)+2)*q;
		t.resize(s);
		u.resize(s);
		lazy.resize(s);
        li.resize(s, 0);
        ri.resize(s, 0);
		identity_element = node();
		identity_transformation = update();
	}

	void pushdown(int32_t &v, const int32_t &tl, const int32_t &tr){
		if(!lazy[v]) return;
		int32_t tm = (tl + tr) >> 1;
		apply(li[v],tl,tm,u[v]);
		apply(ri[v],tm+1,tr,u[v]);
		u[v] = identity_transformation;
		lazy[v] = 0;
	}

	void apply(int32_t &id, const int32_t &tl, const int32_t &tr, update upd){
        if (id == 0) id = ++blen;
 		if(tl != tr){
			lazy[id] = 1;
			u[id].combine(upd,tl,tr);
		}
		upd.apply(t[id],tl,tr);
        return;
	}

	node query(int32_t &id,const int32_t &tl,const int32_t &tr,const int32_t &l,const int32_t &r){
		if(l > tr || r < tl){
			return identity_element;
		}
        if (id == 0) return identity_element;
		if(tl >= l && tr <= r){
			return t[id];
		}
		pushdown(id,tl,tr);
		int32_t tm = (tl + tr) >> 1;
		node a = query(li[id],tl,tm,l,r),b = query(ri[id],tm+1,tr,l,r),ans;
		ans.merge(a,b);
		return ans;
	}

	// rupd = range update
	void rupd(int32_t &id,const int32_t &tl,const int32_t &tr,const int32_t &l,const int32_t &r,const update &upd){
		if(l > tr || r < tl){
			return;
		}
        if (id == 0) id = ++blen;
		if(tl >= l && tr <= r){
			apply(id,tl,tr,upd);
			return;
		}
		pushdown(id,tl,tr);
		int32_t tm = (tl + tr) >> 1;
		rupd(li[id],tl,tm,l,r,upd);
		rupd(ri[id],tm+1,tr,l,r,upd);
		t[id].merge(t[li[id]],t[ri[id]]);
        return;
	}

	public:
	node query(const int32_t &l,const int32_t &r){
        int v = 1, tl = 0, tr = len-1;
		return query(v,tl,tr,l,r);
	}
	void rupd(const int32_t &l,const int32_t &r,const update &upd){
        int v = 1, tl = 0, tr = len-1;
        rupd(v,tl,tr,l,r,upd);
	}
};

// #define node node1
// #define update update1
struct node
{
    int mx = 0;
    int idx = 0;
    // use more variables if you want more information
    // these default values should be identity_element
    node(){}
    node(pii val){
        mx = val.fi;
        idx = val.sc;
    }
    void merge(const node &l,const node &r){ // store the thing you wanna query
        mx = max(l.mx,r.mx);
        if (l.mx <= r.mx) {
            idx = r.idx;
        }
        else {
            idx = l.idx;
        }
    }
};

struct update
{
    int v = 0; // 4
    int idx = 0;
    // use more variables if you want more information
    // these default values should be identity_transformation
    update(){}
    update(int val){
        v = val; // 5
    }
    // combine the current update with the other update (see keynotes)
    void combine(update &other,const int32_t &tl,const int32_t &tr){
        // v = other.v; // 6
        if (v < other.v) {
            v = other.v;
            idx = other.idx;
        }
        else if (v == other.v) {
            amax(idx, other.idx);
        }
    }
    // store the correct information in the node x
    void apply(node &x,const int32_t &tl,const int32_t &tr){
        // x.mx = v;
        if (v > x.mx) {
            x.mx = v;
            x.idx = idx;
        }
        else if (v == x.mx) {
            amax(x.idx, idx);
        }
    }
};
