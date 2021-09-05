// please implement array based implement of this thing as well

#include<bits/stdc++.h>
using namespace std;
template <class t> class MergeSortTree{
	public:
		int _l, _r, _m;
		vector<t> v;
		MergeSortTree *left, *right;
		MergeSortTree(int l, int r, vector<t> &e){
            v.resize(r-l+1);
			_l=l, _r=r, _m=(l+r)/2, v[0]=e[l];
			if(l==r)	left=right=nullptr;
			else{
				left=new MergeSortTree(_l,_m, e);
				right=new MergeSortTree(_m+1,_r, e);
				merge(left->v.begin(), left->v.end(), right->v.begin(), right->v.end(), v.begin());
			}
		}
		int count(int l, int r, t a, t b){ //Number of x -> a<=x<=b and x is between l and r
			if (l>r || a>b) return 0;  // extra
			if(l>_r || r<_l) return 0;
			if(_l>=l && _r<=r)	return upper_bound(v.begin(), v.end(), b)-lower_bound(v.begin(), v.end(), a);
			return left->count(l,r,a,b)+right->count(l,r,a,b);
		}
		// for fixing memory leaks
		void clear() {
            if (left != nullptr) {
                left->clear();
                delete left;
            }
            if (right != nullptr) {
                right->clear();
                delete right;
            }
        }
};
int main(){

    #ifdef SAT_LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);
    #endif

	vector<int> v={1,5,2,7,4,1};
	MergeSortTree<int> mt(0,v.size()-1,v);
	cout<<mt.count(0,v.size()-1,0,1);
}

// time is obviously nlogn to create the tree and log2n for each query
// space is nlogn

// link: https://bit.ly/3ljc40G

// Merge sort tree with Frational Cascading
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class t> class MergeSortTree{
	public:
		int _l, _r, _m;
        vector<t> v;
        vector<int> lp, rp;
		MergeSortTree *left, *right;
		MergeSortTree(int l, int r, vector<t> &e){
			_l=l, _r=r, _m=(l+r)/2, v.push_back(e[l]);
			if(l==r)	left=right=nullptr;
			else{
				left=new MergeSortTree(_l,_m, e);
				right=new MergeSortTree(_m+1,_r, e);
                int i1=0, i2=0, p1=0, p2=0;
                v.pop_back();
                while (i1<sz(left->v) and i2<sz(right->v)) {
                    if (left->v[i1] < right->v[i2]) {
                        v.push_back(left->v[i1]);
                        lp.push_back(p1);
                        i1++;
                        if (i1 < sz(left->v)) {
                            if (left->v[p1] < left->v[i1]) p1 = i1;
                        }
                        rp.push_back(p2);
                    }
                    else if (right->v[i2] < left->v[i1]) {
                        v.push_back(right->v[i2]);
                        rp.push_back(p2);
                        i2++;
                        if (i2 < sz(right->v)) {
                            if (right->v[p2] < right->v[i2]) p2 = i2;
                        }
                        lp.push_back(p1);
                    }
                    else {
                        v.push_back(right->v[i2]);
                        v.push_back(left->v[i1]);
						lp.push_back(p1);
                        lp.push_back(p1);
                        i1++;
                        if (i1 < sz(left->v)) {
                            if (left->v[p1] < left->v[i1]) p1 = i1;
                        }
						rp.push_back(p2);
                        rp.push_back(p2);
                        i2++;
                        if (i2 < sz(right->v)) {
                            if (right->v[p2] < right->v[i2]) p2 = i2;
                        }
                    }
                }

                while (i1<sz(left->v)) {
                    v.push_back(left->v[i1]);
                    lp.push_back(p1);
                    i1++;
                    if (i1 < sz(left->v)) {
                        if (left->v[p1] < left->v[i1]) p1 = i1;
                    }
                }
                lp.push_back(sz(left->v));

                while(i2<sz(right->v)) {
                    v.push_back(right->v[i2]);
                    rp.push_back(p2);
                    i2++;
                    if (i2 < sz(right->v)) {
                        if (right->v[p2] < right->v[i2]) p2 = i2;
                    }
                }
                rp.push_back(sz(right->v));

                while(sz(lp) != sz(v)+1) lp.push_back(sz(left->v));
                while(sz(rp) != sz(v)+1) rp.push_back(sz(right->v));
 			}
		}

        // assuming that +1(addition operation) exits in t
        int count(int l, int r, t a, t b){ //Number of x -> a<=x<=b and x is between l and r
            if (l>r || a>b) return 0;  // extra
            int i1 = lower_bound(v.begin(), v.end(), a) - v.begin();
            int i2 = lower_bound(v.begin(), v.end(), b+1) - v.begin();
            return count_internal(l, r, i1) - count_internal(l, r, i2);
        }

		int count_internal(int l, int r, int i){ //Number of x -> a<=x and x is between l and r
			if(l>_r || r<_l) return 0;
			if(l<=_l && _r<=r)	{
                return (sz(v) - i);
            }
			return left->count_internal(l,r,lp[i])+right->count_internal(l,r,rp[i]);
		}

		// for fixing memory leaks
		void clear() {
            if (left != nullptr) {
                left->clear();
                delete left;
            }
            if (right != nullptr) {
                right->clear();
                delete right;
            }
        }
};
////////////////////////////////////////////////////////////////////////////////////////////////////////

