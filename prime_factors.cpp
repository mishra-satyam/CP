vi facs;
void primeFactors(int n)
{
    facs.clear();
    while (n % 2 == 0)
    {
        facs.pb(2);
        n = n/2;
    }

    for (int i = 3; i*i <= n; i = i + 2)
    {
        while (n % i == 0)
        {
            facs.pb(i);
            n = n/i;
        }
    }

    if (n > 2)
    facs.pb(n);
}

// if it is a prime then O(sqrt(n))
// O( log(n) )

//////////////////////////////////////////////////////////////////////////////////////////
int primes[N];
vector<int> pr;
vector<int> fac[N];
void sieve(){
	for(int i=2;i<N;i++){
		if(primes[i]==0){
			pr.pb(i);
			for(int j=i;j<N;j+=i){
				if (j!=i) primes[j]=1;
				fac[j].pb(i);
			}
		}
		primes[i]^=1;
	}
}
//////////////////////////////////////////////////////////////////////////////////////////
// O(nlog(logn))
// only single occurance of all prime numbers

// prime test
ll sq(ll x){
    ll k = sqrtl(x);
    while(k*k < x) k++;
    while(k*k > x) k--;
    return k;
}

bool isprime(ll x) {
    FOR(i,2,sq(x)+1) {
        if (x%i == 0) return 0;
    }
    return 1;
}
