const int N = 1e5 + 5;

int t[4*N];
bool lazy[4*N];
int upd[4*N];

// stores the value in current node and remember it and terminates
void apply(int v, int tl, int tr, int val){
    t[v] += val*(tr-tl+1);  // 1
    if (tl!=tr){
        lazy[v] = 1;
        upd[v] += val;  // 2
    }
}

// pushes the value to a level down and terminates
void pushdown(int v, int t1, int tr){
    if (lazy[v]){
        lazy[v] = 0;
        int tm = (tl+tr)/2;
        apply(2*v,tl,tm,upd[v]);
        apply(2*v+1,tm+1,tr,upd[v]);
        upd[v] = 0;
    }
}

// main update function
// terminates at total overlap
void update(int v, int tl, int tr, int l, int r, int val){
    // no overlap
    if (tl > r || tr < l){
        return;
    }
    // complete overlap
    if (l<=tl && tr<=r){
        // ask to remember
        apply(v,tl,tr,val);
        return;
    }
    // partial overlap
    pushdown(v, tl, tr);

    // it is inside this range
    int tm = (tl+tr)/2;
    update(2*v,tl,tm,l,r,val);
    update(2*v+1,tm+1,tr,l,r,val);
    t[v] = t[2*v] + t[2*v+1];   // 3
}

int query(int v, int tl, int tr, int l, int r){
    // no overlap
    if (tl > r || tr < l){
        return 0;
    }
    // complete overlap
    if (l<=tl && tr<=r){
        // l...t1.....tr.....r
        return t[v];
    }

    // partial overlap
    // so here we need to make this node free

    pushdown(v,t1,tr);

    int tm = (tl+tr)/2;
    int ans = 0;    // 4
    ans += query(2*v,tl,tm,l,r);
    ans += query(2*v+1,tm+1,tr,l,r);
    return ans;
}

// associative property required  ( a*(b*c)  ==  (a*b)*c  )
// dont forget the initialisation of leaf nodes
// always call for tl = 0 and tr = N-1
// level = logN
// query => logN (2 important nodes per level(side ones'))
// update => logN (as this code is isomorphic to query)
