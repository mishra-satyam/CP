// better stuct version

struct fraction {
    pii val;
    fraction() {val.fi=0, val.sc=1;}
    fraction(int a) {val.fi = a, val.sc = 1;}
    fraction(int a, int b) {val.fi = a, val.sc = b;}

    void operator++ ()
    {val.fi = (0ll+val.fi+val.sc)%mod;}
    void operator-- ()
    {val.fi = (0ll+mod+val.fi-val.sc)%mod;}

    fraction operator++(int)
    {fraction before = *this;val.fi = (0ll+val.fi+val.sc)%mod;return before;}
    fraction operator--(int)
    {fraction before = *this;val.fi = (0ll+mod+val.fi-val.sc)%mod;return before;}

    // fraction to int
    void operator+=(int x)
    {val.fi = (0ll+val.fi+1ll*x*val.sc)%mod;}
    fraction operator+(int x)
    {fraction tmp;tmp.val.fi = (0ll+val.fi+1ll*x*val.sc)%mod;tmp.val.sc=val.sc;return tmp;}

    void operator-=(int x)
    {val.fi = (0ll+mod+val.fi-1ll*x*val.sc%mod)%mod;}
    fraction operator-(int x)
    {fraction tmp;tmp.val.fi = (0ll+mod+val.fi-1ll*x*val.sc)%mod;tmp.val.sc=val.sc;return tmp;}

    fraction operator*(int x)
    {fraction tmp;tmp.val.fi = (val.fi*1ll*x%mod);tmp.val.sc=val.sc;return tmp;}
    void operator*=(int x)
    {val.fi = (val.fi*x)%mod;}

    fraction operator/(int x)
    {fraction tmp;tmp.val.sc = (val.sc*1ll*x%mod);tmp.val.fi=val.fi;return tmp;}
    void operator/=(int x)
    {val.sc = (val.sc*x)%mod;}

    // fraction to fraction
    void operator+=(fraction x)
    {val.fi = (val.fi*1ll*x.val.sc + x.val.fi*1ll*val.sc)%mod;
    val.sc = val.sc*1ll*x.val.sc%mod;}
    fraction operator+(fraction x)
    {fraction tmp;tmp.val.fi = (val.fi*1ll*x.val.sc + x.val.fi*1ll*val.sc)%mod;
    tmp.val.sc = val.sc*1ll*x.val.sc%mod;return tmp;}

    void operator-=(fraction x)
    {val.fi = (val.fi*1ll*x.val.sc%mod - x.val.fi*1ll*val.sc%mod + mod)%mod;
    val.sc = val.sc*x.val.sc*1ll%mod;}
    fraction operator-(fraction x)
    {fraction tmp;tmp.val.fi = (val.fi*1ll*x.val.sc%mod - x.val.fi*1ll*val.sc%mod + mod)%mod;
    tmp.val.sc = val.sc*x.val.sc*1ll%mod;return tmp;}

    fraction operator*(fraction x)
    {fraction tmp;tmp.val.fi = (val.fi*1ll*x.val.fi%mod);
    tmp.val.sc=val.sc*1ll*x.val.sc;return tmp;}
    void operator*=(fraction x)
    {val.fi = (val.fi*1ll*x.val.fi%mod);
    val.sc=val.sc*1ll*x.val.sc;}

    fraction operator/(fraction x)
    {fraction tmp;tmp.val.fi = (val.fi*1ll*x.val.sc%mod);
    tmp.val.sc=val.sc*1ll*x.val.fi;return tmp;}
    void operator/=(fraction x)
    {val.fi = (val.fi*1ll*x.val.sc%mod);
    val.sc=val.sc*1ll*x.val.fi;}

    friend ostream& operator<<(ostream& out, fraction& f)
    {return out<<f.val.fi<<"/"<<f.val.sc<<"\n";return out;}

};

// _______________________________________________________________________________________________


template<typename T1,typename T2> pair<T1,T2> operator++ (pair<T1,T2>& a)
{a.fi = (0ll+a.fi+a.sc)%mod;return a;}
template<typename T1,typename T2> pair<T1,T2> operator-- (pair<T1,T2>& a)
{a.fi = (0ll+mod+a.fi-a.sc)%mod;return a;}
template<typename T1,typename T2> pair<T1,T2> operator+(pair<T1,T2>& a, int x)
{a.fi = (0ll+a.fi+1ll*x*a.sc)%mod;return a;}

template<typename T1,typename T2> void operator+=(pair<T1,T2>& a, int x)
{a.fi = (0ll+a.fi+1ll*x*a.sc)%mod;return ;}
template<typename T1,typename T2> pair<T1,T2> operator-(pair<T1,T2>& a, int x)
{a.fi = (0ll+a.fi+mod-(1ll*x*a.sc)%mod)%mod;return a;}
template<typename T1,typename T2> void operator-=(pair<T1,T2>& a, int x)
{a.fi = (0ll+a.fi+mod-(1ll*x*a.sc)%mod)%mod;return;}
template<typename T1,typename T2> pair<T1,T2> operator* (pair<T1,T2>& a, int x)
{a.fi = (a.fi * 1ll * x)%mod;return a;}
template<typename T1,typename T2> void operator*=(pair<T1,T2>& a, int x)
{a.fi = (a.fi * 1ll * x)%mod;return;}
template<typename T1,typename T2> pair<T1,T2> operator/ (pair<T1,T2>& a, int x)
{a.sc = (a.sc * 1ll * x)%mod;return a;}
template<typename T1,typename T2> void operator/=(pair<T1,T2>& a, int x)
{a.sc = (a.sc * 1ll * x)%mod;return;}

template<typename T1,typename T2> pair<T1,T2> operator+(pair<T1,T2>& a, pair<T1,T2>& b)
{a.fi = (1ll*a.fi*b.sc+1ll*b.fi*a.sc)%mod;a.sc=(a.sc*1ll*b.sc)%mod;return a;}
template<typename T1,typename T2> void operator+=(pair<T1,T2>& a, pair<T1,T2>& b)
{a.fi = (1ll*a.fi*b.sc+1ll*b.fi*a.sc)%mod;a.sc=(a.sc*1ll*b.sc)%mod;return;}
template<typename T1,typename T2> pair<T1,T2> operator-(pair<T1,T2>& a, pair<T1,T2>& b)
{a.fi = (mod+1ll*a.fi*b.sc-(1ll*b.fi*a.sc)%mod)%mod;a.sc=(a.sc*1ll*b.sc)%mod;return a;}
template<typename T1,typename T2> void operator-=(pair<T1,T2>& a, pair<T1,T2>& b)
{a.fi = (mod+1ll*a.fi*b.sc-(1ll*b.fi*a.sc)%mod)%mod;a.sc=(a.sc*1ll*b.sc)%mod;return ;}
template<typename T1,typename T2> pair<T1,T2> operator* (pair<T1,T2>& a, pair<T1,T2>& b)
{a.fi = (a.fi*1ll*b.fi)%mod;a.sc = (a.sc*1ll*b.sc)%mod;return a;}
template<typename T1,typename T2> void operator*=(pair<T1,T2>& a, pair<T1,T2>& b)
{a.fi = (a.fi*1ll*b.fi)%mod;a.sc = (a.sc*1ll*b.sc)%mod;return ;}
// template<typename T1,typename T2> pair<T1,T2> operator/ (pair<T1,T2>& a, int x)
// {a.sc = (a.sc * 1ll * x)%mod;return a;}
// template<typename T1,typename T2> void operator/=(pair<T1,T2>& a, int x)
// {a.sc = (a.sc * 1ll * x)%mod;return;}