// here
// build time :- nlogn
// query time :- logn
// space :- nlogn


/*
// IMPORTANT POINTS
1.	for sum in range (l, r) for all numbers satisfing
	a <= x <= b.
	use another array of partial sum and then for every complete
	overlap return sum of elements in that range.
2.	In Frational Cascading i have assumed that +1 exits in t
	if not then you may want to calculate for a<=x<b this kind
	of x's;
3.
*/

// ARRAY BASED IMPLEMENTATION
////////////////////////////////////////////////////////////////////////////////////////////////////////
template<typename tt>
struct MergeSortTree
{
	int len;
	vector<vector<tt>> t;
	MergeSortTree(int l){
		len = l;
		t.resize(4 * len);
	}

	template<typename T>
	void build(const T &arr,const int32_t &v, const int32_t &tl, const int32_t &tr){
        t[v].clear();
		t[v].resize(tr-tl+1);
		if(tl == tr){
            t[v][0] = arr[tl];
			return;
		}
		int32_t tm = (tl + tr) >> 1;
		build(arr,v<<1,tl,tm);
		build(arr,v<<1|1,tm+1,tr);
        merge(t[v<<1].begin(), t[v<<1].end(), t[v<<1|1].begin(), t[v<<1|1].end(), t[v].begin());
	}

	int count(const int32_t &v,const int32_t &tl,const int32_t &tr,const int32_t &l,const int32_t &r,tt ql,tt qr){
		if(l > tr || r < tl){
			return 0;
		}
		if(tl >= l && tr <= r){
			return upper_bound(t[v].begin(), t[v].end(), qr)-lower_bound(t[v].begin(), t[v].end(), ql);
		}
		int tm = (tl + tr) >> 1;
		int a = count(v<<1,tl,tm,l,r,ql,qr),b = count(v<<1|1,tm+1,tr,l,r,ql,qr);
		return (a+b);
	}
	public:
	template<typename T>
	void build(const T &arr){
		build(arr,1,0,len-1);
	}
	int count(const int32_t &l,const int32_t &r, tt ql, tt qr){
		return count(1,0,len-1,l,r,ql,qr);
	}
};
////////////////////////////////////////////////////////////////////////////////////////////////////////


// ARRAY BASED IMPLEMENTATION (with fractional cascading)
////////////////////////////////////////////////////////////////////////////////////////////////////////
template<typename tt>
struct MergeSortTree
{
	int len;
	vector<vector<tt>> t;
    vector<vector<int>> lp, rp;
	MergeSortTree(int l){
		len = l;
        t.resize(4 * len);
        lp.resize(4 * len);
		rp.resize(4 * len);
	}

