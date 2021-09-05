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
