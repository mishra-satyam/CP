const int N = 1e5 + 5;

int t[4*N];

void update(int v, int tl, int tr, int id, int val){
    // exact spot to be updated
    if (tl==id && tr==id){
        t[v] = val;
        return;
    }
    // point is outside the node range
    if (id>tr || id<tl){
        return;
    }
    // it is inside this range
    int tm = (tl+tr)/2;
    update(2*v,tl,tm,id,val);
    update(2*v+1,tm,tr,id,val);
    t[v] = t[2*v] + t[2*v+1];
}

void query(int v, int tl, int tr, int l, int r){
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
    int tm = (tl+tr)/2;
    int ans = 0;
    ans += query(2*v,tl,tm,l,r);
    ans += query(2*v+1,tm+1,tr,l,r);
    return ans;
}