	template<typename T>
	void build(const T &arr,const int32_t &v, const int32_t &tl, const int32_t &tr){
        t[v].clear();
        lp[v].clear();
        rp[v].clear();
		if(tl == tr){
            t[v].pb(arr[tl]);
			return;
		}
		int32_t tm = (tl + tr) >> 1;
		build(arr,v<<1,tl,tm);
		build(arr,v<<1|1,tm+1,tr);
        int i1=0, i2=0, p1=0, p2=0;
        debug("here")
        while (i1<sz(t[v<<1]) and i2<sz(t[v<<1|1])) {
            if (t[v<<1][i1] < t[v<<1|1][i2]) {
                t[v].push_back(t[v<<1][i1]);
                lp[v].push_back(p1);
                i1++;
                if (i1 < sz(t[v<<1])) {
                    if (t[v<<1][p1] < t[v<<1][i1]) p1 = i1;
                }
                rp[v].push_back(p2);
            }
            else if (t[v<<1|1][i2] < t[v<<1][i1]) {
                t[v].push_back(t[v<<1|1][i2]);
                rp[v].push_back(p2);
                i2++;
                if (i2 < sz(t[v<<1|1])) {
                    if (t[v<<1|1][p2] < t[v<<1|1][i2]) p2 = i2;
                }
                lp[v].push_back(p1);
            }
            else {
                t[v].push_back(t[v<<1|1][i2]);
                t[v].push_back(t[v<<1][i1]);
                lp[v].push_back(p1);
                lp[v].push_back(p1);
                i1++;
                if (i1 < sz(t[v<<1])) {
                    if (t[v<<1][p1] < t[v<<1][i1]) p1 = i1;
                }
                rp[v].push_back(p2);
                rp[v].push_back(p2);
                i2++;
                if (i2 < sz(t[v<<1|1])) {
                    if (t[v<<1|1][p2] < t[v<<1|1][i2]) p2 = i2;
                }
            }
        }

        while (i1<sz(t[v<<1])) {
            t[v].push_back(t[v<<1][i1]);
            lp[v].push_back(p1);
            i1++;
            if (i1 < sz(t[v<<1])) {
                if (t[v<<1][p1] < t[v<<1][i1]) p1 = i1;
            }
        }
        lp[v].push_back(sz(t[v<<1]));

        while(i2<sz(t[v<<1|1])) {
            t[v].push_back(t[v<<1|1][i2]);
            rp[v].push_back(p2);
            i2++;
            if (i2 < sz(t[v<<1|1])) {
                if (t[v<<1|1][p2] < t[v<<1|1][i2]) p2 = i2;
            }
        }
        rp[v].push_back(sz(t[v<<1|1]));
        while(sz(lp[v]) != sz(t[v])+1) lp[v].push_back(sz(t[v<<1]));
        while(sz(rp[v]) != sz(t[v])+1) rp[v].push_back(sz(t[v<<1|1]));
	}

	int count(const int32_t &v,const int32_t &tl,const int32_t &tr,const int32_t &l,const int32_t &r,tt qi) {
        if(l>tr || r<tl) return 0;
        if(l<=tl && tr<=r)	{
            // need to add 1
            return (sz(t[v]) - qi);
        }
        int32_t tm = (tl + tr) >> 1;
        return count(v<<1,tl,tm,l,r,lp[v][qi])+count(v<<1|1,tm+1,tr,l,r,rp[v][qi]);
	}
	public:
	template<typename T>
	void build(const T &arr){
		build(arr,1,0,len-1);
	}
	int count(const int32_t &l,const int32_t &r, tt ql, tt qr){
        if (l>r || ql>qr) return 0;
        assert(qr < qr+1);
        int i1 = lower_bound(t[1].begin(), t[1].end(), ql) - t[1].begin();
        int i2 = lower_bound(t[1].begin(), t[1].end(), qr+1) - t[1].begin();
        return count(1,0,len-1,l,r,i1) - count(1,0,len-1,l,r,i2);
	}
};
////////////////////////////////////////////////////////////////////////////////////////////////////////

// ARRAY(with just one array) BASED IMPLEMENTATION (with fractional cascading)
////////////////////////////////////////////////////////////////////////////////////////////////////////
template<typename tt>
struct MergeSortTree
{
	int len;
    vector<vector<pair<tt, pii>>> t;
	MergeSortTree(int l){
		len = l;
        t.resize(4 * len);
	}

	template<typename T>
	void build(const T &arr,const int32_t &v, const int32_t &tl, const int32_t &tr){
        t[v].clear();
		if(tl == tr){
            t[v].pb({arr[tl],{0,0}});
            t[v].pb({0,{0,0}});
			return;
		}
		int32_t tm = (tl + tr) >> 1;
		build(arr,v<<1,tl,tm);
		build(arr,v<<1|1,tm+1,tr);

        // merge
        // merge array, lp, rp
        t[v].resize(tr-tl+2);
        int i1=0, i2=0, iv=0, ilp=0, irp=0, p1=0, p2=0;
        debug("here")
        while (i1<(sz(t[v<<1])-1) and i2<(sz(t[v<<1|1])-1)) {
            if (t[v<<1][i1].fi < t[v<<1|1][i2].fi) {
                t[v][iv++].fi = t[v<<1][i1].fi;
                t[v][ilp++].sc.fi = p1;
                i1++;
                if (i1 < sz(t[v<<1])-1) {
                    if (t[v<<1][p1].fi < t[v<<1][i1].fi) p1 = i1;
                }
                t[v][irp++].sc.sc = p2;
            }
            else if (t[v<<1|1][i2].fi < t[v<<1][i1].fi) {
                t[v][iv++].fi = t[v<<1|1][i2].fi;
                t[v][irp++].sc.sc = p2;
                i2++;
                if (i2 < sz(t[v<<1|1])-1) {
                    if (t[v<<1|1][p2].fi < t[v<<1|1][i2].fi) p2 = i2;
                }
                t[v][ilp++].sc.fi = p1;
            }
            else {
                t[v][iv++].fi = t[v<<1|1][i2].fi;
                t[v][iv++].fi = t[v<<1][i1].fi;
                t[v][ilp++].sc.fi = p1;
                t[v][ilp++].sc.fi = p1;
                i1++;
                if (i1 < sz(t[v<<1])-1) {
                    if (t[v<<1][p1].fi < t[v<<1][i1].fi) p1 = i1;
                }
                t[v][irp++].sc.sc = p2;
                t[v][irp++].sc.sc = p2;
                i2++;
                if (i2 < sz(t[v<<1|1])-1) {
                    if (t[v<<1|1][p2].fi < t[v<<1|1][i2].fi) p2 = i2;
                }
            }
        }

        while (i1<sz(t[v<<1])-1) {
            t[v][iv++].fi = t[v<<1][i1].fi;
            t[v][ilp++].sc.fi = p1;
            i1++;
            if (i1 < sz(t[v<<1])-1) {
                if (t[v<<1][p1].fi < t[v<<1][i1].fi) p1 = i1;
            }
        }
        t[v][ilp++].sc.fi = sz(t[v<<1])-1;

        while(i2<sz(t[v<<1|1])-1) {
            t[v][iv++].fi = t[v<<1|1][i2].fi;
            t[v][irp++].sc.sc = p2;
            i2++;
            if (i2 < sz(t[v<<1|1])-1) {
                if (t[v<<1|1][p2].fi < t[v<<1|1][i2].fi) p2 = i2;
            }
        }
        t[v][irp++].sc.sc = sz(t[v<<1|1])-1;
        while(sz(t[v]) > ilp) t[v][ilp++].sc.fi = sz(t[v<<1])-1;
        while(sz(t[v]) > irp) t[v][irp++].sc.sc = sz(t[v<<1|1])-1;
	}

	int count(const int32_t &v,const int32_t &tl,const int32_t &tr,const int32_t &l,const int32_t &r,tt qi) {
        if(l>tr || r<tl) return 0;
        if(l<=tl && tr<=r)	{
            // need to add 1
            return (sz(t[v]) - qi-1);
        }
        int32_t tm = (tl + tr) >> 1;
        return count(v<<1,tl,tm,l,r,t[v][qi].sc.fi)+count(v<<1|1,tm+1,tr,l,r,t[v][qi].sc.sc);
	}
	public:
	template<typename T>
	void build(const T &arr){
		build(arr,1,0,len-1);
	}
	int count(const int32_t &l,const int32_t &r, tt ql, tt qr){
        if (l>r || ql>qr) return 0;
        assert(qr < qr+1);
        int i1 = lower_bound(t[1].begin(), t[1].end()-1, mp(ql,mp(0,0))) - t[1].begin();
        int i2 = lower_bound(t[1].begin(), t[1].end()-1, mp(qr+1,mp(0,0))) - t[1].begin();
        return count(1,0,len-1,l,r,i1) - count(1,0,len-1,l,r,i2);
	}
};
////////////////////////////////////////////////////////////////////////////////////////////////////////


// please refer this question
// link:- https://codeforces.com/contest/369/problem/E
